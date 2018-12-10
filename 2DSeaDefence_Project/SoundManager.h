#pragma once
#include "singleton.h"

enum SoundFileType
{
	E_MP3,
	E_WAV,
};

class SoundManager :
	public singleton<SoundManager>
{
private:
	MCI_OPEN_PARMSA mciOpen;
	MCI_PLAY_PARMS	mciPlay;
	MCI_STATUS_PARMS mciStatus;

	UINT deviceId;

	map<string, DWORD> sounds;

	bool bBackGroundSound;
public:
	SoundManager();
	virtual ~SoundManager();

	void PlayBackGround(cstr path);

	void AddSound(cstr name, cstr path, SoundFileType type);
	void Play(cstr name);

	DWORD LoadWave(cstr path);
	DWORD LoadMp3(cstr path);
};

#define SOUND SoundManager::GetInst()