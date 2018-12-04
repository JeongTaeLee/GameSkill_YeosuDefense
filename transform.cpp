#include "DXUT.h"
#include "transform.h"


transform::transform()
{
	pos = Vector2(0.f, 0.f);
	size = Vector2(1.f, 1.f);
	rot = 0.f;

}


transform::~transform()
{
}

void transform::Update()
{
	Matrix matPos;
	D3DXMatrixTranslation(&matPos, pos.x, pos.y, 0.f);

	Matrix matSize;
	D3DXMatrixScaling(&matSize, size.x, size.y, 0.f);

	Matrix matRot;
	D3DXMatrixRotationZ(&matRot, rot);

	matWorld = matSize * matRot * matPos;
	worldPos = Vector2(matWorld._41, matWorld._42);
}

void transform::SetTransform(LPD3DXSPRITE sprite)
{
	sprite->SetTransform(&matWorld);
}
