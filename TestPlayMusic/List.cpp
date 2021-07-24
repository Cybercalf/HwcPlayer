#include "List.h"

Media* createMedia(char* path)
{
	struct _finddata_t* musicInfo = (struct _finddata_t*)malloc(sizeof(struct _finddata_t));
	long handle = _findfirst(path, musicInfo);
	if (handle == -1)
	{
		//找到文件，并将信息存储在结构体_finddata_t中
		return NULL; //未找到文件则返回NULL
	}
	else
	{
		// 为新建的Media结构体分配一块内存
		Media* newMedia = (Media*)malloc(sizeof(Media));
		// 初始化Media结构体中的参数
		newMedia->name = musicInfo->name;
		newMedia->path = path;

		// 通过在windows中打开对应的文件，来获取对应音频文件的有关信息
		char lengthOfTime[1024] = "";
		char cmd[1000] = "";
		strcpy_s(cmd, "open ");
		strcat_s(cmd, path);
		strcat_s(cmd, " alias song");

		//打开文件
		mciSendString(cmd, NULL, 0, NULL);
		//获取音频时长，单位秒
		mciSendString("status song length", lengthOfTime, 1024, NULL);
		newMedia->length = atoi(lengthOfTime) / 1000;
		// 关闭文件
		mciSendString("close song", NULL, 0, NULL);

		_findclose(handle);

		return newMedia;
	}
}

MediaNodePtr createNode(char* path)
{
	MediaNodePtr newNodePtr = (MediaNodePtr)malloc(sizeof(MediaNode));
	Media* tempMediaPtr = createMedia(path);
	if (tempMediaPtr != NULL)
	{
		newNodePtr->media = *tempMediaPtr;
	}
	return newNodePtr;
}

MediaNodePtr createList()
{
	MediaNodePtr head = (MediaNodePtr)malloc(sizeof(MediaNode));
	head->number = 0;
	head->next = NULL;

	return head;
}

int isListEmpty(MediaNodePtr startPtr)
{
	return startPtr == NULL;
}


int appendNode(MediaNodePtr& startPtr, char* path)
{
	MediaNodePtr newPtr = createNode(path);

	if (newPtr = NULL)
	{
		return -1;
	}
	else
	{
		MediaNodePtr pMoveFront = NULL;
		MediaNodePtr pMove = startPtr->next;
		while (pMove != NULL)
		{
			pMoveFront = pMove;
			pMove = pMove->next;
		}
		if (pMoveFront == NULL) // 在链表开头追加节点，这里写的代码不一定对
		{
			newPtr->next = startPtr;
			startPtr = newPtr;
		}
		else // 在链表后追加节点
		{
			pMoveFront->next = newPtr;
		}
		return 0;
	}
}


// int appendMediaNode(MediaNodePtr* sPtr, Media value)
// {
// 	// 新建一个Media节点
// 	MediaNodePtr newMediaPtr = (MediaNodePtr)malloc(sizeof(MediaNode));
// 	newMediaPtr->media = value; // 将传进来的Media的值赋给新建节点的Media
// 	// 如果新建节点成功
// 	if (newMediaPtr != NULL)
// 	{
// 		MediaNodePtr previousPtr = NULL;
// 		MediaNodePtr currentPtr = *sPtr;
// 		// 直到currentPtr为NULL为止，移动两个指针的位置，从而找到链表的末尾
// 		while (currentPtr != NULL)
// 		{
// 			previousPtr = currentPtr;
// 			currentPtr = currentPtr->next;
// 		}
// 		// 如果currentPtr为NULL，说明原先链表没有任何节点，要追加的节点在开头
// 		if (previousPtr == NULL)
// 		{
// 			*sPtr = newMediaPtr;
// 		}
// 			// 如果currentPtr不为NULL，说明原先链表中有节点
// 		else
// 		{
// 			previousPtr->next = newMediaPtr;
// 		}
// 		return 1;
// 	}
// 	return 0;
// }
//
// int deleteMediaNodeById(MediaNodePtr* sPtr, unsigned int id)
// {
// 	return 0;
// }
//
// MediaNodePtr searchAllMediaBySongName(MediaNodePtr sPtr, const char* songName)
// {
// 	return NULL;
// }
//
// int printMediaLinkList(MediaNodePtr currentPtr)
// {
// 	// 如果链表为空
// 	if (currentPtr == NULL)
// 	{
// 		return 0;
// 	}
// 	else
// 	{
// 		while (currentPtr != NULL)
// 		{
// 			// 自己设置的打印的方式
// 			printf("%u\n", currentPtr->media.id);
// 			// 找下一个节点
// 			currentPtr = currentPtr->next;
// 		}
// 		return 1;
// 	}
// }
//
// int swapTwoMediaNodeById(MediaNodePtr  * sPtr, unsigned int firstId, unsigned int secondId)
// {
// 	MediaNodePtr previousFirstPtr = NULL;
// 	MediaNodePtr firstPtr = *sPtr;
// 	while (firstPtr->media.id != firstId)
// 	{
// 		previousFirstPtr = firstPtr;
// 		firstPtr = firstPtr->next;
// 	}
// 	MediaNodePtr previousSecondPtr = NULL;
// 	MediaNodePtr secondPtr = *sPtr;
// 	while (secondPtr->media.id != secondId)
// 	{
// 		previousSecondPtr = secondPtr;
// 		secondPtr = secondPtr->next;
// 	}
// 	// 如果两个指针都不为空，说明都找到了对应节点
// 	if (firstPtr != NULL && secondPtr != NULL)
// 	{
// 		// 交换两个节点指向下一个节点的指针
// 		MediaNodePtr tempPtr = firstPtr->next;
// 		firstPtr->next = secondPtr->next;
// 		secondPtr->next = tempPtr;
// 		// 各自上一个节点的这个信息也需要改变
// 		if (previousFirstPtr != NULL && previousSecondPtr != NULL)
// 		{
// 			MediaNodePtr tempPtr = previousFirstPtr->next;
// 			previousFirstPtr->next = previousSecondPtr->next;
// 			previousSecondPtr->next = tempPtr;
// 		}
// 		// 如果其中一个previousPtr为空，说明要交换的节点中有一个是头节点，这时交换节点后必须修改指向头结点的指针
// 		else if (previousFirstPtr == NULL && previousSecondPtr != NULL)
// 		{
// 			previousSecondPtr->next = firstPtr;
// 			*sPtr = secondPtr;
// 		}
// 		else if (previousSecondPtr == NULL && previousFirstPtr != NULL)
// 		{
// 			previousFirstPtr->next = secondPtr;
// 			*sPtr = firstPtr;
// 		}
// 		return 1;
// 	}
// 	// 如果找不到要交换的节点，则交换失败
// 	return 0;
// }
//
// MediaNodePtr searchAMediaNodeById(MediaNodePtr sPtr, unsigned int id)
// {
// 	return NULL;
// }
