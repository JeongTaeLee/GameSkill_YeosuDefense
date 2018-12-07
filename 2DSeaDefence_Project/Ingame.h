#pragma once
#include "Scene.h"
class Ingame :
	public Scene
{
private:
	float fManaAccrue;
	float fManaDelay;
public:
	Ingame();
	virtual ~Ingame();

	virtual void Init()	override;
	virtual void Release()	override;
	virtual void Update(float Et) override;
	virtual void Render(LPD3DXSPRITE sprite) override;
};

