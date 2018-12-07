#pragma once
#include "Map.h"
class Map03 :
	public Map
{
public:
	Map03();
	virtual ~Map03();

public:
	virtual void Init()	override;
public:

public:
	virtual void SetTile()	override;
	virtual void SetRoad(vector<Vector2> & _road, Monster * monster = nullptr)	override;

public:
	virtual void SetWave()	override;
};

