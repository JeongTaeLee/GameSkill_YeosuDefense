#include "DXUT.h"
#include "Map01.h"
#include "Hac.h"


Map01::Map01()
{
}


Map01::~Map01()
{
}

void Map01::Init()
{
	Map::Init();
	renderer->SetTexture(IMAGE.AddTexture("Map01", "./rs/png/Map01.png"));
	InitTileArray(16, 9);

	Delay = 1.5f;
	Accrue = 0.f;

	hac01 = (Hac*)OBJECT.AddObject(new Hac, Vector2(1125, 480));
}

void Map01::SetTile()
{
	InitTileX(1, 0, 12);
	InitTileX(3, 0, 12);

	InitTileX(5, 3, 15);
	InitTileX(7, 2, 15);
}

void Map01::SetRoad(vector<Vector2> & _road, Monster * monster)
{
	float Height = 180.f;

	_road.push_back(Vector2(-20, Height));
	_road.push_back(Vector2(1020, Height));

	Vector2 pivot = Vector2(_road[_road.size() - 1].x, 260);
	float r = fabs(pivot.y - Height);

	for (int i = 5; i < 180; i += 5)
	{
		float cos = cosf(D3DXToRadian(i - 90)), sin = sinf(D3DXToRadian(i - 90));

		Vector2 pos = Vector2(pivot.x + (r * cos), pivot.y + (r * sin));
		_road.push_back(pos);
	}

	_road.push_back(Vector2(280, _road[_road.size() - 1].y));

	Height = _road[_road.size() - 1].y;
	pivot = Vector2(_road[_road.size() - 1].x, 420);
	r = fabs(pivot.y - Height);
	
	for (int i = 265; i > 90; i -= 5)
	{
		float cos = cosf(D3DXToRadian(i)), sin = sinf(D3DXToRadian(i));

		Vector2 pos = Vector2(pivot.x + (r * cos), pivot.y + (r * sin));
		_road.push_back(pos);
	}

	_road.push_back(Vector2(950, _road[_road.size() - 1].y));

	
}

void Map01::SetWave()
{	
	vWave.push_back(vector<MonsterType>());
	for (int i = 0; i < 8; ++i)
		vWave[0].push_back(MonsterType::E_MOB01);

	vWave.push_back(vector<MonsterType>());
	for (int i = 0; i < 8; ++i)
	{
		if (i % 2)
			vWave[1].push_back(MonsterType::E_MOB02);
		else
			vWave[1].push_back(MonsterType::E_MOB01);
	}

	vWave.push_back(vector<MonsterType>());
	for (int i = 0; i < 5; ++i)
		vWave[2].push_back(MonsterType::E_MOB03);
	for (int i = 0; i < 5; ++i)
		vWave[2].push_back(MonsterType::E_MOB02);

	vWave.push_back(vector<MonsterType>());
	for (int i = 0; i < 5; ++i)
		vWave[3].push_back(MonsterType::E_MOB02);
	for (int i = 0; i < 5; ++i)
		vWave[3].push_back(MonsterType::E_MOB01);

	vWave.push_back(vector<MonsterType>());
	for (int i = 0; i < 5; ++i)
		vWave[4].push_back(MonsterType::E_MOB01);
	for (int i = 0; i < 5; ++i)
		vWave[4].push_back(MonsterType::E_MOB02);

}
