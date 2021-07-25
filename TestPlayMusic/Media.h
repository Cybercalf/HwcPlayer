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

void MymciSendString(const char* szCommand, char* szbuffer);

int openMusic(char* path);