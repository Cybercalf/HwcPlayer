#include "Lrc.h"
using namespace std;

LrcNodePtr g_lrc_head_ptr = createLrcList();

int loadIrcList(const char* filename)
{
	// 利用C++文件操作，以文本形式打开歌词文件
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open()) // 如果没有打开
	{
		return -1;
	}
	else
	{
		char buf[1024] = "";
		while (ifs.getline(buf, sizeof(buf))) // 对歌词文件一行行地读取，读取的一行暂存在buf中
		{
			int minute = 0, second = 0, bufint = -1; // 因为时间只精确到秒，所以小数点后的数忽略不计，存在bufint中
			char lrc_str[1024] = "";
			sscanf(buf, "[%d:%d.%d]%[^\n]", &minute, &second, &bufint, lrc_str);
			// 如果这一行格式不规范（比如，读取的这一行中，代表时间的数，小数点后面没有数字），不读入
			if (bufint == -1) continue;
			// 如果这一行没有歌词，不读入
			if (strcmp(lrc_str, "") == 0) continue;
			// 如果格式规范且有歌词，则生成一个Lrc结构体，将其添加到歌词链表中
			Lrc tempLrc;
			tempLrc.time = minute * 60 + second;
			strcpy(tempLrc.buf, lrc_str);
			appendLrcNode(tempLrc);
		}
		return 0;
	}
}

void appendLrcNode(Lrc lrc)
{
	LrcNodePtr newptr = (LrcNodePtr)malloc(sizeof(LrcNode));
	if (newptr == NULL) return;
	newptr->lrc = lrc;
	newptr->next = NULL;
	LrcNodePtr pMoveFront = g_lrc_head_ptr;
	LrcNodePtr pMove = g_lrc_head_ptr->next;
	while (pMove != NULL)
	{
		pMoveFront = pMove;
		pMove = pMove->next;
	}
	// 如果新建的节点时间和之前的节点时间不一样，就可以追加，否则不追加
	if(pMoveFront->lrc.time != lrc.time)
	{
		pMoveFront->next = newptr;
	}
}

LrcNodePtr createLrcList()
{
	LrcNodePtr newPtr = (LrcNodePtr)malloc(sizeof(LrcNode));
	newPtr->next = NULL;
	newPtr->lrc.time = -1;
	memset(newPtr->lrc.buf, '\0', sizeof(newPtr->lrc.buf));
	return newPtr;
}

bool isLrcListEmpty()
{
	return g_lrc_head_ptr->next == NULL;
}

void clearLrcList()
{
	LrcNodePtr pMoveFront = g_lrc_head_ptr;
	LrcNodePtr pMove = g_lrc_head_ptr->next;
	while (!isLrcListEmpty())
	{
		pMoveFront->next = pMove->next; // 让节点脱节
		free(pMove);
		pMove = g_lrc_head_ptr->next;
	}
}

const char* getLrcByTime(int time)
{
	// 如果链表为空，返回空字符串
	if (isLrcListEmpty()) return "\0";
	LrcNodePtr pMove = g_lrc_head_ptr->next;
	while (pMove != NULL && pMove->lrc.time != time)
	{
		pMove = pMove->next;
	}
	// 如果没找到对应节点（字符串），返回空字符串
	if (pMove == NULL) return "\0";
	// 如果找到，返回找到的字符串
	return pMove->lrc.buf;
}
