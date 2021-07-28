#pragma once
#include "Media.h"
#include "List.h"
#include "ListPage.h"
#include "Volume.h"
#include <conio.h>
#include <Windows.h>

enum SONG_MUTE_STATUS
{
	MUTE = 0,
	NOT_MUTE,
};


void volumePage();

void showVolumePage();

void loadIsSongMute();

void switchSongMute();

void audioVolumeUp();

void audioVolumeDown();

void songVolumeUp();

void songVolumeDown();