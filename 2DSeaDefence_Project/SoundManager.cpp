#include "DXUT.h"
#include "SoundManager.h"


SoundManager::SoundManager()
{
	ZeroMemory(&mciOpen, sizeof(mciOpen));
	ZeroMemory(&mciPlay, sizeof(mciPlay));
	ZeroMemory(&mciStatus, sizeof(mciStatus));

	deviceId = 0;
	bBackGroundSound = false;
}


SoundManager::~SoundManager()
{
	for (auto Iter : sounds)
		mciSendCommand(Iter.second, MCI_CLOSE, 0, (DWORD)(LPVOID)NULL);
}

void SoundManager::PlayBackGround(cstr path)
{
	if (bBackGroundSound)
		sndPlaySound(NULL, SND_ASYNC);

	sndPlaySoundA(path.c_str(), SND_LOOP | SND_ASYNC); // SND_ASYNC 음악 연주시 프로그램을 멈추않음
	bBackGroundSound = true;
}

void SoundManager::AddSound(cstr name, cstr path, SoundFileType type)
{
	DWORD sound = 0;

	switch (type)
	{
	case E_MP3:
		sound = LoadMp3(path);
		break;
	case E_WAV:
		sound = LoadWave(path);
		break;
	default:
		break;
	}

	if (!sound)
	{
		DEBUG_LOG("Failed Load Sound : " << name);
		return;
	}
	sounds.insert(make_pair(name, sounds.size() + 1));
}

void SoundManager::Play(cstr name)
{
	auto find = sounds.find(name);

	if (find == sounds.end())
		return;

	find->second = mciSendCommand(find->second, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
	find->second = mciSendCommand(find->second, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&mciPlay);
}

DWORD SoundManager::LoadWave(cstr path)
{
	DWORD result = 0;

	mciOpen.lpstrDeviceType = "WaveAudio";
	mciOpen.lpstrElementName = path.c_str();

	result = mciSendCommand(deviceId, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&mciOpen);

	if (result)
		return result;

	deviceId = mciOpen.wDeviceID;
	mciPlay.dwCallback = (DWORD)DXUTGetHWND();

	if (result)
		return result;

	return 0;
}

DWORD SoundManager::LoadMp3(cstr path)
{
	DWORD result = 0;

	mciOpen.lpstrDeviceType = "MPEGVideo";
	mciOpen.lpstrElementName = path.c_str();

	result = mciSendCommand(deviceId, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&mciOpen);

	if (result)
		return result;

	deviceId = mciOpen.wDeviceID;
	mciPlay.dwCallback = (DWORD)DXUTGetHWND();

	if (result)
		return result;

	return 0;
}
