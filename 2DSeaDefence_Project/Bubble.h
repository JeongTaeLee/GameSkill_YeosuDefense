#pragma once
#include "GameObject.h"
class Bubble :
	public GameObject
{
private:
	Renderer * renderer;

	float fAngle;
	float fSpeed;
	float fX;
public:
	Bubble();
	virtual ~Bubble();

	virtual void Init()	override;
	virtual void Update(float Et) override;

	void SetBubble();
};

