#pragma once
#include "Map.h"
class Map01 :
	public Map
{
private:
	
public:
	Map01();
	virtual ~Map01();

	virtual void Init()	override;

public:
	virtual void SetTile()	override;
	virtual void SetRoad(vector<Vector2> & _road, Monster * monster = nullptr)	override;

public:
	virtual void SetWave()	override;
};

