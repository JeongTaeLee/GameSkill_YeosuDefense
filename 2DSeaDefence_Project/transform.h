#pragma once
#include "Component.h"
class transform :
	public Component
{
	public:
	Vector2 pos;
	Vector2 size;
	float rot;

	Vector2		worldPos;
	Matrix	matWorld;
public:
	transform();
	virtual ~transform();

	void Update();
	void SetTransform(LPD3DXSPRITE sprite);
};

