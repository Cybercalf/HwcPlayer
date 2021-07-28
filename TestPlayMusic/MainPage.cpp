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
	// printf(
	// 	"\n\n\n\n"
	// 	"\t\t    * * * * * * * * * *           * * * * * * * * * *\n"
	// 	"\t\t    * * * * * * * *                   * * * * * * * *\n"
	// 	"\t\t    * * * * * *    H W C 音 乐 播 放 器   * * * * * *\n"
	// 	"\t\t    * * * * * * * *                   * * * * * * * *\n"
	// 	"\t\t    * * * * * * * * * *           * * * * * * * * * *\n"
	// 	"\n\n\n"
	// 	"\t\t                        -北京时间-\n"
	// 	"\t\t                   -%4d年%2d 月 %2d 日-\n"
	// 	"\t\t                   -%2d 点 %2d 分 %2d 秒-\n"
	// 	"\t\t                      -L-   音乐列表\n"
	// 	"\t\t                      -P-   播放界面\n"
	// 	"\t\t                      -V-   音量界面\n"
	// 	"\t\t                      -E-     退出\n"
	// 	, getCurrentYear(), getCurrentMonth(), getCurrentDay(),
	// 	getCurrentHour(), getCurrentMinute(), getCurrentSecond());
	printf(
		"\n\n\n\n"
		"            * * * * *___ ___               __________.__                          * * * * *\n"
		"          * * * * * /   |   \\__  _  __ ____\\______   \\  | _____  ___.__. ___________* * * * *\n"
		"        * * * * *  /    -    \\ \\/ \\/ // ___\\|     ___/  | \\__  \\<   |  |/ __  \\_  __ \\* * * * *\n"
		"        * * * * *  \\    T    /\\     /\\  \\___|    |   |  |__/ __ \\\\___  \\   ___/|  | \\/* * * * *\n"
		"          * * * * * \\___|_  /  \\/\\_/  \\___  >____|   |____(____  / ____| \\___  >__| * * * * *\n"
		"            * * * * *     \\/              \\/                   \\/\\/          \\/ * * * * *\n"
		"\n\n\n"
		"\t\t\t                        -北京时间-\n"
		"\t\t\t                   -%4d年 %2d 月 %2d 日-\n"
		"\t\t\t                   -%3d 点 %2d 分 %2d 秒-\n\n"
		"\t\t\t                      -L-   音乐列表\n"
		"\t\t\t                      -P-   播放界面\n"
		"\t\t\t                      -E-     退出\n"
		, getCurrentYear(), getCurrentMonth(), getCurrentDay(),
		getCurrentHour(), getCurrentMinute(), getCurrentSecond());
}
