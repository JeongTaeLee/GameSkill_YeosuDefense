#pragma once
#include "GameObject.h"
class cBullet :
	public GameObject
{
protected:
	Renderer * renderer;
	Animater * animater;
	Collider * collider;

public:
	float fDamage;
public:
	cBullet();
	virtual ~cBullet();

	virtual void Init()	override;

	void SetBullet(float fDamage);
};

