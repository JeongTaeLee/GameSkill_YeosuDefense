#include "DXUT.h"
#include "Cannon.h"
#include "Monster.h"

Cannon::Cannon()
	:bInstall(false), monster(nullptr), fRgn(0.f), fAttackDelay(0.f), fAttackAccrues(0.f), fDamage(0.f), bAttack(false), level(E_CANNONLEVEL_1)
	, iUpgradeCost(0)
{
	sTag = "Cannon";
	iRenderingSort = INGAME01;
}


Cannon::~Cannon()
{
}

void Cannon::Init()
{
	renderer = AC<Renderer>();
	collider = AC<Collider>();
	animater = AC(Animater);

	collider->SetCollider(80, 80);
}

void Cannon::Update(float Et)
{
	if (bInstall)
	{
		string aniname; 

		switch (level)
		{
		case E_CANNONLEVEL_1:
			aniname = "Attack1";
			break;
		case E_CANNONLEVEL_2:
			aniname = "Attack2";
			break;
		case E_CANNONLEVEL_3:
			aniname = "Attack3";
			break;
		}

		Targetidng();

		if (!bAttack)
		{
			fAttackAccrues += Et;
			if (fAttackAccrues > fAttackDelay)
			{
				if (monster)
				{	
					animater->Play(aniname);
					bAttack = true;
				}
			}
		}

		if (bAttack && animater->GetIndex() == fAttackIndex)
		{
			fAttackAccrues = 0.0f;
			bAttack = false;

			if(monster)
				Attack(Et);
		}
	}
	else
		tf->pos = INPUT.GetScrollPos();
}

void Cannon::Receive(cstr str)
{
	if (str == "EndAnimation")
	{
		animater->Stop(0);
	}
}

void Cannon::InstallTile(const Vector2 &vec)
{
	tf->pos = vec;
	bInstall = true;
	INGAME.bOnCannon = false;
}

void Cannon::Targetidng()
{
	if (monster)
	{
		if (monster->GetDestroy())
			monster = nullptr;

		
		if (monster)
		{
			Vector2 Length = monster->tf->pos - tf->pos;
			float fLength = D3DXVec2Length(&Length);
	
			if (fLength > fRgn)
				monster = nullptr;
		}
	}

	if (monster)
		return;
	
	float fShortRgn = fRgn;

	for (auto Iter : OBJECT.GetLists())
	{

		if (Iter->sTag == "Monster")
		{
			Vector2 Length = Iter->tf->pos - tf->pos;	
			float fLength = D3DXVec2Length(&Length);

			if (fLength < fShortRgn)
				monster = (Monster*)Iter;

		}
	}
}

void Cannon::LevelUp()
{
	if (2 > (int)level)
	{
		if (INGAME.GetGold() >= iUpgradeCost)
		{
			INGAME.AddGold(-iUpgradeCost);
			level = (CannonLevel)((int)level + 1);
			iUpgradeCost += 100;
		}
		else
			return;
	}

	string aniname;

	switch (level)
	{
	case E_CANNONLEVEL_1:
		aniname = "Attack1";
		break;
	case E_CANNONLEVEL_2:
		aniname = "Attack2";
		break;
	case E_CANNONLEVEL_3:
		aniname = "Attack3";
		break;
	}

	animater->Play(aniname);
	animater->Stop(0);
}

void Cannon::AddAni(cstr aniKey, cstr key, cstr path, int mn, int mx)
{
	animater->Add(aniKey, key, path, mn, mx);
}

void Cannon::SetDelay(float d)
{
	animater->SetDelay(d);
}

void Cannon::Play(cstr aniKey)
{
	animater->Play(aniKey);
}
