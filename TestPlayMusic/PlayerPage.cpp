#include "PlayerPage.h"
#include "ListPage.h"

using namespace std;

char* progressBarStr = (char*)malloc(sizeof(char) * 51);

void mediaPlayerPage()
{
#ifdef DEBUG
	appendNode(g_headPtr, "C:\\Users\\Cybercalf\\Music\\_menuLoop.mp3");
#endif

	// 结束程序的标志
	int exit = 0;
	char szTimeBuffer[1024];
	char szModeBuffer[1024];
	char szCommandBuffer[1024];

	// const char* debugStr;

	while (exit == 0)
	{
		while (!_kbhit())
		{
			showMediaPlayerMenu();
			Sleep(200);
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
	int musicCurrentPosition = getMusicCurrentPosition();
	int musicLength = getMusicLength();
	printf("%d  %50s  %d\n",
	       musicCurrentPosition,
	       progressBar(musicCurrentPosition, musicLength),
	       musicLength);
}

const char* progressBar(int nowTime, int musicTime)
{
	for (int i = 0; i < 50; i++)
	{
		progressBarStr[i] = '-';
	}
	progressBarStr[50] = '\0';

	int percentage; // 播放进度百分比
	if (musicTime == 0) // 如果总时长为0
	{
		percentage = 0;
	}
	else // 如果总时长不为0
	{
		percentage = 50 * nowTime / musicTime;
	}

	for (int i = 0; i < percentage; i++)progressBarStr[i] = '*';

	return (const char*)progressBarStr;
}
