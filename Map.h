#pragma once
#include "GameObject.h"
#include "Monster.h"

class Tile;
class Hac;
class Monster;

class Map :
	public GameObject
{
protected:
	int w, h;

	Renderer * renderer;
	Tile ***   tileArray; 

	vector<Vector2> road;

	float Accrue;
	float Delay;

	float fWaveAccrue;
	float fWaveDelay;
	bool bWaveEnd;	

	Hac * hac01;
	Hac * hac02;

	bool twoHac = false;
	 
	vector< vector<MonsterType> > vWave;
	int iCreateCount;
	int iWaveCount;

	bool bStageEnd;
public:
	Map();
	virtual ~Map();

	virtual void Init()	override;
	virtual void Update(float Et) override;
public:
	void		 InitTileArray(int w, int h);
	virtual void SetTile()	PURE;
	virtual void SetRoad(vector<Vector2> & _road, Monster * hac = nullptr)	PURE;

	void InitTile(int x, int y);
	void InitTileX(int y, int minX, int maxX);
	void InitTileY(int x, int minY, int maxY);

	virtual void CreateMonster(float Et);

public:
	void CreateMonster01();
	void CreateMonster02();
	void CreateMonster03();
	void CreateMonster04();	
	void CreateBoss();

	virtual void SetWave() PURE;
};

