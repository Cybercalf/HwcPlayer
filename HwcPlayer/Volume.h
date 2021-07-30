// Volume.h：与系统音量和播放器音量有关的基本操作函数
#pragma once
#include "Glue.h"
#include "Media.h"

// 设置系统音量
// 参数：
// audio_volume：指定的系统音量，范围0-100
//
void setAudioVolume(int audio_volume);

// 获取当前系统音量
// 返回值：当前的系统音量，范围0-100
//
int getAudioVolume();

// 检测当前播放器是否静音
// 返回值：
// true：当前播放器静音
// false：当前播放器没有静音
//
bool isSongMute();

// 设置播放器是否静音
// 参数：
// mute：指定播放器是否静音，是为true，否为false
void setSongMute(bool mute);

// 获取当前播放器音量
// 返回值：当前的播放器音量，范围0-1000
//
int getSongVolume();

// 设置播放器音量
// 参数：
// song_volume：指定的播放器音量，范围0-1000
//
void setSongVolume(int song_volume);
