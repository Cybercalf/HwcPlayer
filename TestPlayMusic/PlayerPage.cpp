#include "PlayerPage.h"
#include "ListPage.h"

using namespace std;

enum PLAY_STATUS
{
	STATUS_PLAY_SEQUENCE = 0,
	STATUS_PLAY_REPEAT,
};

enum STATUS
{
	STATUS_PLAY = 0,
	STATUS_PAUSE,
	STATUS_STOPPED,
};

char progressBarStr[50];
char totalBarStr[100];
char szStatusBuffer[1024];
char szPlayModeBuffer[1024];
char szMediaNameBuffer[1024];

unsigned int number = 1;

enum PLAY_STATUS play_status = STATUS_PLAY_SEQUENCE;
enum STATUS status = STATUS_STOPPED;

void mediaPlayerPage()
{
	// 结束程序的标志
	int exit = 0;
	openMusic(getNodePathByNumber(g_headPtr, number));
	// char szTimeBuffer[1024];

	// char szCommandBuffer[1024];

	while (exit == 0)
	{
		while (!_kbhit())
		{
			showMediaPlayerMenu();
			if (status == STATUS_STOPPED && play_status == STATUS_PLAY_SEQUENCE && getMusicCurrentPosition() ==
				getMusicLength())
			{
				playMusicDown();
			}
			Sleep(1000);
		}

		switch (_getch())
		{
		case '1':
			if (status == STATUS_STOPPED)
			{
				playMusic();
				status = STATUS_PLAY;
			}
			else if (status == STATUS_PLAY)
			{
				pauseMusic();
				status = STATUS_PAUSE;
			}
			else if (status == STATUS_PAUSE)
			{
				resumeMusic();
				status = STATUS_PLAY;
			}
			break;

		case '2':
			if (play_status == STATUS_PLAY_SEQUENCE)
			{
				playMusicRepeat();
				play_status = STATUS_PLAY_REPEAT;
			}
			else if (play_status == STATUS_PLAY_REPEAT)
			{
				playMusic();
				play_status = STATUS_PLAY_SEQUENCE;
			}
			break;

			// case 'o':
			// 	StringCchPrintf(szCommandBuffer, sizeof(szCommandBuffer) - 1, "seek BackMusic to %s", szTimeBuffer);
			// 	MymciSendString(szCommandBuffer, NULL);
			// 	break;

		case 'j':
			playMusicUp();
			break;
		case 'k':
			playMusicDown();
			break;
		case '0':
			exit = 1;
			break;

		default:
			break;
		}
	}
}

// 显示命令
void showMediaPlayerMenu()
{
	system("cls");
	loadProcessBar(getMusicCurrentPosition(), getMusicLength());
	loadStatus();
	loadPlayStatus();
	loadMediaName();
	puts(
		"\n\n\n"
		"\t\t    * * * * * * * *                   * * * * * * * *\n"
		"\t\t    * * * * * *         音    乐          * * * * * *\n"
		"\t\t    * * * * * * * *                   * * * * * * * *\n"
		"\n\n\n");
	printf("\t\t    正在播放：%s\n", szMediaNameBuffer);
	printf("\t\t    播放状态：%s\n", szStatusBuffer);
	printf("\t\t    播放模式：%s\n", szPlayModeBuffer);
	printf("\t\t%s\n"
	       "\t\t              - 1 -  播放/暂停\n"
	       "\t\t              - 2 -  切换播放模式\n"
	       "\t\t              - J -  上一曲\n"
	       "\t\t              - K -  下一曲\n"
	       "\t\t              - 0 -  返回主菜单\n"
	       "\n"
	       , totalBarStr);
}


void loadProcessBar(int nowTime, int musicTime)
{
	int pos;
	pos = sprintf(totalBarStr,
	              "%02d:%02d ",
	              nowTime / 60000 % 100,
	              nowTime / 1000 % 60
	);
	if (musicTime == 0)
	{
		for (int i = 0; i < 50; i++)
		{
			pos += sprintf(totalBarStr + pos, "%c", '-');
		}
	}
	else
	{
		int percentage = 50 * nowTime / musicTime;
		for (int i = 0; i < percentage; i++)
		{
			pos += sprintf(totalBarStr + pos, "%c", '*');
		}
		for (int i = percentage; i < 50; i++)
		{
			pos += sprintf(totalBarStr + pos, "%c", '-');
		}
	}
	pos += sprintf(totalBarStr + pos,
	               " %02d:%02d",
	               musicTime / 60000 % 100,
	               musicTime / 1000 % 60);
}

void loadStatus()
{
	MymciSendString("status BackMusic mode", szStatusBuffer);
	if (strcmp(szStatusBuffer, "paused") == 0) status = STATUS_PAUSE;
	else if (strcmp(szStatusBuffer, "stopped") == 0) status = STATUS_STOPPED;
	else if (strcmp(szStatusBuffer, "playing") == 0)  status = STATUS_PLAY;
}

void loadPlayStatus()
{
	switch (play_status)
	{
	case STATUS_PLAY_SEQUENCE:
		sprintf(szPlayModeBuffer, "%s", "列表循环");
		break;
	case STATUS_PLAY_REPEAT:
		sprintf(szPlayModeBuffer, "%s", "单曲循环");
		break;
	default:
		break;
	}
}

void loadMediaName()
{
	sprintf(szMediaNameBuffer, "%s", getMediaNameByNumber(g_headPtr, number));
}

void playMusicUp()
{
	closeMusic();
	number -= 1;
	if (number <= 0) number = getLength(g_headPtr);
	if (openMusic(getNodePathByNumber(g_headPtr, number)) == 0) playMusic();
	return;
}

void playMusicDown()
{
	closeMusic();
	number += 1;
	if (number > getLength(g_headPtr)) number = 1;
	if (openMusic(getNodePathByNumber(g_headPtr, number)) == 0) playMusic();
}
