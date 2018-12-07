#pragma once
#include "GameObject.h"

class Cannon;

class Tile :
	public GameObject
{
private:
	Renderer * renderer;
	Collider * collider;
	
	Cannon *	cannon;
public:
	Tile();
	virtual ~Tile();

	virtual void Init()	override;

	virtual void OnCollider(Collider * otherColl) override;
};

