#include "DXUT.h"
#include "LBullet.h"


LBullet::LBullet()
{
}


LBullet::~LBullet()
{
}

void LBullet::Init()
{
	renderer = AC(Renderer);
	renderer->SetTexture(IMAGE.AddTexture("LBullet", "./rs/png/LBullet.png"));
	renderer->SetCenterPos(Vector3(-10.f, 20.f / 2.f, 0.f));

	fDurationAccrue = 0.f;
	fDurationDelay = 0.4f;
}

void LBullet::Update(float Et)
{
	fDurationAccrue += Et;

	if (fDurationAccrue > fDurationDelay)
	{
		renderer->SetEnable(false);
		Destroy(this);
	}
}
