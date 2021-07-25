#include "PlayerPage.h"
#include "ListPage.h"


using namespace std;

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
		showMediaPlayerMenu();
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

		case 'i':
			MymciSendString("status BackMusic position", szTimeBuffer);
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
}
