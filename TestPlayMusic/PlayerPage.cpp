#include "PlayerPage.h"
#include "ListPage.h"

using namespace std;

char progressBarStr[50];
char totalBarStr[100];
char szStatusBuffer[1024];
char szPlayModeBuffer[1024];
char szMediaNameBuffer[1024];
char szMediaSpeedBuffer[10];

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
			if (status == STATUS_STOPPED &&
				getMusicCurrentPosition() == getMusicLength())
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
			switch_play_status();
			break;
		case '3':
			printList(g_headPtr);
			printf("%s\n", "请输入你想跳转的音乐编号：");
			scanf("%u", &number);
			CLEAR_BUF
			if (number >= 1 && number <= getLength(g_headPtr))
			{
				closeMusic();
				openMusic(getNodePathByNumber(g_headPtr, number));
				playMusic();
			}
			else
			{
				puts("打开失败，请检查编号填写是否正确");
				system("pause");
			}
			break;
		case 'j':
		case 'J':
			playMusicUp();
			break;
		case 'k':
		case 'K':
			playMusicDown();
			break;
		case 'u':
		case 'U':
			stepBackward10Sec();
			break;
		case 'i':
		case 'I':
			stepForward10Sec();
			break;
		case 'o':
		case 'O':
			switchMusicSpeed();
			break;
		case 'q':
		case 'Q':
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
	loadMediaSpeed();
	puts(
		"\n\n\n"
		"\t\t    * * * * * * * *                   * * * * * * * *\n"
		"\t\t    * * * * * *         音    乐          * * * * * *\n"
		"\t\t    * * * * * * * *                   * * * * * * * *\n"
		"\n\n\n");
	printf("\t\t    正在播放：%s\n", szMediaNameBuffer);
	printf("\t\t    播放状态：%s\n", szStatusBuffer);
	printf("\t\t    播放模式：%s\n", szPlayModeBuffer);
	printf("\t\t    播放速度：%s\n", szMediaSpeedBuffer);
	printf("\t\t%s\n"
	       "\t\t              - 1 -  播放/暂停\n"
	       "\t\t              - 2 -  切换播放模式\n"
	       "\t\t              - 3 -  跳转到\n"
	       "\t\t              - J -  上一曲\n"
	       "\t\t              - K -  下一曲\n"
	       "\t\t              - U -  快退10秒\n"
	       "\t\t              - I -  快进10秒\n"
	       "\t\t              - O -  调整倍速\n"
	       "\t\t              - Q -  返回主菜单\n"
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
	else if (strcmp(szStatusBuffer, "playing") == 0) status = STATUS_PLAY;
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
	case STATUS_PLAY_RANDOM:
		sprintf(szPlayModeBuffer, "%s", "随机播放");
		break;
	default:
		break;
	}
}

void loadMediaName()
{
	sprintf(szMediaNameBuffer, "%s", getMediaNameByNumber(g_headPtr, number));
}

void loadMediaSpeed()
{
	sprintf(szMediaSpeedBuffer, "X %.1f", getMusicSpeed() * 1.0 / 1000);
}

void switch_play_status()
{
	switch (play_status)
	{
	case STATUS_PLAY_SEQUENCE:
		play_status = STATUS_PLAY_REPEAT;
		break;
	case STATUS_PLAY_REPEAT:
		play_status = STATUS_PLAY_RANDOM;
		break;
	case STATUS_PLAY_RANDOM:
		play_status = STATUS_PLAY_SEQUENCE;
		break;
	}
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
	switch (play_status)
	{
	case STATUS_PLAY_SEQUENCE:
		number += 1;
		if (number > getLength(g_headPtr)) number = 1;
		break;
	case STATUS_PLAY_REPEAT:
		break;
	case STATUS_PLAY_RANDOM:
		srand(time(0));
		number = rand() % getLength(g_headPtr) + 1;
		break;
	}
	if (openMusic(getNodePathByNumber(g_headPtr, number)) == 0) playMusic();
	return;
}

void stepForward10Sec()
{
	int jumpTime = getMusicCurrentPosition() + 10000;
	if (jumpTime > getMusicLength()) jumpTime = getMusicLength();
	seekToPosition(jumpTime);
	playMusic();
}

void stepBackward10Sec()
{
	int jumpTime = getMusicCurrentPosition() - 10000;
	if (jumpTime < 0) jumpTime = 0;
	seekToPosition(jumpTime);
	playMusic();
}

void switchMusicSpeed()
{
	switch (getMusicSpeed())
	{
	case 1000:
		setMusicSpeed(1250);
		break;
	case 1500:
		setMusicSpeed(800);
		break;
	case 800:
		setMusicSpeed(1000);
		break;
	default:
		break;
	}
}
