#include "ListPage.h"
using namespace std;

enum STATUS
{
	STATUS_STOP = 0,
	STATUS_PLAY,
	STATUS_PAUSE,
}; //用枚举变量限制状态的变化范围

MediaNodePtr g_headPtr = createList();

void listPage()
{



	int exit = 0; // 页面退出的标志
	int num = 0; // 用户输入的节点编号
	char path[PATH_LENGTH] = "";
	while (!exit)
	{
		showListPage();
		switch (_getch())
		{
		case '1':
			strcpy_s(path, "");
			printf("请输入您要添加的mp3文件的路径:\n");

			scanf("%s", path);
			switch (appendNode(g_headPtr, path))
			{
			case 0:
				puts("添加成功");
				break;
			case -1:
				puts("新建节点失败");
				break;
			case -2:
				puts("列表中已有该曲目，不能重复添加");
				break;
			}
			system("pause");

			break;
		case '2': // print
			printList(g_headPtr);

			system("pause");
			break;
		case '3':
			printf("input number: ");
			int number;
			scanf("%d", &number);
			CLEAR_BUF
			strcpy_s(path, getNodePathByNumber(g_headPtr, number));
			printf("%s\n", path);
			system("pause");
			break;
		case '4':
			printf("%s", "即将退出此界面!\n");
			system("pause");
			exit = 1;
			break;
		default:
			puts("invalid choice.");
			system("pause");

			break;
		}
	}
}

void showListPage()
{
	system("cls");
#ifdef DEBUG
	printf("g_headPtr: %p\n", g_headPtr);
#endif
	puts("这里是播放列表页面！\n"
		"1. 为链表中添加一个节点\n"
		"2. 打印链表节点\n"
		"3. 根据编号输出一个节点的路径\n"
		"4. exit"
	);
}
