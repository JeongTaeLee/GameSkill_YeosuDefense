#include "DXUT.h"
#include "cBullet.h"


cBullet::cBullet()
{
	sTag = "Bullet";
	iRenderingSort = INGAME02;
}


cBullet::~cBullet()
{
}

void cBullet::Init()
{
	renderer = AC(Renderer);
	animater = AC(Animater);
	collider = AC(Collider);
}

void cBullet::SetBullet(float _fDamage)
{
	fDamage = _fDamage;
}
