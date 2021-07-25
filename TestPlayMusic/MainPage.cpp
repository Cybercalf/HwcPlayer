#include "MainPage.h"
#include "ListPage.h"
using namespace std;

void mainMenuPage()
{
	bool running = true;
	while (running)
	{
		while (!_kbhit())
		{
			showMainMenuPage();
			Sleep(200);
		}
		switch (_getch())
		{
		case 'E':
		case 'e':
			puts("程序退出，再见");
			running = !running;
			system("pause");
			
			break;
		case 'L':
		case 'l':
			listPage();
			break;
		case 'P':
		case 'p':
			mediaPlayerPage();
			break;
		default:
			break;
		}
	}
}

void showMainMenuPage()
{
	system("cls");
	printf("\t\t\t************************\t\t\t\n"
	       "\t\t\t***********欢迎**********\t\t\t\n"
	       "\t\t\t北京时间：%d时%d分%d秒\n",
	       getCurrentHour(), getCurrentMinute(), getCurrentSecond());
	puts("\n\n\n"
		"\t\t\t[L] 播放列表\n"
		"\t\t\t[P] 播放界面\n"
		"\t\t\t[E] 退出\n");
}
