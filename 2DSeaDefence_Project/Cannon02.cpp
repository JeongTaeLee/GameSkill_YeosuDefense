#include "DXUT.h"
#include "Cannon02.h"
#include "ClamBullet.h"
#include "Monster.h"
#include "LBullet.h"
#include"Effect.h"

Cannon02::Cannon02()
{
}


Cannon02::~Cannon02()
{
}

void Cannon02::Init()
{
	Cannon::Init();
	animater->Add("Attack1", "Cannon02_01_%d", " ", 1, 20);
	animater->Add("Attack2", "Cannon02_02_%d", " ", 1, 20);
	animater->Add("Attack3", "Cannon02_03_%d", " ", 1, 20);
	animater->Play("Attack1");
	animater->Stop(0);
	animater->SetDelay(0.02f);
	renderer->SetCenterPos(Vector3(140.f / 2.f, 140.f / 2.f + 10, 0.f));

	fAttackAccrues = (float)CANNON02_D;
	fAttackDelay = (float)CANNON02_D;

	fRgn = (float)CANNON02_R;
	fDamage = (float)CANNON02_A;

	fAttackIndex = 5;

	iUpgradeCost = 400;
}

void Cannon02::Attack(float Et)
{
	Vector2 vStart = tf->pos;
	vStart.y -= 10;
	
	Vector2 vDir = monster->tf -> pos - vStart;
	D3DXVec2Normalize(&vDir, &vDir);

	Vector2 vLength = monster->tf->pos - vStart;
	float fLength = D3DXVec2Length(&vLength);
	float fBulletLength = sqrt(20 + 20);

	int count = fLength / fBulletLength - 1;
	
	for (int i = 0; i < count; ++i)
	{
		Vector2 Pos = vStart + vDir * fBulletLength * i;

		LBullet * bullet = new LBullet;
		OBJECT.AddObject(bullet);
		bullet->tf->pos = Pos;
		bullet->tf->rot = atan2f(vDir.y, vDir.x);
	}
	
	SOUND.Play("LEffect");

	monster->SetStun();
	monster->HitBullet(fDamage);

	GameObject * object = OBJECT.AddObject(new GameObject, vStart);
	object->AC(Effect)->SetEffect("LFireEffect%d", 1, 3, 0.09);
	
	object = OBJECT.AddObject(new GameObject, vStart + vDir * fBulletLength * (count));
	object->AC(Effect)->SetEffect("LHitEffect%d", 1, 3, 0.09);

}

void Cannon02::Upgrade()
{
	LevelUp();

	if (level == CannonLevel::E_CANNONLEVEL_2)
	{
		fAttackAccrues = (float)CANNON02_2_D;
		fAttackDelay = (float)CANNON02_2_D;

		fRgn = (float)CANNON02_2_R;
		fDamage = (float)CANNON02_2_A;
	}
	else if (level == CannonLevel::E_CANNONLEVEL_3)
	{
		fAttackAccrues = (float)CANNON02_3_D;
		fAttackDelay = (float)CANNON02_3_D;

		fRgn = (float)CANNON02_3_R;
		fDamage = (float)CANNON02_3_A;
	}
}
