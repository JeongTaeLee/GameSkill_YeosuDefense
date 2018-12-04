#include "DXUT.h"
#include "Boss.h"
#include "HpBar.h"

Boss::Boss()
	:eBossState(E_WALK), fCreateAccrue(0.0f), fCreateDelay(3.f), bBossAttack(false), bMobCreate(false)
{
}


Boss::~Boss()
{
}

void Boss::Init()
{
	Monster::Init();

	animater->Add("DWalk", "Boss_DWalk%d", " ", 1, 10);
	animater->Add("DLWalk", "Boss_DLWalk%d", " ", 1, 10);
	animater->Add("LWalk", "Boss_LWalk%d", " ", 1, 10);
	animater->Add("ULWalk", "Boss_ULWalk%d", " ", 1, 10);
	animater->Add("UWalk", "Boss_UWalk%d", " ", 1, 10);
	animater->Add("URWalk", "Boss_URWalk%d", " ", 1, 10);
	animater->Add("RWalk", "Boss_RWalk%d", " ", 1, 10);
	animater->Add("DRWalk", "Boss_DRWalk%d", " ", 1, 10);

	animater->Add("DWalkA", "BossA_DWalk%d", " ", 1, 10);
	animater->Add("DLWalkA", "BossA_DLWalk%d", " ", 1, 10);
	animater->Add("LWalkA", "BossA_LWalk%d", " ", 1, 10);
	animater->Add("ULWalkA", "BossA_ULWalk%d", " ", 1, 10);
	animater->Add("UWalkA", "BossA_UWalk%d", " ", 1, 10);
	animater->Add("URWalkA", "BossA_URWalk%d", " ", 1, 10);
	animater->Add("RWalkA", "BossA_RWalk%d", " ", 1, 10);
	animater->Add("DRWalkA", "BossA_DRWalk%d", " ", 1, 10);

	animater->Play("RWalk");
	renderer->SetMidCenter();

	SetSpeed(BOSS_S);
	SetHp(BOSS_H);
	SetAp(BOSS_A);

	fAttackDelay = 13.f;
	fAttackAccrue = 0.f;
}

void Boss::Update(float Et)
{
	switch (eBossState)
	{
	case E_WALK:
		SetLook();
		Walking(Et);

		fAttackAccrue += Et;

		if (fAttackAccrue > fAttackDelay)
		{
			fAttackAccrue = 0.f;
			
			fCreateAccrue = 2.f;
			fCreateDelay = 2.f;
			count = 0;

			eBossState = E_ATTACK;
		}
		break;
	case E_ATTACK:	
		if (bBossAttack)
			break; 
			
		fCreateAccrue += Et;
		if (fCreateAccrue > fCreateDelay)
		{
			fCreateAccrue = 0;

			if (count < 3)
			{
				++count;
				
				string key	= animater->GetNowString() + "A";
				LookKey		= key;
				animater->Play(key);
			
				bBossAttack = true;
			}
			else
			{
				eBossState = E_WALK;
				SetLook();
				animater->Play(animater->GetNowString());
			}
		}
		break;

	default:
		break;
	}

	if (bBossAttack)
	{
		if (animater->GetIndex() == 4 && !bMobCreate)
		{
			bMobCreate = true;

			MonsterType m = (MonsterType)GetRandomNumber((int)E_MOB01, (int)E_MOB04);

			CreateMonster(m);
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

	hpBar->RenewBar(Vector2(tf->pos.x, tf->pos.y - 70), fHp);
}

void Boss::SetInitRoad()
{
	tf->pos = road[0];
	++node;

	hpBar->SetHpBar(IMAGE.AddTexture("Boss_OutBar", "./rs/png/A/Boss1.png"), IMAGE.AddTexture("Boss_InBar", "./rs/png/A/Boss2.png"), fHp);
	hpBar->RenewBar(Vector2(tf->pos.x, tf->pos.y - 70), fHp);
}

void Boss::Receive(cstr message)
{
	if (bBossAttack)
	{
		if (message == "EndAnimation")
		{
			bBossAttack = false;
			bMobCreate = false;
			SetLook();
			animater->Stop(0);
		}
	}
}


void Boss::CreateMonster(MonsterType mobType)
{
	Monster * monster = new Monster;
	OBJECT.AddObject(monster);
	

	switch (mobType)
	{
	case E_MOB01:
		monster->AddAni("DWalk", "Mob01_DWalk%d", " ", 1, 10);
		monster->AddAni("DLWalk", "Mob01_DLWalk%d", " ", 1, 10);
		monster->AddAni("LWalk", "Mob01_LWalk%d", " ", 1, 10);
		monster->AddAni("ULWalk", "Mob01_ULWalk%d", " ", 1, 10);
		monster->AddAni("UWalk", "Mob01_UWalk%d", " ", 1, 10);
		monster->AddAni("URWalk", "Mob01_URWalk%d", " ", 1, 10);
		monster->AddAni("RWalk", "Mob01_RWalk%d", " ", 1, 10);
		monster->AddAni("DRWalk", "Mob01_DRWalk%d", " ", 1, 10);
		monster->AddAni("Attack", "Mob01_Attack%d", " ", 1, 10);

		monster->GC(Renderer)->SetCenterPos(Vector3(140.f / 2.f, 140.f / 2.f, 0.f));
		monster->GC(Animater)->Play("RWalk");

		monster->SetSpeed((float)MOB01_S);
		monster->SetHp((float)MOB01_H);
		monster->SetAp((float)MOB01_A);
		monster->SetDeadGold(MOB01_G);
		monster->SetScore(MOB01_SC);


		monster->SetHac(target);

		monster->PickStartNode(road, tf->pos, node);
		break;
	case E_MOB02:
		monster->AddAni("DWalk", "Mob02_DWalk%d", " ", 1, 10);
		monster->AddAni("DLWalk", "Mob02_DLWalk%d", " ", 1, 10);
		monster->AddAni("LWalk", "Mob02_LWalk%d", " ", 1, 10);
		monster->AddAni("ULWalk", "Mob02_ULWalk%d", " ", 1, 10);
		monster->AddAni("UWalk", "Mob02_UWalk%d", " ", 1, 10);
		monster->AddAni("URWalk", "Mob02_URWalk%d", " ", 1, 10);
		monster->AddAni("RWalk", "Mob02_RWalk%d", " ", 1, 10);
		monster->AddAni("DRWalk", "Mob02_DRWalk%d", " ", 1, 10);
		monster->AddAni("Attack", "Mob02_Attack%d", " ", 1, 10);


		monster->GC(Renderer)->SetCenterPos(Vector3(140.f / 2.f, 140.f / 2.f, 0.f));
		monster->GC(Animater)->Play("RWalk");

		monster->SetSpeed((float)MOB02_S);
		monster->SetHp((float)MOB02_H);
		monster->SetAp((float)MOB02_A);
		monster->SetDeadGold(MOB02_G);
		monster->SetScore(MOB02_SC);


		monster->SetHac(target);

		monster->PickStartNode(road, tf->pos, node);

		break;
	case E_MOB03:
		monster->AddAni("DWalk", "Mob03_DWalk%d", " ", 1, 10);
		monster->AddAni("DLWalk", "Mob03_DLWalk%d", " ", 1, 10);
		monster->AddAni("LWalk", "Mob03_LWalk%d", " ", 1, 10);
		monster->AddAni("ULWalk", "Mob03_ULWalk%d", " ", 1, 10);
		monster->AddAni("UWalk", "Mob03_UWalk%d", " ", 1, 10);
		monster->AddAni("URWalk", "Mob03_URWalk%d", " ", 1, 10);
		monster->AddAni("RWalk", "Mob03_RWalk%d", " ", 1, 10);
		monster->AddAni("DRWalk", "Mob03_DRWalk%d", " ", 1, 10);
		monster->AddAni("Attack", "Mob03_Attack%d", " ", 1, 10);

		monster->GC(Renderer)->SetCenterPos(Vector3(140.f / 2.f, 140.f / 2.f, 0.f));
		monster->GC(Animater)->Play("RWalk");

		monster->SetSpeed((float)MOB03_S);
		monster->SetHp((float)MOB03_H);
		monster->SetAp((float)MOB03_A);
		monster->SetDeadGold(MOB03_G);
		monster->SetScore(MOB03_SC);


		monster->SetHac(target);

		monster->PickStartNode(road, tf->pos, node);
		break;
	case E_MOB04:
		monster->AddAni("DWalk", "Mob04_DWalk%d", " ", 1, 10);
		monster->AddAni("DLWalk", "Mob04_DLWalk%d", " ", 1, 10);
		monster->AddAni("LWalk", "Mob04_LWalk%d", " ", 1, 10);
		monster->AddAni("ULWalk", "Mob04_ULWalk%d", " ", 1, 10);
		monster->AddAni("UWalk", "Mob04_UWalk%d", " ", 1, 10);
		monster->AddAni("URWalk", "Mob04_URWalk%d", " ", 1, 10);
		monster->AddAni("RWalk", "Mob04_RWalk%d", " ", 1, 10);
		monster->AddAni("DRWalk", "Mob04_DRWalk%d", " ", 1, 10);
		monster->AddAni("Attack", "Mob04_Attack%d", " ", 1, 10);

		monster->GC(Renderer)->SetCenterPos(Vector3(140.f / 2.f, 140.f / 2.f, 0.f));
		monster->GC(Animater)->Play("RWalk");

		monster->SetSpeed((float)MOB04_S);
		monster->SetHp((float)MOB04_H);
		monster->SetAp((float)MOB04_A);
		monster->SetDeadGold(MOB04_G);
		monster->SetScore(MOB04_SC);


		monster->SetHac(target);

		monster->PickStartNode(road, tf->pos, node);
		break;
	default:
		break;
	}
}

