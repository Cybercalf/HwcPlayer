// Media.h：媒体交互基本函数
#pragma once
#include "Glue.h"
#include "Lrc.h"
#include "List.h"
#include "ListPage.h"

// 代表三种不同的播放模式
enum PLAY_STATUS
{
	STATUS_PLAY_SEQUENCE = 0,
	STATUS_PLAY_REPEAT,
	STATUS_PLAY_RANDOM,
};

// 代表当前音乐的播放状态
enum STATUS
{
	STATUS_PLAY = 0,
	STATUS_PAUSE,
	STATUS_STOPPED,
};

// 代表当前播放器是否静音
enum SONG_MUTE_STATUS
{
	MUTE = 0,
	NOT_MUTE,
};

// 调用MCI接口对音乐文件进行操作，成功返回0，不成功返回非0
// 参数：
// szCommand：指令字符串
// szbuffer：缓存字符串，如果不需要可以取NULL
// 返回值：
// int，成功返回0，不成功返回非0
int MymciSendString(const char *szCommand, char *szbuffer);

// 调用MCI接口根据短路径打开文件，同时将相应的.lrc文件加载到歌词链表中
// 参数：
// path：文件路径
// 返回值：
// int，成功返回0，不成功返回非0
//
int openMusicByShortPath(const char *short_path);

// 调用MCI接口关闭文件，成功返回0，不成功返回非0
int closeMusic();

// 调用MCI接口播放音乐，成功返回0，不成功返回非0
int playMusic();

// 调用MCI接口循环播放音乐，成功返回0，不成功返回非0（最终没有用到）
int playMusicRepeat();

// 调用MCI接口停止音乐，成功返回0，不成功返回非0
int stopMusic();

// 调用MCI接口暂停音乐，成功返回0，不成功返回非0
int pauseMusic();

// 调用MCI接口继续音乐，成功返回0，不成功返回非0
int resumeMusic();

// 调用MCI接口将播放位置放到指定位置
// 参数：
// position：指定的播放位置，是一个整数
// 返回值：
// int， 成功返回0，不成功返回非0
//
int seekToPosition(int position);

// 调用MCI接口获取当前播放位置
// 返回值：
// int，当前播放的位置，单位为毫秒
//
int getMusicCurrentPosition();

// 调用MCI接口获取当前音乐的总播放时长
// 返回值：
// int，当前音乐的总播放时长，单位为毫秒
//
int getMusicLength();

// 调用MCI接口获取当前音乐的播放速度
// 返回值：
// int，当前音乐的播放速度，标准为1000
//
int getMusicSpeed();

// 调用MCI接口设置当前音乐的播放速度
// 参数：
// speed：指定的音乐播放速度，标准为1000
//
void setMusicSpeed(int speed);