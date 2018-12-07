#include "DXUT.h"
#include "MBullet.h"
#include "Hac.h"
#include"Effect.h"

MBullet::MBullet()
{
}


MBullet::~MBullet()
{
}

void MBullet::Init()
{
	renderer = AC(Renderer);
	renderer->SetTexture(IMAGE.AddTexture("eb", "./rs/png/eb.png"));
	renderer->SetMidCenter();

	collider = AC(Collider);
	collider->SetCollider(30, 30);
	
	fSpeed = 200;
	iRenderingSort = INGAME02;
}

void MBullet::Update(float Et)
{
	tf->pos += vDir * (fSpeed * Et);
}

void MBullet::OnCollider(Collider * coll)
{
	if (coll->GetObj()->sTag == "Hac")
	{
		Hac * hac = (Hac*)coll->GetObj();
		hac->HitBullet(fDamage);

		GameObject * object = OBJECT.AddObject(new GameObject, tf->pos);
		object->AC(Effect)->SetEffect("HacEffect%d", 1, 5, 0.05f);
		object->tf->size = Vector2(1.5f, 1.5f);
		Destroy(this);
	}
}

void MBullet::SetMBullet(Vector2 startPos, Vector2 endPos)
{
	tf->pos = startPos;
	
	vDir = endPos - startPos;
	D3DXVec2Normalize(&vDir, &vDir);
}
