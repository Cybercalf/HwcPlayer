#include "PlayerPage.h"


using namespace std;

void mediaPlayerPage()
{
	int icommand = -1;
	// 结束程序的标志
	int bflag = 1;
	char szTimeBuffer[1024];
	char szModeBuffer[1024];
	char szCommandBuffer[1024];

	while (bflag)
	{
		showMediaPlayerMenu();
		// scanf_s("%d", &icommand);
		// CLEAR_BUF
		switch (_getch())
		{
		case '1':
			MymciSendString(
				"open C:\\Users\\Cybercalf\\Music\\WorldChase-OST.mp3 alias BackMusic",
				NULL);
			break;

		case '2':
			MymciSendString("close BackMusic", NULL);
			break;

		case '3':
			MymciSendString("play BackMusic", NULL);
			break;

		case 33:
			MymciSendString("play BackMusic repeat", NULL);
			break;

		case '4':
			MymciSendString("stop BackMusic", NULL);
			break;

		case '5':
			MymciSendString("pause BackMusic", NULL);
			break;

		case '6':
			MymciSendString("resume BackMusic", NULL);
			break;

		case '7':
			MymciSendString("status BackMusic position", szTimeBuffer);
			break;

		case '8':
			StringCchPrintf(szCommandBuffer, sizeof(szCommandBuffer) - 1, "seek BackMusic to %s", szTimeBuffer);
			MymciSendString(szCommandBuffer, NULL);
			break;

		case '9':
			MymciSendString("status BackMusic mode", szModeBuffer);
			printf("%s", szModeBuffer);
			break;

		case '0':
			bflag = 0;
			break;

		default:
			break;
		}

		printf("\n");
		system("pause");
	}
}

// 显示命令
void showMediaPlayerMenu()
{
	system("cls");
	printf("1.open music\n");
	printf("2.close music\n");
	printf("3.play music\n");
	printf("33.play music repeat\n");
	printf("4.stop music\n");
	printf("5.pause music\n");
	printf("6.resume music\n");
	printf("7.status music position\n");
	printf("8.seek to position\n");
	printf("9.view playback status\n");

	printf("0.out\n");
	printf("Enter Your Choice:\n");
}
