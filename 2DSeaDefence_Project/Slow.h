#pragma once
#include "GameObject.h"
class Slow :
	public GameObject
{
private:
	Renderer * renderer;

	float Rgn;

	float fAccrue;
	float fDelay;
public:
	Slow();
	virtual ~Slow();

	virtual void Init()	override;
	virtual void Update(float Et) override;

	void StartSkill();
};

