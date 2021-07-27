#pragma once

#include <cstdio>
#include <Windows.h>
#include <mmsystem.h>
#include <strsafe.h>

#pragma comment (lib,"winmm.lib")

#define CLEAR_BUF \
    {\
    int ch; \
while ((ch = getchar()) != EOF && ch != '\n')\
        {\
        ; \
        }\
    }

// 调用MCI接口对音乐文件进行操作，成功返回0，不成功返回非0
int MymciSendString(const char* szCommand, char* szbuffer);

// 调用MCI接口打开文件，成功返回0，不成功返回非0
int openMusic(const char* path);

int closeMusic();

int playMusic();

int playMusicRepeat();

int stopMusic();

int pauseMusic();

int resumeMusic();

int seekToPosition(int position);

int viewPlaybackStatus();

int getMusicCurrentPosition();

int getMusicLength();
