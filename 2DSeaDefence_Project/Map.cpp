#include "DXUT.h"
#include "Map.h"
#include "Tile.h"

#include "Monster.h"
#include "Boss.h"
#include "Victroy.h"

Map::Map()
	:renderer(nullptr), w(0), h(0), hac01(nullptr), hac02(nullptr), iWaveCount(0), iCreateCount(0), fWaveAccrue(0.f), fWaveDelay(0.f),
	bStageEnd(false), bWaveEnd(false)
{
}


Map::~Map()
{
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (tileArray[i][j])
				tileArray[i][j]->Destroy(tileArray[i][j]);
		}
	}

	for (auto i = 0; i < h; ++i)
		SAFE_DELETE_ARRAY(tileArray[i]);
	SAFE_DELETE_ARRAY(tileArray);
}

void Map::Init()
{
	renderer = AC<Renderer>();
	iRenderingSort = BACKGROUND01;

	fWaveDelay = 60.f;
	bWaveEnd = true;

	INGAME.SetNowWave(fWaveAccrue);
	INGAME.SetNowWave(1);


	SetWave();
}

void Map::Update(float Et)
{
	if (bStageEnd)
		return;

	CreateMonster(Et);
}

void Map::InitTileArray(int _w, int _h)
{
	w = _w;
	h = _h;

	tileArray = new Tile**[h];

	for (int i = 0; i < h; ++i)
	{
		tileArray[i] = new Tile*[w];
		memset(tileArray[i], NULL, 4 * w);
	}

	SetTile();
}

void Map::InitTile(int x, int y)
{
	if (tileArray[y][x])
		return;

	Tile * tile = new Tile;
	OBJECT.AddObject(tile);
	
	tile->tf->pos = Vector2(80 * x + 40, 80 * y + 40);

	tileArray[y][x] = tile;
}

void Map::InitTileX(int y, int minX, int maxX)
{
	for (int i = minX; i <= maxX; ++i)
	{
		InitTile(i, y);
	}
}

void Map::InitTileY(int x, int minY, int maxY)
{
	for (int i = minY; i <= maxY; ++i)
	{
		InitTile(x, i);
	}
}

void Map::CreateMonster(float Et)
{
	if (INGAME.GetGameEnd())
		return;

	/*
	if (bWaveEnd)
	{
		for (auto Iter : OBJECT.GetLists())
		{
			if (Iter->sTag == "Monster")
				return;
		}

		if (iWaveCount == vWave.size() - 1)
			INGAME.ClearStage();

		if (KEYDOWN('S'))
		{
			fWaveAccrue = 0.f;
			fWaveDelay = 60.f;
			bWaveEnd = false;
		
			++iWaveCount;
			INGAME.SetNowWave(iWaveCount + 1);
		}

		fWaveAccrue += Et;
		INGAME.SetNowTime(fWaveAccrue);

		if (fWaveAccrue > fWaveDelay)
		{
			fWaveAccrue = 0.f;
			fWaveDelay = 60.f;
			bWaveEnd = false;

			++iWaveCount;
			INGAME.SetNowWave(iWaveCount + 1);
		}

		return;
	}
	else
		INGAME.SetNowTime(0);
	*/

	/*
	if (iWaveCount == vWave.size())
	{
		bWaveEnd = true;
		return;
	}
	*/


	if (bWaveEnd)
	{
		for (auto Iter : OBJECT.GetLists())
		{
			if (Iter->sTag == "Monster")
				return;
		}

		if (iWaveCount == vWave.size())
			INGAME.ClearStage();


		fWaveAccrue += Et;
		INGAME.SetNowTime(fWaveAccrue);

		if (fWaveAccrue >= fWaveDelay || KEYDOWN('S'))
		{
			bWaveEnd = false;
			++iWaveCount;

			INGAME.SetNowTime(60.f);
			INGAME.SetNowWave(iWaveCount);
		}
		

		return;
	}


	Accrue += Et;

	if (Delay < Accrue)
	{
		Accrue = 0.f;

		switch (vWave[iWaveCount - 1][iCreateCount])
		{
		case MonsterType::E_MOB01:
			CreateMonster01();
			break;

		case MonsterType::E_MOB02:
			CreateMonster02();
			break;

		case MonsterType::E_MOB03:
			CreateMonster03();
			break;

		case MonsterType::E_MOB04:
			CreateMonster04();
			break;

		case MonsterType::E_BOSS:
			CreateBoss();
		default:
			break;
		}

		++iCreateCount;

		if (iCreateCount == vWave[iWaveCount - 1].size())
		{
			iCreateCount = 0;

			fWaveAccrue = 0.f;
			fWaveDelay = 60.f;

			bWaveEnd = true;
		}


		/*
		if (iCreateCount == vWave[iWaveCount].size() - 1)
		{
			iCreateCount = 0;
		
			fWaveAccrue = 0.f;
			fWaveDelay = 60.f;

			bWaveEnd = true;
		}
		else
			++iCreateCount;
		*/
	}
}


void Map::CreateMonster01()
{
	Monster * monster = new Monster;
	OBJECT.AddObject(monster);
	monster->AddAni("DWalk", "Mob01_DWalk%d", " ", 1, 10);
	monster->AddAni("DLWalk", "Mob01_DLWalk%d", " ", 1, 10);
	monster->AddAni("LWalk", "Mob01_LWalk%d", " ", 1, 10);
	monster->AddAni("ULWalk", "Mob01_ULWalk%d", " ", 1, 10);
	monster->AddAni("UWalk", "Mob01_UWalk%d", " ", 1, 10);
	monster->AddAni("URWalk", "Mob01_URWalk%d", " ", 1, 10);
	monster->AddAni("RWalk", "Mob01_RWalk%d", " ", 1, 10);
	monster->AddAni("DRWalk", "Mob01_DRWalk%d", " ", 1, 10);
	monster->AddAni("Attack", "Mob01_Attack%d", " ", 1, 10);


	monster->GC(Renderer)->SetCenterPos(Vector3(140.f / 2.f, 140.f / 2.f, 0.f));
	monster->GC(Animater)->Play("RWalk");

	monster->SetSpeed((float)MOB01_S);
	monster->SetHp((float)MOB01_H);
	monster->SetAp((float)MOB01_A);
	monster->SetDeadGold(MOB01_G);
	monster->SetScore(MOB01_SC);

	monster->SetHac(hac01);

	if (twoHac)
		SetRoad(monster->GetRoad(), monster);
	else
		SetRoad(monster->GetRoad());
	monster->SetInitRoad();
}

void Map::CreateMonster02()
{
	Monster * monster = new Monster;
	OBJECT.AddObject(monster);
	monster->AddAni("DWalk", "Mob02_DWalk%d", " ", 1, 10);
	monster->AddAni("DLWalk", "Mob02_DLWalk%d", " ", 1, 10);
	monster->AddAni("LWalk", "Mob02_LWalk%d", " ", 1, 10);
	monster->AddAni("ULWalk", "Mob02_ULWalk%d", " ", 1, 10);
	monster->AddAni("UWalk", "Mob02_UWalk%d", " ", 1, 10);
	monster->AddAni("URWalk", "Mob02_URWalk%d", " ", 1, 10);
	monster->AddAni("RWalk", "Mob02_RWalk%d", " ", 1, 10);
	monster->AddAni("DRWalk", "Mob02_DRWalk%d", " ", 1, 10);
	monster->AddAni("Attack", "Mob02_Attack%d", " ", 1, 10);

	monster->GC(Renderer)->SetCenterPos(Vector3(140.f / 2.f, 140.f / 2.f, 0.f));
	monster->GC(Animater)->Play("RWalk");

	monster->SetSpeed((float)MOB02_S);
	monster->SetHp((float)MOB02_H);
	monster->SetAp((float)MOB02_A);
	monster->SetDeadGold(MOB02_G);
	monster->SetScore(MOB02_SC);

	monster->SetHac(hac01);

	if (twoHac)
		SetRoad(monster->GetRoad(), monster);
	else
		SetRoad(monster->GetRoad());
	monster->SetInitRoad();
}

void Map::CreateMonster03()
{
	Monster * monster = new Monster;
	OBJECT.AddObject(monster);
	monster->AddAni("DWalk", "Mob03_DWalk%d", " ", 1, 10);
	monster->AddAni("DLWalk", "Mob03_DLWalk%d", " ", 1, 10);
	monster->AddAni("LWalk", "Mob03_LWalk%d", " ", 1, 10);
	monster->AddAni("ULWalk", "Mob03_ULWalk%d", " ", 1, 10);
	monster->AddAni("UWalk", "Mob03_UWalk%d", " ", 1, 10);
	monster->AddAni("URWalk", "Mob03_URWalk%d", " ", 1, 10);
	monster->AddAni("RWalk", "Mob03_RWalk%d", " ", 1, 10);
	monster->AddAni("DRWalk", "Mob03_DRWalk%d", " ", 1, 10);
	monster->AddAni("Attack", "Mob03_Attack%d", " ", 1, 10);

	monster->GC(Renderer)->SetCenterPos(Vector3(140.f / 2.f, 140.f / 2.f, 0.f));
	monster->GC(Animater)->Play("RWalk");

	monster->SetSpeed((float)MOB03_S);
	monster->SetHp((float)MOB03_H);
	monster->SetAp((float)MOB03_A);
	monster->SetDeadGold(MOB03_G);
	monster->SetScore(MOB03_SC);

	monster->SetHac(hac01);

	if (twoHac)
		SetRoad(monster->GetRoad(), monster);
	else
		SetRoad(monster->GetRoad());
	monster->SetInitRoad();
}

void Map::CreateMonster04()
{
	Monster * monster = new Monster;
	OBJECT.AddObject(monster);
	monster->AddAni("DWalk", "Mob04_DWalk%d", " ", 1, 10);
	monster->AddAni("DLWalk", "Mob04_DLWalk%d", " ", 1, 10);
	monster->AddAni("LWalk", "Mob04_LWalk%d", " ", 1, 10);
	monster->AddAni("ULWalk", "Mob04_ULWalk%d", " ", 1, 10);
	monster->AddAni("UWalk", "Mob04_UWalk%d", " ", 1, 10);
	monster->AddAni("URWalk", "Mob04_URWalk%d", " ", 1, 10);
	monster->AddAni("RWalk", "Mob04_RWalk%d", " ", 1, 10);
	monster->AddAni("DRWalk", "Mob04_DRWalk%d", " ", 1, 10);
	monster->AddAni("Attack", "Mob04_Attack%d", " ", 1, 10);


	monster->GC(Renderer)->SetCenterPos(Vector3(140.f / 2.f, 140.f / 2.f, 0.f));
	monster->GC(Animater)->Play("RWalk");

	monster->SetSpeed((float)MOB04_S);
	monster->SetHp((float)MOB04_H);
	monster->SetAp((float)MOB04_A);
	monster->SetDeadGold(MOB04_G);
	monster->SetScore(MOB04_SC);

	monster->SetHac(hac01);

	if(twoHac)
		SetRoad(monster->GetRoad(), monster);
	else
		SetRoad(monster->GetRoad());
	monster->SetInitRoad();
}

void Map::CreateBoss()
{
	Boss * boss = new Boss;
	OBJECT.AddObject(boss);

	boss->SetHac(hac01);
	SetRoad(boss->GetRoad());
	boss->SetInitRoad();
}
