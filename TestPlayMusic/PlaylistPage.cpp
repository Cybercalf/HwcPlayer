#include "PlaylistPage.h"
using namespace std;

void playlistPage()
{
	MediaNodePtr startPtr = NULL;
	Media tempMedia;
	memset(tempMedia.fileName, '\0', sizeof(tempMedia.fileName));
	memset(tempMedia.location, '\0', sizeof(tempMedia.location));
	int exit = 0;
	while (!exit)
	{
		showPlaylistPage();
		switch (_getch())
		{
		case '1': // insert

			printf("%s", "输入id：");
			scanf("%u", &(tempMedia.id)); // 读入学生id
			if (appendMediaNode(&startPtr, tempMedia))
			{
				printf("%u inserted.\n", tempMedia.id);
			}
			else
			{
				printf("id %u not inserted. No memory available.\n", tempMedia.id);
			}
			system("pause");
			break;
		case '2': // print
			printMediaLinkList(startPtr);
			system("pause");
			break;
		case '4':
			printf("%s", "即将退出此界面!\n");
			system("pause");
			exit = 1;
			break;
		default:
			break;
		}
	}
}

void showPlaylistPage()
{
	system("cls");
	puts("这里是播放列表页面！\n"
		"1. 为链表中添加一个节点\n"
		"2. 打印链表节点\n"
		"4. exit"
	);
}
