#pragma once
#include "singleton.h"

enum STAGE
{
	STAGE_01,
	STAGE_02,
	STAGE_03,
	STAGE_END,
};

class Cannon;

class IngameManager :
	public singleton<IngameManager>
{
public:
	STAGE stage;
	Cannon * cannon;

	int  iScore;
	int  iGold;
	int  iMp;

	bool bOnCannon; // 포탑을 들고 있는지 안들고있는지.

	bool bStop;
	bool bTime;

	bool bGameEnd;
	bool bLoadingComplete;

	int iNowWave;
	float fNowTime;
public:
	IngameManager();
	virtual ~IngameManager();

	void CreateMap();
	void UpgradeCannon();

	void SetPickCannon(Cannon * _cannon) { cannon = _cannon; }

public:
	void BuyCannon01();
	void BuyCannon02();
	void BuyCannon03();

	void BuySlow();
	void BuyStop();

	float GetETime();
public:
	void AddGold(int money) { iGold += money; }
	void AddMp(int mp) { iMp += mp; }
	void AddScore(int score) { iScore += score; }

public:
	void NextStage();
	void ContinueStage();

	void ClearStage();
	void DefeatStage();
public:
	void SetStop(bool _bStop) { bStop = _bStop; }
	void SetTime(bool _bTime) { bTime = _bTime; }

	void SetNowWave(int _iNowWave) { iNowWave = _iNowWave; }
	void SetNowTime(float _fNowTime) { fNowTime = _fNowTime; }
public:
	int GetGold() { return iGold; }
	int GetMp() { return iMp; }
	int GetScore() { return iScore; }
	bool GetGameEnd() { return bGameEnd; }

	int GetNowWave() { return iNowWave; }
	float GetNowTime() { return fNowTime; }

	bool GetStop() { return bStop; }
	bool GetTime() { return bTime; }
};

#define INGAME IngameManager::GetInst()