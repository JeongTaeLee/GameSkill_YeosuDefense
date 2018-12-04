#pragma once
#include "GameObject.h"

class Bubble;

class BubbleCreater :
	public GameObject
{
private:
	list<Bubble*> Waters;

	float fCreateAccrue;
	float fCreateDelay;
public:
	BubbleCreater();
	virtual ~BubbleCreater();

	virtual void Init()	override;
	virtual void Update(float Et) override;
};

