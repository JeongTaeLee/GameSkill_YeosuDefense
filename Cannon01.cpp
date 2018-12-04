#include "DXUT.h"
#include "Cannon01.h"
#include "ClamBullet.h"
#include "Monster.h"

Cannon01::Cannon01()
{
}


Cannon01::~Cannon01()
{
}

void Cannon01::Init()
{
	Cannon::Init();
	animater->Add("Attack1", "Cannon01_01_%d", " ", 1, 20);
	animater->Add("Attack2", "Cannon01_02_%d", " ", 1, 20);
	animater->Add("Attack3", "Cannon01_03_%d", " ", 1, 20);
	animater->Play("Attack1");
	animater->Stop(0);
	animater->SetDelay(0.02f);
	renderer->SetCenterPos(Vector3(140.f / 2.f, 140.f / 2.f + 10, 0.f));

	fAttackAccrues = (float)CANNON01_D;
	fAttackDelay = (float)CANNON01_D;

	fRgn = (float)CANNON01_R;
	fDamage = (float)CANNON01_A;

	fAttackIndex = 15;

	iUpgradeCost = 200;
}

void Cannon01::Attack(float Et)
{
	ClamBullet * bullet = new ClamBullet;
	OBJECT.AddObject(bullet);

	bullet->SetBullet(fDamage);
	bullet->SetClamBullet(tf->pos, monster->tf->pos, 0.3f);
}

void Cannon01::Upgrade()
{
	LevelUp();

	if (level == CannonLevel::E_CANNONLEVEL_2)
	{
		fAttackAccrues = (float)CANNON01_2_D;
		fAttackDelay = (float)CANNON01_2_D;

		fRgn = (float)CANNON01_2_R;
		fDamage = (float)CANNON01_2_A;
	}
	else if (level == CannonLevel::E_CANNONLEVEL_3)
	{
		fAttackAccrues = (float)CANNON01_3_D;
		fAttackDelay = (float)CANNON01_3_D;

		fRgn = (float)CANNON01_3_R;
		fDamage = (float)CANNON01_3_A;
	}

}
