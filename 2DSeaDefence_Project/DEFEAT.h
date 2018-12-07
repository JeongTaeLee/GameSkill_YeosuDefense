#pragma once
#include "GameObject.h"
class DEFEAT :
	public GameObject
{
private:
	Renderer * renderer;

	bool bButton;
	int iAlpha;
public:
	DEFEAT();
	virtual ~DEFEAT();

	virtual void Init()	override;
	virtual void Update(float Et)	override;
};

