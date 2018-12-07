#pragma once
#include "GameObject.h"

class Cannon;

class PickCannon :
	public GameObject
{
private:
	Cannon * cannon;
	GameObject * button;
public:
	PickCannon();
	~PickCannon();

	virtual void Init()				override;
	virtual void Update(float Et)	override;
public:
	void Pick();
	void Upgrade();
};

