#include "DXUT.h"
#include "Monster.h"
#include "MBullet.h"
#include "Hac.h"
#include "HpBar.h"

Monster::Monster()
	:fHp(0.f), fAtkPower(0.f), fSpeed(0.f), node(0), LookKey("RWalk"), bStun(false), bAttack(false), bAttackAni(false),
	hpBar(nullptr), iDeadGold(0), iScore(0), bStop(false)
{
	sTag = "Monster";
}


Monster::~Monster()
{
	if (hpBar)
		Destroy(hpBar);
	hpBar = nullptr;
}

void Monster::Init()
{
	renderer = AC(Renderer);
	animater = AC(Animater);
	collider = AC(Collider);

	collider->SetCollider(80, 80);
	animater->SetDelay(0.05f);
	iRenderingSort = INGAME01;

	fAttackAccrue = 0.f;
	fAttackDelay = 1.f;

	hpBar = new HpBar;
	OBJECT.AddObject(hpBar);
}

void Monster::Update(float Et)
{
	if (!bAttack)
	{
		SetLook();
		Walking(Et);
	}
	else
	{
		fAttackAccrue += Et;

		if (fAttackAccrue > fAttackDelay)
		{
			fAttackAccrue = 0.f;
			fAttackDelay = 50.f;

			bAttackAni = true;
			animater->Play("Attack");
		}

		if (bAttackAni && animater->GetIndex() == 4)
		{
			MBullet * mBullet = new MBullet;
			OBJECT.AddObject(mBullet, tf->pos);
			mBullet->SetBullet(fAtkPower);
			mBullet->SetMBullet(tf->pos, target->tf->pos);
			bAttackAni = false;
		}
	}

	if (bStun)
	{
		fStunAccrue += Et;

		if (fStunAccrue > fStunDelay)
		{
			bStun = false;
			fSpeed *= 2;
		}
	}
	if (bStop)
	{
		fStopAccrue += Et;

		if (fStopAccrue > fStopDelay)
			bStop = false;

	}

	
	hpBar->RenewBar(Vector2(tf->pos.x, tf->pos.y - 50), fHp);
}

void Monster::Receive(const string & message)
{
	if (bAttack)
	{
		if (message == "EndAnimation")
			Destroy(this);
	}
}

void Monster::Walking(float Et)
{
	if (bAttack)
		return;
	Vector2 vLength = road[node] - tf->pos;
	float length = D3DXVec2Length(&vLength);

	if (length < (fSpeed * Et))
	{
		if (road.size() - 1 != node)
			++node;
		else
		{
			bAttack = true;
			animater->Stop(0);
			return;
		}
	}

	vDir = road[node] - tf->pos;
	D3DXVec2Normalize(&vDir, &vDir);

	if (!bStop)
		tf->pos += vDir * (fSpeed * Et);
}

void Monster::SetLook()
{
	Vector2 Direction = vDir;
	D3DXVec2Normalize(&Direction, &Direction);

	float angle = D3DXToDegree(atan2f(Direction.y, Direction.x));

	string str;

	if (0.f < angle && angle <= 22.5f)
		str = "RWalk";
	else if (22.5f < angle && angle <= 67.5f)
		str = "DRWalk";
	else if (67.5f < angle && angle <= 112.5f)
		str = "DWalk";
	else if (112.5f < angle && angle <= 157.5f)
		str = "DLWalk";
	else if (157.5f < angle && angle <= 180.f)
		str = "LWalk";
	else if (-180 < angle && angle <= -157.5f)
		str = "LWalk";
	else if (-157.5f < angle && angle <= -112.5f)
		str = "ULWalk";
	else if (-112.5f < angle && angle <= -67.5f)
		str = "UWalk";
	else if (-67.5f < angle && angle <= -22.5f)
		str = "URWalk";
	else if (-22.5f < angle && angle <= 0.f)
		str = "RWalk";


	if (str != LookKey)
	{
		LookKey = str;
		animater->Play(LookKey);
	}
}

void Monster::Attack(float Et)
{
	if (bAttackAni)
		return;

	bAttackAni = true;	
	animater->Play("Attack");
}

void Monster::SetInitRoad()
{
	tf->pos = road[0];
	++node;

	hpBar->SetHpBar(IMAGE.AddTexture("Mob_OutBar", "./rs/png/A/Mob1.png"), IMAGE.AddTexture("Mob_InBar", "./rs/png/A/Mob2.png"), fHp);
	hpBar->RenewBar(Vector2(tf->pos.x, tf->pos.y - 50), fHp);
}

void Monster::SetStun()
{
	if (!bStun)
	{
		bStun = true;
		fSpeed = fSpeed / 2.f;
	
		fStunAccrue = 0.f;
		fStunDelay = 8.f;
	}
}

void Monster::SetStop()
{
	if (!bStop)
	{
		bStop = true;

		fStopAccrue = 0.f;
		fStopDelay = 8.f;
	}
}

void Monster::AddAni(cstr aniKey, cstr keys, cstr paths, int mn, int mx)
{
	animater->Add(aniKey, keys, paths, mn, mx);
	animater->Play(aniKey);
}

void Monster::HitBullet(float fDamage)
{
	fHp -= fDamage;
	
	if (fHp <= 0)
	{
		fHp = 0;
		INGAME.AddGold(iDeadGold);
		INGAME.AddScore(iScore);
		Destroy(this);
	}
}

void Monster::PickStartNode(const vector<Vector2> & _road, Vector2 & pos, int Node)
{
	road = _road;
	node = Node;
	tf->pos = pos;

	hpBar->SetHpBar(IMAGE.AddTexture("Mob_OutBar", "./rs/png/A/Mob1.png"), IMAGE.AddTexture("Mob_InBar", "./rs/png/A/Mob2.png"), fHp );
	hpBar->RenewBar(Vector2(tf->pos.x, tf->pos.y - 50), fHp);
}


