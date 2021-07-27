#include "PlayerPage.h"
#include "ListPage.h"

using namespace std;

enum PLAY_STATUS
{
	STATUS_PLAY_SEQUENCE = 0,
	STATUS_PLAY_REPEAT,
};

char progressBarStr[50];
char totalBarStr[100];
char szModeBuffer[1024];
char szPlayModeBuffer[1024];

enum PLAY_STATUS play_status = STATUS_PLAY_SEQUENCE;

void mediaPlayerPage()
{
	// 结束程序的标志
	int exit = 0;
	char szTimeBuffer[1024];
	int number;
	char szCommandBuffer[1024];

	while (exit == 0)
	{
		while (!_kbhit())
		{
			showMediaPlayerMenu();
			Sleep(1000);
		}

		switch (_getch())
		{
		case '1':
			printf("input number: ");
			scanf("%d", &number);
			CLEAR_BUF
			openMusic(getNodePathByNumber(g_headPtr, number));
			break;

		case '2':
			closeMusic();
			break;

		case '3':
			playMusic();
			break;

		case '4':
			playMusicRepeat();
			break;

		case '5':
			stopMusic();
			break;

		case '6':
			pauseMusic();
			break;

		case '7':
			resumeMusic();
			break;
			// case 'o':
			// 	StringCchPrintf(szCommandBuffer, sizeof(szCommandBuffer) - 1, "seek BackMusic to %s", szTimeBuffer);
			// 	MymciSendString(szCommandBuffer, NULL);
			// 	break;

		case 'j':
			closeMusic();
			number -= 1;
			if (number <= 0) number = getLength(g_headPtr);
			if (openMusic(getNodePathByNumber(g_headPtr, number)) == 0) playMusic();
			break;
		case 'k':
			closeMusic();
			number += 1;
			if (number > getLength(g_headPtr)) number = 1;
			if (openMusic(getNodePathByNumber(g_headPtr, number)) == 0) playMusic();
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

	puts(
		"\n\n\n"
		"\t\t    * * * * * * * *                   * * * * * * * *\n"
		"\t\t    * * * * * *         音    乐          * * * * * *\n"
		"\t\t    * * * * * * * *                   * * * * * * * *\n"
		"\n\n\n");
	printf("\t\t    播放状态：%s\n", szModeBuffer);
	printf("\t\t    播放模式：%s\n", szPlayModeBuffer);
	printf("\t\t%s\n"
	       "\t\t              - 1 -  打开音乐      - 2 -  关闭音乐\n"
	       "\t\t              - 3 -  播放音乐      - 4 -  切换播放模式\n"
	       "\t\t              - 5 -  停止          - 6 -  暂停\n"
	       "\t\t              - 7 -  继续          - 0 -  退出\n"
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
	MymciSendString("status BackMusic mode", szModeBuffer);
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
