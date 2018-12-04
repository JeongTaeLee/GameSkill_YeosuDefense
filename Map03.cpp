#include "DXUT.h"
#include "Map03.h"
#include "Hac.h"
#include "Boss.h"

Map03::Map03()
{
}


Map03::~Map03()
{
}

void Map03::Init()
{
	Map::Init();
	renderer->SetTexture(IMAGE.AddTexture("Map03", "./rs/png/Map03.png"));
	InitTileArray(24, 13);

	Delay = 1.5f;
	Accrue = 0.f;

	hac01 = (Hac*)OBJECT.AddObject(new Hac, Vector2(1765, 470));

}

void Map03::SetTile()
{
	InitTileX(9, 0, 7);
	InitTileX(11, 0, 9);

	InitTile(8, 8);
	InitTileX(7, 4, 7);

	InitTileY(10, 5, 11);
	InitTileX(5, 6, 9);

	InitTile(5, 4);
	InitTileX(3, 6, 11);

	InitTileY(3, 3, 7);
	InitTileX(1, 6, 14);

	InitTileY(14, 2, 7);
	InitTileY(12, 4, 10);

	InitTileX(10, 13, 18);

	InitTileY(18, 7, 9);

	InitTileX(7, 19, 23);

	InitTile(15, 8);

	InitTileY(16, 5, 7);

	InitTileX(5, 17, 23);

}

void Map03::SetRoad(vector<Vector2>& _road, Monster * monster)
{
	_road.push_back(Vector2(-50, 830));
	_road.push_back(Vector2(585, 830));

	Vector2 pivot = Vector2(_road[_road.size() - 1].x, 660);
	float r = _road[_road.size() - 1].y - pivot.y;

	for (int i = 85; i > -90; i -= 5)
	{
		float cos = cosf(D3DXToRadian(i)), sin = sinf(D3DXToRadian(i));

		Vector2 pos = Vector2(pivot.x + cos * r, pivot.y + sin * r);
	
		_road.push_back(pos);
	}

	_road.push_back(Vector2(525, _road[_road.size() - 1].y));

	pivot = Vector2(_road[_road.size() - 1].x, 330);
	r = _road[_road.size() - 1].y - pivot.y;


	for (int i = 5; i < 180; i += 5)
	{
		float cos = cosf(D3DXToRadian(i + 90)), sin = sinf(D3DXToRadian(i+ 90));

		Vector2 pos = Vector2(pivot.x + cos * r, pivot.y + sin * r);

		_road.push_back(pos);
	}

	_road.push_back(Vector2(945, _road[_road.size() - 1].y));

	pivot = Vector2(_road[_road.size() - 1].x, 310);
	r = pivot.y - _road[_road.size() - 1].y;


	for (int i = 5; i < 90; i += 5)
	{
		float cos = cosf(D3DXToRadian(i - 90)), sin = sinf(D3DXToRadian(i - 90));

		Vector2 pos = Vector2(pivot.x + cos * r, pivot.y + sin * r);

		_road.push_back(pos);
	}

	_road.push_back(Vector2(_road[_road.size() - 1].x, 580));

	pivot = Vector2(1235, _road[_road.size() - 1].y);
	r = pivot.x - _road[_road.size() - 1].x;

	for (int i = 175; i > 0; i -= 5)
	{
		float cos = cosf(D3DXToRadian(i)), sin = sinf(D3DXToRadian(i));

		Vector2 pos = Vector2(pivot.x + cos * r, pivot.y + sin * r);

		_road.push_back(pos);
	}

	_road.push_back(Vector2(_road[_road.size() - 1].x, _road[_road.size() - 1].y));

	//1535
	pivot = Vector2(_road[_road.size() - 1].x + 100, _road[_road.size() - 1].y);
	r = pivot.x - _road[_road.size() - 1].x;

	for (int i = 185; i < 270; i += 5)
	{
		float cos = cosf(D3DXToRadian(i)), sin = sinf(D3DXToRadian(i));

		Vector2 pos = Vector2(pivot.x + cos * r, pivot.y + sin * r);

		_road.push_back(pos);
	}

	_road.push_back(Vector2(1600, _road[_road.size() - 1].y));
}

void Map03::SetWave()
{
	vWave.push_back(vector<MonsterType>());
	for (int i = 0; i < 8; ++i)
		vWave[0].push_back(MonsterType::E_MOB03);

	vWave.push_back(vector<MonsterType>());
	for (int i = 0; i < 8; ++i)
	{
		if (i % 2)
			vWave[1].push_back(MonsterType::E_MOB02);
		else
			vWave[1].push_back(MonsterType::E_MOB04);
	}

	vWave.push_back(vector<MonsterType>());
	for (int i = 0; i < 5; ++i)
		vWave[2].push_back(MonsterType::E_MOB04);
	for (int i = 0; i < 5; ++i)
		vWave[2].push_back(MonsterType::E_MOB02);

	vWave.push_back(vector<MonsterType>());
	for (int i = 0; i < 5; ++i)
		vWave[3].push_back(MonsterType::E_MOB02);
	for (int i = 0; i < 5; ++i)
		vWave[3].push_back(MonsterType::E_MOB04);

	vWave.push_back(vector<MonsterType>());
	for (int i = 0; i < 5; ++i)
		vWave[4].push_back(MonsterType::E_MOB03);
	for (int i = 0; i < 5; ++i)
		vWave[4].push_back(MonsterType::E_MOB04);

	vWave[4].push_back(MonsterType::E_BOSS);

}
