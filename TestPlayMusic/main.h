#pragma once

#include <cstdio>
#include <Windows.h>
#include <mmsystem.h>
#include <strsafe.h>
#include "Media.h"
#include "MainPage.h"

#pragma comment (lib,"winmm.lib")

#define CLEAR_BUF \
    {\
    int ch; \
while ((ch = getchar()) != EOF && ch != '\n')\
        {\
        ; \
        }\
    }
