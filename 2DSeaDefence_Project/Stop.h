#pragma once
#include "GameObject.h"
class Stop :
	public GameObject
{
private:
	Renderer * renderer;

	bool bDown;

	int alpha;

	float Accrue;
	float Delay;
public:
	Stop();
	virtual ~Stop();

	virtual void Init()	override;
	virtual void Update(float Et) override;
};

