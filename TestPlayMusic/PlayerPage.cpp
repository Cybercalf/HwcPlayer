#include "PlayerPage.h"
#include "ListPage.h"

using namespace std;

char progressBarStr[50];
char totalBarStr[100];

void mediaPlayerPage()
{
	// 结束程序的标志
	int exit = 0;
	char szTimeBuffer[1024];
	char szModeBuffer[1024];
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
			int number;
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
		case 'o':
			StringCchPrintf(szCommandBuffer, sizeof(szCommandBuffer) - 1, "seek BackMusic to %s", szTimeBuffer);
			MymciSendString(szCommandBuffer, NULL);
			break;

		case 'p':
			MymciSendString("status BackMusic mode", szModeBuffer);
			printf("%s", szModeBuffer);
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
	puts("播放界面\n"
		"1. open music\n"
		"2. close music\n"
		"3. play music\n"
		"4. play music repeat\n"
		"5. stop music\n"
		"6. pause music\n"
		"7. resume music\n"
		"i. status music position\n"
		"o. seek music\n"
		"p. status music mode\n"
		"0. exit\n"
	);
	printProcessBar(getMusicCurrentPosition(), getMusicLength());
}

void printProcessBar(int nowTime, int musicTime)
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
	printf("%s\n", totalBarStr);
}
