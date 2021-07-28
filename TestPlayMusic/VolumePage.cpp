// #include "VolumePage.h"
// using namespace std;
//
// char isSongMuteBuf[10];
// enum SONG_MUTE_STATUS song_mute_status = NOT_MUTE;
//
// void volumePage()
// {
// 	int exit = 0;
// 	while (!exit)
// 	{
// 		while (!_kbhit())
// 		{
// 			showVolumePage();
// 			Sleep(1000);
// 		}
// 		switch (_getch())
// 		{
// 		case '+':
// 		case '=':
// 			audioVolumeUp();
// 			break;
// 		case '_':
// 		case '-':
// 			audioVolumeDown();
// 			break;
// 		case '0':
// 		case ')':
// 			songVolumeUp();
// 			break;
// 		case '(':
// 		case '9':
// 			songVolumeDown();
// 			break;
// 		case '8':
// 		case '*':
// 			switchSongMute();
// 			break;
// 		case 'Q':
// 		case 'q':
// 			exit = 1;
// 			break;
// 		default:
// 			break;
// 		}
// 	}
// }
//
// void showVolumePage()
// {
// 	system("cls");
// 	loadIsSongMute();
// 	printf("\n\n\n\n\n"
// 	       "\t\t    * * * * * * * *                   * * * * * * * *\n"
// 	       "\t\t    * * * * * *          音   量          * * * * * *\n"
// 	       "\t\t    * * * * * * * *                   * * * * * * * *\n"
// 	       "\n\n"
// 	       "\t\t                   - 当前系统音量    %5d\n"
// 	       "\t\t                   - 当前播放器音量  %.1f%%\n"
// 	       "\t\t                   - 播放器是否静音 [%s]\n\n"
// 	       "\t\t                    [  +  ]  增大系统音量\n"
// 	       "\t\t                    [  -  ]  减小系统音量\n"
// 	       "\t\t                    [  0  ]  增大播放器音量\n"
// 	       "\t\t                    [  9  ]  减小播放器音量\n"
// 	       "\t\t                    [  8  ]  静音/取消静音\n"
// 	       "\t\t                    [  Q  ]  返回\n",
// 	       getAudioVolume(),
// 	       getSongVolume() / 10.0,
// 	       isSongMuteBuf);
// }
//
// void loadIsSongMute()
// {
// 	if (song_mute_status == MUTE) sprintf(isSongMuteBuf, "%s", "是");
// 	else sprintf(isSongMuteBuf, "%s", "否");
// }
//
// void switchSongMute()
// {
// 	if (song_mute_status == NOT_MUTE)
// 	{
// 		setSongMute(true);
// 		song_mute_status = MUTE;
// 	}
// 	else
// 	{
// 		setSongMute(false);
// 		song_mute_status = NOT_MUTE;
// 	}
// }
//
// void audioVolumeUp()
// {
// 	int audio_volume = (getAudioVolume() + 2);
// 	if (audio_volume > 100) audio_volume = 100;
// 	setAudioVolume(audio_volume);
// }
//
// void audioVolumeDown()
// {
// 	int audio_volume = (getAudioVolume() - 2);
// 	if (audio_volume < 0) audio_volume = 0;
// 	setAudioVolume(audio_volume);
// }
//
// void songVolumeUp()
// {
// 	int song_volume = (getSongVolume() + 50);
// 	if (song_volume > 1000) song_volume = 1000;
// 	setSongVolume(song_volume);
// }
//
// void songVolumeDown()
// {
// 	int song_volume = (getSongVolume() - 50);
// 	if (song_volume < 0) song_volume = 0;
// 	setSongVolume(song_volume);
// }
