#pragma once
#include "Component.h"
class Renderer :
	public Component
{
private:
	texture * lpTex;

	RECT		re;
	Vector3		vCenterPos;

	Color		color;
public:
	DWORD		dwRenderType;
	
	Renderer();
	virtual ~Renderer();

	virtual void Render(LPD3DXSPRITE sprite);
public:
	void SetTexture(texture * tex);
	void SetColor(Color _color) { color = _color; }
	void SetRenderType(DWORD _dwRenderType) { dwRenderType = _dwRenderType; }
	void SetCenterPos(Vector3 _vCenterPos) { vCenterPos = _vCenterPos; }
	void SetMidCenter() { vCenterPos = Vector3(lpTex->info.Width / 2, lpTex->info.Height / 2, 0.f); }
};

