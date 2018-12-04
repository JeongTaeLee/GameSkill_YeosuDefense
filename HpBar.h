#pragma once
#include "GameObject.h"
class HpBar :
	public GameObject
{
private:
	texture * InBar;
	RECT InBarRect;

	Renderer * renderer;

	float fRatio;
public:
	HpBar();
	virtual ~HpBar();

	virtual void Init()	override;

	virtual void Render(LPD3DXSPRITE sprite) override;
public:
	void RenewBar(const Vector2 & pos, float fHp);
	void SetHpBar(texture * _OutBar, texture * _InBar, float fPullHp);
};

