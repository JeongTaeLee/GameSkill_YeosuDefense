#include "DXUT.h"
#include "Bubble.h"


Bubble::Bubble()
	:renderer(nullptr), fAngle(0.0f)
{
}


Bubble ::~Bubble()
{
}

void Bubble::Init()
{
	renderer = AC(Renderer);
	
	renderer->SetTexture(IMAGE.AddTexture("WaterBalloon", "./rs/png/WaterBalloon.png"));
	renderer->SetMidCenter();
	renderer->SetRenderType(D3DXSPRITE_ALPHABLEND);

	iRenderingSort = UI02;
}

void Bubble::Update(float Et)
{
	tf->pos.x = fX + (cosf(fAngle) * 60);
	tf->pos.y -= fSpeed * DXUTGetElapsedTime();

	fAngle += D3DXToRadian(2.f);

	if (tf->pos.y < -100)
		SetActive(false);
}

void Bubble::SetBubble()
{
	fAngle = 0.f;
	fSpeed = GetRandomNumber(150, 250);
	
	tf->pos = Vector2(GetRandomNumber(60, 900), 800);
	SetActive(true);

	fX = tf->pos.x;
}
