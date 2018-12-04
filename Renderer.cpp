#include "DXUT.h"
#include "Renderer.h"


Renderer::Renderer()
	:lpTex(nullptr), re({0, 0, 0, 0}), vCenterPos(0.f, 0.f, 0.f), color(D3DCOLOR_XRGB(255, 255, 255)),
	dwRenderType(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE)
{
}


Renderer::~Renderer()
{
}

void Renderer::Render(LPD3DXSPRITE sprite)
{
	sprite->Begin(dwRenderType);
	sprite->Draw(lpTex->lpTex, &re, &vCenterPos, nullptr, color);
	sprite->End();
}

void Renderer::SetTexture(texture * tex)
{
	lpTex = tex; 
	SetRect(&re, 0, 0, lpTex->info.Width, lpTex->info.Height);
}

