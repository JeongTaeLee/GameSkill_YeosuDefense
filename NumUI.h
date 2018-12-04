#pragma once
#include "GameObject.h"
class NumUI :
	public GameObject
{
private:
	char GoldStr[128];
	char MpStr[128];
	char Score[128];

	char WaveTime[128];
	char WaveCount[128];
public:
	NumUI();
	virtual ~NumUI();

	virtual void Init()	override;

	virtual void Update(float Et)	override;
	virtual void Render(LPD3DXSPRITE sprite)	override;
};

