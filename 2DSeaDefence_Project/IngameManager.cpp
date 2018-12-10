#include "DXUT.h"
#include "IngameManager.h"
#include "Map01.h"
#include "Map02.h"
#include "Map03.h"
#include "Cannon.h"

#include "Cannon01.h"
#include "Cannon02.h"
#include "Cannon03.h"
#include "Slow.h"
#include "Stop.h"

#include "Victroy.h"
#include "DEFEAT.h"

IngameManager::IngameManager()
{
	stage = STAGE_01;
	cannon = nullptr;

	iScore = 0;
	iGold = 2000;
	iMp = 400;

	bOnCannon = false;

	bStop = false;
	bTime = false;

	bGameEnd = false;
	bLoadingComplete = false;
	
	iNowWave = 1;

	fNowTime = 0.f;
}


IngameManager::~IngameManager()
{
}


void IngameManager::CreateMap()
{
	switch (stage)
	{
	case STAGE_01:
		CAMERA.SetCameraLock(Vector2(0, 0), Vector2(1480, 720));
		OBJECT.AddObject(new Map01);
		break;
	case STAGE_02:
		CAMERA.SetCameraLock(Vector2(0, 0), Vector2(2120, 1040));
		OBJECT.AddObject(new Map02);
		break;
	case STAGE_03:
		CAMERA.SetCameraLock(Vector2(0, 0), Vector2(2120, 1040));
		OBJECT.AddObject(new Map03);
		break;
	default:
		break;
	}
}

void IngameManager::UpgradeCannon()
{
	if (cannon)
		cannon->Upgrade();
}

void IngameManager::BuyCannon01()
{
	if (!INGAME.bOnCannon) { 

		if (300 <= iGold)
		{
			iGold -= 300;
			OBJECT.AddObject(new Cannon01); 
			INGAME.bOnCannon = true; 
		}
	}
}

void IngameManager::BuyCannon02()
{
	if (!INGAME.bOnCannon) {

		if (500 <= iGold)
		{
			iGold -= 500;
			OBJECT.AddObject(new Cannon02);
			INGAME.bOnCannon = true;
		}
	}
}

void IngameManager::BuyCannon03()
{
	if (!INGAME.bOnCannon) {

		if (700 <= iGold)
		{
			iGold -= 700;
			OBJECT.AddObject(new Cannon03);
			INGAME.bOnCannon = true;
		}
	}
}

void IngameManager::BuySlow()
{
	if (200 <= iMp)
	{
		iMp -= 200;
		OBJECT.AddObject(new Slow);
	}
}

void IngameManager::BuyStop()
{
	if (200 <= iMp)
	{
		iMp -= 200;
		OBJECT.AddObject(new Stop);
	}
}

float IngameManager::GetETime()
{
	if (bStop)
		return 0.f;
	if (bTime)
		return DXUTGetElapsedTime() * 2.f;

	return DXUTGetElapsedTime();
}

void IngameManager::NextStage()
{

		
	cannon		= nullptr;
	bOnCannon	= false;

	bStop = false;
	bTime = false;
	bGameEnd = false;

	iScore = 0;

	switch ((STAGE)((int)stage + 1))
	{
	case STAGE_02:
		iGold = 2500;
		iMp = 400;

		stage = (STAGE)((int)stage + 1);
		SCENE.ChanScene("Ingame");
		break;
	case STAGE_03:
		iGold = 3000;
		iMp = 400;
		
		stage = (STAGE)((int)stage + 1);
		SCENE.ChanScene("Ingame");
		break;
	case STAGE_END:
		iGold = 200;
		iMp = 400;

		stage = STAGE_01;
		SCENE.ChanScene("Load");
	default:
		break;
	}
}

void IngameManager::ContinueStage()
{
	switch (stage)
	{
	case STAGE_01:
		iGold = 2000;
		iMp = 400;
		break;
	case STAGE_02:
		iGold = 2500;
		iMp = 400;
		break;
	case STAGE_03:
		iGold = 3000;
		iMp = 400;
		break;
	case STAGE_END:
		break;
	default:
		break;
	}
	iScore = 0;

	cannon = nullptr;
	bOnCannon = false;

	bStop = false;
	bTime = false;
	bGameEnd = false;

	SCENE.ChanScene("Load");
}

void IngameManager::ClearStage()
{
	OBJECT.AddObject(new Victroy);
	bGameEnd = true;
}

void IngameManager::DefeatStage()
{
	OBJECT.AddObject(new DEFEAT);
	bGameEnd = true;
}
