#pragma once
#include "Map.h"
class Map02 :
	public Map
{
public:
	Map02();
	virtual ~Map02();

public:
	virtual void Init()	override;

public:
	virtual void SetTile()	override;
	virtual void SetRoad(vector<Vector2> & _road, Monster * monster = nullptr)	override;

public:
	virtual void SetWave()	override;
};

