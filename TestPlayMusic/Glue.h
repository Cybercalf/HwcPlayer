// Glue.h：“胶水”库，存储所有用到的头文件和部分宏定义
#pragma once
#ifndef GLUE_H
#define GLUE_H
#include <Audioclient.h>
#include <ShlObj.h>
#include <Windows.h>
#include <conio.h>
#include <cstdbool>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <endpointvolume.h>
#include <fstream>
#include <io.h>
#include <iostream>
#include <mmdeviceapi.h> //提供IMM开头的结构
#include <mmsystem.h>
#include <string>
#include <strsafe.h>
#include <vector>
#pragma comment(lib, "winmm.lib")

#define CLEAR_BUF                                     \
	{                                                 \
		int ch;                                       \
		while ((ch = getchar()) != EOF && ch != '\n') \
		{                                             \
			;                                         \
		}                                             \
	}

#endif
