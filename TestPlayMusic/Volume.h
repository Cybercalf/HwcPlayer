#pragma once
#include "Media.h"
#include <string>
#include <mmdeviceapi.h> //提供IMM开头的结构
#include <endpointvolume.h>
#include <audioclient.h>
#include <conio.h>
#include <cstdio>
#include <Windows.h>

enum SONG_MUTE_STATUS
{
	MUTE = 0,
	NOT_MUTE,
};


void setAudioVolume(int audio_volume);

int getAudioVolume();

bool isSongMute();

void setSongMute(bool mute);

int getSongVolume();

void setSongVolume(int song_volume);
