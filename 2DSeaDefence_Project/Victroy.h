#pragma once
#include "GameObject.h"
class Victroy :
	public GameObject
{
private:
	Renderer * renderer;

	bool bButton;
	int iAlpha;
public:
	Victroy();
	virtual ~Victroy();

	virtual void Init()		override;
	virtual void Update(float Et)	override;
};

