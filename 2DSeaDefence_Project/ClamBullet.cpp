#include "DXUT.h"
#include "ClamBullet.h"
#include "Monster.h"
#include "Effect.h"

ClamBullet::ClamBullet()
	: vStartPos(0, 0), vDestPos(0, 0), vSpeed(0, 0), g(0.f), fDestTime(0.f), fHeight(0.f), fDestHeight(0.f),
	fAccrueTime(0.f), fMaxHeight(0.f), fMaxAchieveTime(0.f), bAttackStart(false)
{
}


ClamBullet::~ClamBullet()
{
}

void ClamBullet::Init()
{
	cBullet::Init();

	animater->Add("Idle", "ClamBullet%d", " ", 0, 20);
	animater->Play("Idle");
	renderer->SetCenterPos(Vector3(50 / 2, 50 / 2, 0.f));
	collider->SetCollider(20, 20);

	iRenderingSort = INGAME02;
}

void ClamBullet::Update(float Et)
{
	fAccrueTime += Et;

	if (fAccrueTime > fDestTime)
	{
		if (bAttackStart)
		{
			Destroy(this);
			return;
		}
		else
		{
			GameObject * object = OBJECT.AddObject(new GameObject, tf->pos);
			Effect * effect = object -> AC(Effect);
			effect->SetEffect("ClamEffect%d", 1, 5, 0.05f);
		}
		bAttackStart = true;
	}

	tf->pos.x = vStartPos.x + vSpeed.x * fAccrueTime;
	tf->pos.y = (vStartPos.y - vSpeed.y * fAccrueTime + 0.5f * g * fAccrueTime * fAccrueTime);
}

void ClamBullet::PreCalculate()
{     
	fDestHeight = vStartPos.y - vDestPos.y;
	fHeight = (fMaxHeight - vDestPos.y);

	g = 2 * fHeight / (fMaxAchieveTime * fMaxAchieveTime);

	vSpeed.y = sqrt(2 * g * fHeight);

	float a = g;
	float b = -2 * vSpeed.y;
	float c = 2 * fDestHeight;

	fDestTime = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	vSpeed.x = (vDestPos.x - vStartPos.x) / fDestTime;
}

void ClamBullet::SetClamBullet(Vector2 _vStartPos, Vector2 _vDestPos, float MaxAchiveTime)
{
	tf->pos = vStartPos;

	vStartPos = _vStartPos;
	vDestPos = _vDestPos;

	fMaxAchieveTime = MaxAchiveTime;

	if (vStartPos.y < vDestPos.y)
		fMaxHeight = vDestPos.y + 100;
	else
		fMaxHeight = vStartPos.y + 100;

	PreCalculate();
}

void ClamBullet::OnCollider( Collider * coll)
{	
	if (coll->GetObj()->sTag == "Monster")
	{
		if (coll->GetObj()->GetDestroy())
			return;

		if (bAttackStart)
		{
			Monster * monster = (Monster*)coll->GetObj();
			monster->HitBullet(fDamage);
			collider->SetEnable(false);
		}
	}
}
