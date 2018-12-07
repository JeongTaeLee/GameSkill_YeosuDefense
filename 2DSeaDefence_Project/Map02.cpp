#include "DXUT.h"
#include "Map02.h"
#include "Hac.h"
#include "Monster.h"

Map02::Map02()
{
}


Map02::~Map02()
{
}

void Map02::Init()
{
	Map::Init();
	renderer->SetTexture(IMAGE.AddTexture("Map02", "./rs/png/Map02.png"));
	InitTileArray(24, 13);

	Delay = 1.5f;
	Accrue = 0.f;

	hac01 = (Hac*)OBJECT.AddObject(new Hac, Vector2(1765, 150));
	hac02 = (Hac*)OBJECT.AddObject(new Hac, Vector2(1765, 800));

	twoHac = true;
}

void Map02::SetTile()
{
	InitTileX(8, 0, 6);
	InitTileX(10, 0, 7);

	InitTileY(6, 2, 8);
	InitTileY(8, 3, 10);

	InitTileX(1, 6, 10);
	InitTileY(10, 2, 5);
	
	InitTileX(5, 11, 12);
	InitTileY(12, 1, 5);

	InitTileX(1, 13, 23);
	InitTileX(3, 14, 23);

	//10 7
	InitTileX(7, 9, 12);

	InitTileY(12, 8, 11);

	InitTileX(11, 13, 23);

	InitTileX(9, 14 , 23);

	InitTileY(14, 3, 9);
}

void Map02::SetRoad(vector<Vector2>& _road , Monster * monster)
{
	int Height = 760;

	_road.push_back(Vector2(-20, Height));
	_road.push_back(Vector2(480, Height));
	
	Vector2 pivot = Vector2(_road[_road.size()-1].x, 640);
	float r = _road[_road.size() - 1].y - pivot.y;

	for (int i = 85; i > 0; i -= 5)
	{
		float cos = cosf(D3DXToRadian(i)), sin = sinf(D3DXToRadian(i));

		Vector2 pos;
		pos.x = pivot.x + cos * r;
		pos.y = pivot.y + sin * r;
		_road.push_back(pos);
	}
	
	_road.push_back(Vector2(_road[_road.size() - 1].x, 280));

	pivot = Vector2(680, _road[_road.size() - 1].y);
	r = pivot.x - _road[_road.size() - 1].x;

	for (int i = 5; i < 180; i += 5)
	{
		float cos = cosf(D3DXToRadian(i - 180)), sin = sinf(D3DXToRadian(i - 180));

		Vector2 pos;
		pos.x = pivot.x + cos * r;
		pos.y = pivot.y + sin * r;
		_road.push_back(pos);
	}

	_road.push_back(Vector2(_road[_road.size() - 1].x, 445));

	pivot = Vector2(830, _road[_road.size() - 1].y);
	r = pivot.x - _road[_road.size() - 1].x;

	for (int i = 175; i > 90; i -= 5)
	{
		float cos = cosf(D3DXToRadian(i)), sin = sinf(D3DXToRadian(i));

		Vector2 pos;
		pos.x = pivot.x + cos * r;
		pos.y = pivot.y + sin * r;
		_road.push_back(pos);
	}

	_road.push_back(Vector2(1000, _road[_road.size() - 1].y));


	int j = GetRandomNumber(0, 1);

	if (j == 0)
	{
		pivot = Vector2(_road[_road.size() - 1].x, 430);
		r = _road[_road.size() - 1].y - pivot.y;

		for (int i = 85; i > 0; i -= 5)
		{
			float cos = cosf(D3DXToRadian(i)), sin = sinf(D3DXToRadian(i));

			Vector2 pos;
			pos.x = pivot.x + cos * r;
			pos.y = pivot.y + sin * r;
			_road.push_back(pos);
		}

		_road.push_back(Vector2(_road[_road.size() - 1].x, 300));

		pivot = Vector2(1200, _road[_road.size() - 1].y);
		r = pivot.x - _road[_road.size() - 1].x;

		for (int i = 5; i < 90; i += 5)
		{
			float cos = cosf(D3DXToRadian(i - 180)), sin = sinf(D3DXToRadian(i - 180));

			Vector2 pos;
			pos.x = pivot.x + cos * r;
			pos.y = pivot.y + sin * r;
			_road.push_back(pos);
		}
		monster->SetHac(hac01);
	}
	else
	{
		pivot = Vector2(_road[_road.size() - 1].x, 600);
		r = pivot.y - _road[_road.size() - 1].y;

		for (int i = 5; i < 90; i += 5)
		{
			float cos = cosf(D3DXToRadian(i - 90)), sin = sinf(D3DXToRadian(i - 90));

			Vector2 pos;
			pos.x = pivot.x + cos * r;
			pos.y = pivot.y + sin * r;
			_road.push_back(pos);
		}

		_road.push_back(Vector2(_road[_road.size() - 1].x, 720));

		pivot = Vector2(1200, _road[_road.size() - 1].y);
		r = pivot.x - _road[_road.size() - 1].x;

		for (int i = 175; i > 90; i -= 5)
		{
			float cos = cosf(D3DXToRadian(i)), sin = sinf(D3DXToRadian(i));

			Vector2 pos;
			pos.x = pivot.x + cos * r;
			pos.y = pivot.y + sin * r;
			_road.push_back(pos);
		}

		monster->SetHac(hac02);
	}

	_road.push_back(Vector2(1650, _road[_road.size() - 1].y));
}

void Map02::SetWave()
{
	vWave.push_back(vector<MonsterType>());
	for (int i = 0; i < 8; ++i)
		vWave[0].push_back(MonsterType::E_MOB01);

	vWave.push_back(vector<MonsterType>());
	for (int i = 0; i < 8; ++i)
	{
		if (i % 2)
			vWave[1].push_back(MonsterType::E_MOB03);
		else
			vWave[1].push_back(MonsterType::E_MOB01);
	}

	vWave.push_back(vector<MonsterType>());
	for (int i = 0; i < 5; ++i)
		vWave[2].push_back(MonsterType::E_MOB02);
	for (int i = 0; i < 5; ++i)
		vWave[2].push_back(MonsterType::E_MOB04);

	vWave.push_back(vector<MonsterType>());
	for (int i = 0; i < 5; ++i)
		vWave[3].push_back(MonsterType::E_MOB01);
	for (int i = 0; i < 5; ++i)
		vWave[3].push_back(MonsterType::E_MOB03);

	vWave.push_back(vector<MonsterType>());
	for (int i = 0; i < 5; ++i)
		vWave[4].push_back(MonsterType::E_MOB04);
	for (int i = 0; i < 5; ++i)
		vWave[4].push_back(MonsterType::E_MOB02);

}
