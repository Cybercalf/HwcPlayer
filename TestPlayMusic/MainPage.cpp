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
			Sleep(1000);
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
	printf("\n\n\n\n"
	       "\t\t***************************************\t\t\n"
	       "\t\t***************************************\t\t\n"
	       "\t\t*************  HwcPlayer  *************\t\t\n"
	       "\t\t***************************************\t\t\n"
	       "\t\t***************************************\t\t\n"
	       "\t\t**********  %d年 %d月 %d日   *********\t\t\n"
	       "\t\t**********  %d时 %d分 %d秒  ***********\t\t\n"
	       "\t\t***********  [L] 音乐列表  ************\t\t\n"
	       "\t\t***********  [P] 播放界面  ************\t\t\n"
	       "\t\t***********  [E] 退出      ************\t\t\n",
	       getCurrentYear(), getCurrentMonth(), getCurrentDay(),
	       getCurrentHour(), getCurrentMinute(), getCurrentSecond());
}
