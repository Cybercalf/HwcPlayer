// MediaLinkList.h: 存储所有对媒体信息链表操作有关的函数
#include <cstdlib>
#include <cstdio>
#include <cstring>

typedef struct
{
	unsigned int id; // 链表节点的id，以0开始依次排列
	char fileName[100]; // 文件名
	// char songName[100]; // 歌曲名
	// char singerName[100]; // 歌手名
	// char timeLength[100]; // 时长，不一定可以正常使用，请注意
	// char fileType[100]; // 文件格式
	char location[100]; // 文件存储位置，包括最后自己的文件名称
} Media;

struct medianode
{
	Media media;
	struct medianode* nextMediaPtr;
};

typedef struct medianode MediaNode;
typedef MediaNode* MediaNodePtr;

// // 创建一个Media节点的实例。返回一个指向该新建的节点的指针。新建节点默认不与其他节点连接
// MediaNodePtr getNewMediaNode(unsigned int id, const char* fileName, const char* songName, const char* singerName,
//                          const char* timeLength, const char* fileType, const char* location);

// 在链表中追加一个媒体节点，成功返回非0值，不成功返回0
int appendMediaNode(MediaNodePtr* sPtr, Media value);

// 在链表中根据id删除一个媒体节点，成功返回非0值，不成功返回0
int deleteMediaNodeById(MediaNodePtr* sPtr, unsigned int id);

// 在链表中根据歌曲名查找所有符合条件的链表信息。
// 返回一个指向新链表头部的指针，新链表存储所有符合条件的媒体节点
// 不成功返回NULL
MediaNodePtr searchAllMediaBySongName(MediaNodePtr sPtr, const char* songName);

// 从头打印链表中所有节点的信息，成功返回1，不成功返回0
int printMediaLinkList(MediaNodePtr sPtr);

// 根据id交换链表中两个媒体节点的位置，成功返回1，不成功返回0
int swapTwoMediaNode(MediaNodePtr sPtr, unsigned int firstId, unsigned int secondId);

// 根据id查找链表中的一个节点，成功返回一个指向符合要求的媒体节点的指针
// 不成功返回NULL
MediaNodePtr searchAMediaNodeById(MediaNodePtr sPtr, unsigned int id);
