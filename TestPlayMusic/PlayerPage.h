// MediaPlayerPage.h: 播放器页面
#pragma once

#include "Glue.h"
#include "List.h"
#include "ListPage.h"
#include "Media.h"
#include "Volume.h"

// 展示播放器页面，同时承担页面交互
// 交互功能：
// 1. 播放与暂停
// 2. 切换播放模式：列表循环、单曲循环和随机播放
// 3. 跳转到播放列表的指定曲目
// 4. 调整歌曲播放的倍速：1.25,1.0，0.8
// 5. 上一曲、下一曲
// 6. 快退10秒、快进10秒
// 7. 减小、增大系统音量
// 8. 减小、增大播放器音量
// 9. 静音、取消静音
// 10. 返回主菜单页面
//
void playerPage();

// 展示播放器页面
// 功能：
// 加载并显示进度条、当前播放状态、当前播放模式、当前播放音乐名、当前播放速度
// 显示当前系统音量、播放器音量
// 提示用户可以做的操作
//
void showPlayerPage();

// 根据现在播放时间与播放总时长，生成一个代表进度条的字符串并存储在全局变量processBarBuf中
// 参数：
// nowTime：当前已播放的时间
// musicTime：播放总时间
//
void loadProcessBar(int nowTime, int musicTime);

// 获取当前播放状态，并存储在全局变量szStatusBuf中
//
void loadStatus();

// 获取当前播放模式，并存储在全局变量szPlayStatusBuf中
void loadPlayStatus();

// 获取当前播放的音乐名，并存储在全局变量szMediaNameBuf中
void loadMediaName();

// 获取当前播放速度，并存储在全局变量szMediaSpeedBuf中
void loadMediaSpeed();

// 播放列表的上一首歌，可以循环
void playMusicUp();

// 根据当前播放模式，选择下一首要播放的歌曲并播放
void playMusicDown();

// 将当前播放进度倒退10秒左右
void stepForward10Sec();

// 将当前播放进度快进10秒左右
void stepBackward10Sec();

// 切换当前的播放模式，在以下三种模式间循环切换：
// 列表循环
// 单曲循环
// 随机播放
//
void switch_play_status();

// 切换当前的播放速度，在以下三种速度间循环切换
// 1倍速
// 1.25倍速
// 0.8倍速
//
void switchMusicSpeed();

// 获取当前播放器是否静音，将状态存储在全局变量isSongMuteBuf中
void loadIsSongMute();

// 将播放器在静音与非静音间切换
// 如果从非静音切换到静音，会先将当前播放音量存储在全局变量temp_song_volume中
// 如果从静音切换到非静音，会自动将播放音量设为temp_song_volume，从而恢复之前的播放音量
//
void switchSongMute();

// 将系统音量增大固定值
void audioVolumeUp();

// 将系统音量减小固定值
void audioVolumeDown();

// 将播放器音量增大固定值
void songVolumeUp();

// 将播放器音量减小固定值
void songVolumeDown();