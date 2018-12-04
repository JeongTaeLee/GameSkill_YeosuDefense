#include "DXUT.h"
#include "Cannon03.h"
#include "ClamBullet.h"
#include "Monster.h"

Cannon03::Cannon03()
{
}


Cannon03::~Cannon03()
{
}

void Cannon03::Init()
{
	Cannon::Init();
	animater->Add("Attack1", "Cannon03_01_%d", " ", 1, 20);
	animater->Add("Attack2", "Cannon03_02_%d", " ", 1, 20);
	animater->Add("Attack3", "Cannon03_03_%d", " ", 1, 20);
	animater->Play("Attack1");
	animater->Stop(0);
	animater->SetDelay(0.02f);
	renderer->SetCenterPos(Vector3(140.f / 2.f, 140.f / 2.f + 10, 0.f));

	fAttackAccrues = (float)CANNON03_D;
	fAttackDelay = (float)CANNON03_D;

	fRgn = (float)CANNON03_R;
	fDamage = (float)CANNON03_A;

	fAttackIndex = 5;

	iUpgradeCost = 600;
}

void Cannon03::Attack(float Et)
{
	ClamBullet * bullet = new ClamBullet;
	OBJECT.AddObject(bullet);

	bullet->SetBullet(fDamage);
	bullet->SetClamBullet(tf->pos, monster->tf->pos, 0.3f);
}

void Cannon03::Upgrade()
{
	LevelUp();


	if (level == CannonLevel::E_CANNONLEVEL_2)
	{
		fAttackAccrues = (float)CANNON03_2_D;
		fAttackDelay = (float)CANNON03_2_D;

		fRgn = (float)CANNON03_2_R;
		fDamage = (float)CANNON03_2_A;
	}
	else if (level == CannonLevel::E_CANNONLEVEL_3)
	{
		fAttackAccrues = (float)CANNON03_3_D;
		fAttackDelay = (float)CANNON03_3_D;

		fRgn = (float)CANNON03_3_R;
		fDamage = (float)CANNON03_3_A;

	}
}
