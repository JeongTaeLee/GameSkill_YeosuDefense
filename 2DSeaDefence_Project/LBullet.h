#pragma once
#include "cBullet.h"
class LBullet :
	public cBullet
{
private:
	float fDurationAccrue;
	float fDurationDelay;
public:
	LBullet();
	virtual ~LBullet();

	virtual void Init()	override;
	virtual void Update(float Et) override;
};

