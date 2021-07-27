#include "File.h"
using namespace std;
void storeList(const char* filename, MediaNodePtr currentPtr)
{
	ofstream ofs;
	ofs.open(filename, ios::out | ios::binary | ios::trunc);
	if (!ofs.is_open())
	{
		puts("文件打开失败");
	}
	// 如果链表中有节点，就要把它们挨个存起来
	if (!isListEmpty(currentPtr))
	{
		// 如果currentPtr不为NULL(没有到达链表的末尾)，就一直循环
		while (currentPtr != NULL)
		{
			ofs.write((const char*)currentPtr, sizeof(MediaNode));
			currentPtr = currentPtr->next;
		}
	}
	ofs.close();
}

void readList(const char* filename, MediaNodePtr sPtr)
{
	ifstream ifs;
	ifs.open(filename, ios::in | ios::binary);
	if (!ifs.is_open())
	{
		puts("文件打开失败");
	} else
	{
		MediaNode tempNode;
		while(ifs.read((char*)&tempNode, sizeof(MediaNode)))
		{
			appendNode(sPtr, tempNode.media.path);
		}
	}
	
	
}
