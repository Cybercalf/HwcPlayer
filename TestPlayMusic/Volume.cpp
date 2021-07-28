#include "Volume.h"
using namespace std;

void setAudioVolume(int audio_volume)
{
	IMMDeviceEnumerator* pDeviceEnumerator = 0;
	/*The IMMDeviceEnumerator interface provides methods for enumerating multimedia device resources.
	In the current implementation of the MMDevice API, the only device resources that this interface
	can enumerate are audio endpoint devices.A client obtains a reference to an IMMDeviceEnumerator
	interface by calling the CoCreateInstance function, as described previously(see MMDevice API).
	The device resources enumerated by the methods in the IMMDeviceEnumerator interface are represented
	 as collections of objects with IMMDevice interfaces.A collection has an IMMDeviceCollection interface.
	The IMMDeviceEnumerator::EnumAudioEndpoints method creates a device collection.To obtain a pointer to
	the IMMDevice interface of an item in a device collection, the client calls the IMMDeviceCollection::Item method*/

	/*IMMDeviceEnumerator接口提供了枚举多媒体设备资源的方法。在MMDevice API的当前实现中，该接口能够枚举的唯一设备资源是音频端点设备。
	客户端通过调用CoCreateInstance函数获得对IMMDeviceEnumerator接口的引用，如上所述(参见MMDevice API)。由IMMDeviceEnumerator接口中的
	方法枚举的设备资源表示为具有IMMDevice接口的对象集合。集合有一个IMMDeviceCollection接口。IMMDeviceEnumerator:: enumaudioendpoint方
	法创建一个设备集合。为了获得设备集合中一个项的IMMDevice接口的指针，客户端调用IMMDeviceCollection:: item方法。*/
	IMMDevice* pDevice = 0;

	/*The IMMDevice interface encapsulates the generic features of a multimedia device resource.
	In the current implementation of the MMDevice API, the only type of device resource that an
	IMMDevice interface can represent is an audio endpoint device.*/

	/*IMMDevice接口封装了多媒体设备资源的通用特性。在MMDevice API的当前实现中，imdevice接口可以表示的设备资源的唯一类型是音频端点设备。*/

	IAudioEndpointVolume* pAudioEndpointVolume = 0;

	/*IAudioEndpointVolume接口表示与音频端点设备之间的音频流上的音量控制。*/
	/*The IAudioEndpointVolume interface represents the volume controls on the audio stream to or from an audio endpoint device. */

	IAudioClient* pAudioClient = 0;

	CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator),
	                 (void**)&pDeviceEnumerator);
	/*STDAPI CoCreateInstance(
		REFCLSID rclsid, //创建的Com对象的类标识符(CLSID)
		LPUNKNOWN pUnkOuter, //指向接口IUnknown的指针
		DWORD dwClsContext, //运行可执行代码的上下文
		REFIID riid, //创建的Com对象的接口标识符
		LPVOID * ppv //用来接收指向Com对象接口地址的指针变量
	);*/
	pDeviceEnumerator->GetDefaultAudioEndpoint(eRender, eMultimedia, &pDevice);
	pDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (void**)&pAudioEndpointVolume);
	pDevice->Activate(__uuidof(IAudioClient), CLSCTX_ALL, NULL, (void**)&pAudioClient);

	pAudioEndpointVolume->SetMasterVolumeLevelScalar(audio_volume / 100.0, &GUID_NULL);
	pAudioClient->Release();
	pAudioEndpointVolume->Release();
	pDevice->Release();
	pDeviceEnumerator->Release();
}

int getAudioVolume()
{
	IMMDeviceEnumerator* pDeviceEnumerator = 0;
	/*The IMMDeviceEnumerator interface provides methods for enumerating multimedia device resources.
	In the current implementation of the MMDevice API, the only device resources that this interface
	can enumerate are audio endpoint devices.A client obtains a reference to an IMMDeviceEnumerator
	interface by calling the CoCreateInstance function, as described previously(see MMDevice API).
	The device resources enumerated by the methods in the IMMDeviceEnumerator interface are represented
	 as collections of objects with IMMDevice interfaces.A collection has an IMMDeviceCollection interface.
	The IMMDeviceEnumerator::EnumAudioEndpoints method creates a device collection.To obtain a pointer to
	the IMMDevice interface of an item in a device collection, the client calls the IMMDeviceCollection::Item method*/

	/*IMMDeviceEnumerator接口提供了枚举多媒体设备资源的方法。在MMDevice API的当前实现中，该接口能够枚举的唯一设备资源是音频端点设备。
	客户端通过调用CoCreateInstance函数获得对IMMDeviceEnumerator接口的引用，如上所述(参见MMDevice API)。由IMMDeviceEnumerator接口中的
	方法枚举的设备资源表示为具有IMMDevice接口的对象集合。集合有一个IMMDeviceCollection接口。IMMDeviceEnumerator:: enumaudioendpoint方
	法创建一个设备集合。为了获得设备集合中一个项的IMMDevice接口的指针，客户端调用IMMDeviceCollection:: item方法。*/
	IMMDevice* pDevice = 0;

	/*The IMMDevice interface encapsulates the generic features of a multimedia device resource.
	In the current implementation of the MMDevice API, the only type of device resource that an
	IMMDevice interface can represent is an audio endpoint device.*/

	/*IMMDevice接口封装了多媒体设备资源的通用特性。在MMDevice API的当前实现中，imdevice接口可以表示的设备资源的唯一类型是音频端点设备。*/

	IAudioEndpointVolume* pAudioEndpointVolume = 0;

	/*IAudioEndpointVolume接口表示与音频端点设备之间的音频流上的音量控制。*/
	/*The IAudioEndpointVolume interface represents the volume controls on the audio stream to or from an audio endpoint device. */

	IAudioClient* pAudioClient = 0;

	CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator),
	                 (void**)&pDeviceEnumerator);
	/*STDAPI CoCreateInstance(
		REFCLSID rclsid, //创建的Com对象的类标识符(CLSID)
		LPUNKNOWN pUnkOuter, //指向接口IUnknown的指针
		DWORD dwClsContext, //运行可执行代码的上下文
		REFIID riid, //创建的Com对象的接口标识符
		LPVOID * ppv //用来接收指向Com对象接口地址的指针变量
	);*/
	pDeviceEnumerator->GetDefaultAudioEndpoint(eRender, eMultimedia, &pDevice);
	pDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (void**)&pAudioEndpointVolume);
	pDevice->Activate(__uuidof(IAudioClient), CLSCTX_ALL, NULL, (void**)&pAudioClient);
	float current_audio_volume;
	pAudioEndpointVolume->GetMasterVolumeLevelScalar(&current_audio_volume);
	pAudioClient->Release();
	pAudioEndpointVolume->Release();
	pDevice->Release();
	pDeviceEnumerator->Release();
	return current_audio_volume * 100;
}

bool isSongMute()
{
	char buf[16] = "";
	MymciSendString("status song audio", buf);
	return (bool)!(0 == strcmp(buf, "on"));
}

void setSongMute(bool mute)
{
	char cmd[64] = "";
	if (mute)
	{
		sprintf(cmd, "%s", "setaudio BackMusic off");
	}
	else
	{
		sprintf(cmd, "%s", "setaudio BackMusic on");
	}
	MymciSendString(cmd, NULL);
}

int getSongVolume()
{
	char buf[64] = "";
	MymciSendString("status BackMusic volume", buf);
	return atoi(buf);
}

void setSongVolume(int song_volume)
{
	char cmd[64] = "";
	sprintf(cmd, "setaudio BackMusic volume to %d", song_volume);
	MymciSendString(cmd, NULL);
}
