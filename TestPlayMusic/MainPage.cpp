#include "MainPage.h"
#include "ListPage.h"
using namespace std;

void mainPage()
{
	bool running = true;
	while (running)
	{
		while (!_kbhit())
		{
			showMainPage();
			Sleep(800);
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
			playerPage();
			break;
		case 'a':
		case 'A':
			showAboutPage();
			break;
		default:
			break;
		}
	}
}

void showMainPage()
{
	system("cls");
	printf(
		"\n\n\n\n"
		"            * * * * *___ ___               __________.__                          * * * * *\n"
		"          * * * * * /   |   \\__  _  __ ____\\______   \\  | _____  ___.__. ___________* * * * *\n"
		"        * * * * *  /    -    \\ \\/ \\/ // ___\\|     ___/  | \\__  \\<   |  |/ __  \\_  __ \\* * * * *\n"
		"        * * * * *  \\    T    /\\     /\\  \\___|    |   |  |__/ __ \\\\___  \\   ___/|  | \\/* * * * *\n"
		"          * * * * * \\___|_  /  \\/\\_/  \\___  >____|   |____(____  / ____| \\___  >__| * * * * *\n"
		"            * * * * *     \\/              \\/                   \\/\\/          \\/ * * * * *\n"
		"\n\n"
		"\t\t\t                       - 北京时间 -\n\n"
		"\t\t\t                  - %-4d年 %-2d 月 %-2d 日 -\n"
		"\t\t\t                  - %-4d点 %-2d 分 %-2d 秒 -\n\n"
		"\t\t\t                      [L]   音乐列表\n\n"
		"\t\t\t                      [P]   播放器界面\n\n"
		"\t\t\t                      [A]   关于\n\n"
		"\t\t\t                      [E]   退出\n\n"
		, getCurrentYear(), getCurrentMonth(), getCurrentDay(),
		getCurrentHour(), getCurrentMinute(), getCurrentSecond());
}

void showAboutPage()
{
	system("cls");
	puts("@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOO/[[[[[OOOOOOOOOOOOOOOOOOOOOOOOOOO@@OO@@@@@@@@@@@@@@@@@@@@@@@\n"
		"@@@@@@@@@@@@@@@@@@@@OOOOOOOO/[.                              ,[OOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@\n"
		"@@@@@@@@@@@@@@@OOOOOOO/[       .]]OOOOOOOOOOOOOOOOOOOOOOOOOOO]].    .[[OOOOOOOOO@OO@@@@@@@@@@@@@@@@\n"
		"@@@@@@@@@@@@O@OOOOO[      ,/OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@OOOOOOOOOOOO]`..[[OOOOOOO@@@@@@@@@@@@@@@\n"
		"@@@@@@@@OOOOOOO/`    ,]OOOOOOOOOOOOOO[[[[`......    .......[[[OOOOOOOOOOOOOO].  ,OOOOOOO@@@@@@@@@@@\n"
		"@@@@OOOOOOO/`    ,OOOOOOOOO/`                                        ,[\\OOOOOOOO`  ,\\OOO@@@@@@@@@@@\n"
		"@@OOOOOO`..]OOOOOOOOO[`             ]/OOOOOOOO].                        .\\ OOOOOOOO\\] /OOO@@@@@@@@@\n"
		"@@OOOO]]/O@OOOOOOO[.      .].      ,OOOOOOOOOOOOOOO]       ,OO]].           .\\OOO0OO@OOO@@@O@@@@@@@\n"
		"@@@@OOOOOOOOOOO[         ,OO`        =OOOO@@@@@@@@@@@OOO`     \\OOOOO]           .\\OOOOOO@@OOO@@@OOO\n"
		"@@@@O@@@OOOO[         ./OO.        .OOOO@OOOOOO@@@@OOOO\\       ,OOOOOOO\\.           [OOOOOOOOOOOOOO\n"
		"OOOOOOOOO`           =OOO.            ,OOOOOOOOOO@@@@OOOO ^      ,OOOO@OOOO\\.           .[[[[[[` .O\n"
		"@OOOO/`    ,]/`     /OOO.                 ,[[OOOOOOOOOOOO ^       =OOO@@OOOOOO`                 ,OO\n"
		"OOO`.]/OOOOO   /  .OOOO/   ....*          ,]]    ,\\OOOOOO/         =OO@@@@@OOOOO`            ./OOOO\n"
		"OOOOOOOOOO ^ /O. ,OOOOO` .]=OOO..       OOOOO ^    .[OO/.          =OO@@@@@@@@OOOO`       ,/OOOO@OO\n"
		"@@@@OOOO/  ,OO   ,OOOOOO =OOOOOO.       ,OOOO`      ,]]/OOO\\      = OO@@@@@@@@OOOOOO`  .]/OOOO@@@@@@\n"
		"@@@@OOOO`/OO/  /OOOOOOO  \\OOOOOOO.                 oOOOOOOOO      =OO@@@@@@@@OOOOOOOOOOOOOO@O@@@@@@@\n"
		"@@@@OOOOOOO` .OOOOOOOOO. =OOO@OOO.              .OOOO@@@OO^      /OO@@@@@@@@@@@@@@@@OOOO@@@@@@@@@@@\n"
		"@@@@OOOOO` ./OOO@@@@OOO` .OOOOOOO\\              ,OOOOO@@@OO^    .OOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
		"@@@@OOO`  ,OOOOOO@@@@OOOO   =OOOOOOO`         /OO@@@@OOOOO`     /OOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
		"@@@@OOOOOOOOOO@@@@@@O@OOO   =OOOOO..OOOO.    ,/OOOOO@@OOOOO`  ,OOOOO@@@@OOOOOO@@@@@@@@@@@@@@@@@@@@@\n"
		"@@@@@@@@@@@@OOOOOOOOOOOOOO` ,OOOO` \\OO/ .OOOOOOO@O@@OOOOOOO  /OOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@\n"
		"@@@@@@@@@@@@OOOOOOOOOOOOOOOO. ,OOOO`  ./OOOOO@@O@@OOOOOOO`  ,OOOOOOOOO[.    [[OOOOOOOOOO@@@@@@@@@@@\n"
		"@@@@@@@@@OOOOOO`        ..[[OO` [OOOOOOOOOOOOOOOOOOO[[   =OOOO[[.                    /OO@@@@@@@@@@@\n"
		"@@@@@@@@O@OO`      ..                ,[[[[[[[[[[.                        ..]]]]]OOOOOOOO@@@@@@@@@@@\n"
		"@@@@@@@@@@@@OOOOOOOOOOOOOOOOOO\\]]`.                                      \\OOOOOO@@@@@@@@@@@@@@@@@@@\n");

	puts("\n\n\t制作人员：\n\n"
		"\t胡未名(https://github.com/Cybercalf)\n\n"
		"\t王澳(https://github.com/SCU-SE2020-WangAo)\n\n"
		"\t陈怡君(https://github.com/dobole)\n\n"
		"\t这是三人一起完成的小项目，缺少任何人，这个小程序都不会像现在一样完整，感谢每一位伟大的开发者！\n\n"
		"\t\t\t\t\t\t\t\t\t————胡未名\n"
	);
	system("pause");
}
