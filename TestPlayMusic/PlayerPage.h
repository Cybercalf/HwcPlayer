// MediaPlayerPage.h: 播放器页面
#pragma once

#include <cstdio>
#include <Windows.h>
#include <mmsystem.h>
#include <strsafe.h>
#include <conio.h>
#include "Media.h"
#include "List.h"
#include "ListPage.h"
#include "List.h"
#include "VolumePage.h"
#include "ListPage.h"

#pragma comment (lib,"winmm.lib")

#define CLEAR_BUF \
    {\
    int ch; \
while ((ch = getchar()) != EOF && ch != '\n')\
        {\
        ; \
        }\
    }

// 展示播放器页面，同时承担页面交互
void mediaPlayerPage();
// 根据歌曲展示它的歌曲名、歌手、当前播放时间、全部播放时间，以及一个据此生成的进度条
// 同时提示用户可以执行的操作，包括：
// 暂停、继续
// 后退10秒、前进10秒
// 上一曲、下一曲
// 切换播放模式（当前为某某模式）
// 播放列表
//
void showMediaPlayerMenu();

void printProcessBar(int nowTime, int musicTime);

void printStatus(char* szModeBuf);

void loadProcessBar(int nowTime, int musicTime);

void loadStatus();

void loadPlayStatus();

void loadMediaName();

void loadMediaSpeed();

void playMusicUp();

void playMusicDown();

void stepForward10Sec();

void stepBackward10Sec();

void switch_play_status();

void switchMusicSpeed();
