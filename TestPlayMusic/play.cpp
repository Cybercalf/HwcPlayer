#include <cstdio>
#include <Windows.h>
#include <mmsystem.h>
#include <strsafe.h>

#pragma comment (lib,"winmm.lib")

#define CLEAR_BUF \
    {\
    int ch; \
while ((ch = getchar()) != EOF && ch != '\n')\
        {\
        ; \
        }\
    }

// 显示命令
void ShowOrder()
{
	system("cls");
	printf("mciSendString order:\n");
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

void MymciSendString(const char* szCommand, char* szbuffer)
{
	if (NULL == szbuffer)
	{
		if (0 != mciSendString(szCommand, NULL, 0, NULL))
		{
			printf("%s false!\n", szCommand);
		}
		else
		{
			printf("%s success!\n", szCommand);
		}
	}
	else
	{
		if (0 != mciSendString(szCommand, szbuffer, 1024, NULL))
		{
			printf("%s false!\n", szCommand);
		}
		else
		{
			printf("%s success!\n", szCommand);
		}
	}
}

int main(void)
{
	int icommand = -1;
	int bflag = 1;
	char szTimeBuffer[1024];
	char szModeBuffer[1024];
	char szCommandBuffer[1024];

	while (bflag)
	{
		ShowOrder();
		scanf_s("%d", &icommand);
		// 方法1
		//fflush(stdout);
		// 方法2
		CLEAR_BUF
			switch (icommand)
			{
			case 1:
				MymciSendString("open C:\\Users\\Cybercalf\\Music\\_StayInsideMe.mp3 alias BackMusic", NULL);
				break;
				
			case 2:
				MymciSendString("close BackMusic", NULL);
				break;

			case 3:
				MymciSendString("play BackMusic", NULL);
				break;

			case 33:
				MymciSendString("play BackMusic repeat", NULL);
				break;

			case 4:
				MymciSendString("stop BackMusic", NULL);
				break;

			case 5:
				MymciSendString("pause BackMusic", NULL);
				break;

			case 6:
				MymciSendString("resume BackMusic", NULL);
				break;

			case 7:
				MymciSendString("status BackMusic position", szTimeBuffer);
				break;

			case 8:
				StringCchPrintf(szCommandBuffer, sizeof(szCommandBuffer) - 1, "seek BackMusic to %s", szTimeBuffer);
				MymciSendString(szCommandBuffer, NULL);
				break;

			case 9:
				MymciSendString("status BackMusic mode", szModeBuffer);
				printf("%s", szModeBuffer);
				break;

			case 0:
				bflag = 0;
				break;

			default:
				printf("Input error!Please enter again.");
				break;
			}

		printf("\n");
		system("pause");
	}
}