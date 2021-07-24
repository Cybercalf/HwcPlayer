#include "medialinklist.h"


int appendMediaNode(MediaNodePtr* sPtr, Media value)
{
	// 新建一个Media节点
	MediaNodePtr newMediaPtr = (MediaNodePtr)malloc(sizeof(MediaNode));
	newMediaPtr->media = value;
	// 如果新建节点成功
	if (newMediaPtr != NULL)
	{
		MediaNodePtr previousPtr = NULL;
		MediaNodePtr currentPtr = *sPtr;
		// 直到currentPtr为NULL为止，移动两个指针的位置，从而找到链表的末尾
		while (currentPtr != NULL)
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextMediaPtr;
		}
		// 如果currentPtr为NULL，说明原先链表没有任何节点，要追加的节点在开头
		if (previousPtr == NULL)
		{
			*sPtr = newMediaPtr;
		}
		// 如果currentPtr不为NULL，说明原先链表中有节点
		else
		{
			previousPtr->nextMediaPtr = newMediaPtr;
		}
		return 1;
	}
	return 0;
}

int deleteMediaNodeById(MediaNodePtr* sPtr, unsigned int id)
{
	return 0;
}

MediaNodePtr searchAllMediaBySongName(MediaNodePtr sPtr, const char* songName)
{
	return NULL;
}

int printMediaLinkList(MediaNodePtr currentPtr)
{
	// 如果链表为空
	if (currentPtr == NULL)
	{
		return 0;
	}
	else
	{
		while (currentPtr != NULL)
		{
			printf("%u\n", currentPtr->media.id);
			currentPtr = currentPtr->nextMediaPtr;
		}
		return 1;
	}
}

int swapTwoMediaNode(MediaNodePtr sPtr, unsigned int firstId, unsigned int secondId)
{
	return 0;
}

MediaNodePtr searchAMediaNodeById(MediaNodePtr sPtr, unsigned int id)
{
	return NULL;
}
