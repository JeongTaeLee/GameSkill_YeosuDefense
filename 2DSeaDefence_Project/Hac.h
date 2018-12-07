#pragma once
#include "GameObject.h"

class HpBar;

class Hac :
	public GameObject
{
private:
	Renderer * renderer;
	Animater * animater;
	Collider * collider;

	HpBar * hpBar;

	float fHp;
public:
	Hac();
	virtual ~Hac();

	virtual void Init()	override;
	virtual void Update(float Et)	override;

	void HitBullet(float Damage);
};

