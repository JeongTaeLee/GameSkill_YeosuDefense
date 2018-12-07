#include "DXUT.h"
#include "HpBar.h"


HpBar::HpBar()
{
}


HpBar::~HpBar()
{
}

void HpBar::Init()
{
	renderer = AC(Renderer);
	iRenderingSort = UI01;
}

void HpBar::Render(LPD3DXSPRITE sprite)
{
	Matrix matPos;
	D3DXMatrixTranslation(&matPos, -(InBar->info.Width / 2.f), 0.f, 0.f);

	Matrix matWorld = tf->matWorld * matPos;

	sprite->SetTransform(&matWorld);

	sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
	sprite->Draw(InBar->lpTex, &InBarRect, &Vector3(0.f, InBar->info.Height / 2, 0.f), nullptr, OrginColor);
	sprite->End();
}

void HpBar::RenewBar(const Vector2 & pos,float fHp)
{
	tf->pos = pos;
	SetRect(&InBarRect, 0, 0, fHp * fRatio, InBar->info.Height);
}

void HpBar::SetHpBar(texture * _OutBar, texture * _InBar, float fPullHp)
{
	InBar = _InBar;
	fRatio = _InBar->info.Width / fPullHp;

	renderer->SetTexture(_OutBar);
	renderer->SetMidCenter();
}
