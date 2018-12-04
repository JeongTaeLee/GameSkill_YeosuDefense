#include "DXUT.h"
#include "Hac.h"
#include "HpBar.h"

Hac::Hac()
{
}


Hac::~Hac()
{
}

void Hac::Init()
{
	sTag = "Hac";

	renderer = AC(Renderer);
	animater = AC(Animater);
	collider = AC(Collider);

	animater->Add("Idle", "Hac%d", " ", 0, 20);
	animater->Play("Idle");
	animater->SetDelay(0.08f);

	renderer->SetMidCenter();

	collider->SetCollider(100, 100);
	iRenderingSort = INGAME02;

	fHp = (float)HAC_H;

	hpBar = new HpBar;
	OBJECT.AddObject(hpBar);
	hpBar->SetHpBar(IMAGE.AddTexture("Hac_OutBar", "./rs/png/A/Core1.png"), IMAGE.AddTexture("Hac_InBar", "./rs/png/A/Core2.png"), fHp);
	hpBar->RenewBar(Vector2(tf->pos.x, tf->pos.y - 170), fHp);
}

void Hac::Update(float Et)
{
}

void Hac::HitBullet(float Damage)
{
	if (INGAME.GetGameEnd())
		return;

	fHp -= Damage;

	if (fHp <= 0)
	{
		fHp = 0.f;
		INGAME.DefeatStage();
	}

	hpBar->RenewBar(Vector2(tf->pos.x, tf->pos.y - 170), fHp);

}
