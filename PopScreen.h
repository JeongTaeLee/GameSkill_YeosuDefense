#pragma once
#include "GameObject.h"
class PopScreen :
	public GameObject
{
private:
	Renderer * renderer;
public:
	PopScreen();
	virtual ~PopScreen();

	virtual void Init()				override;
	virtual void Update(float Et)	override;

	void SetPopScreen(texture * tex);
};

