#include "DXUT.h"
#include "Collider.h"


Collider::Collider()
	:coll({ 0, 0, 0, 0 }), Width(0), Height(0), bCenter(true)
{
}


Collider::~Collider()
{
}

void Collider::Start()
{
	OBJECT.AddCollider(this);
}

void Collider::Release()
{
	OBJECT.DeleteCollider(this);
}

void Collider::Update(float Et)
{
	Vector2 pos = gameObject->tf->worldPos;

	if (bCenter)
	{
		SetRect(&coll,
			pos.x - (float)Width / 2.f,
			pos.y - (float)Height / 2.f,
			pos.x + (float)Width / 2.f,
			pos.y + (float)Height / 2.f);
	}
	else
	{
		SetRect(&coll,
			pos.x,
			pos.y,
			pos.x + Width,
			pos.y + Height);
	}
}

void Collider::SetCollider(int _Width, int _Height, bool _bCenter)
{
	Width = _Width;
	Height = _Height;
	bCenter = _bCenter;

	Vector2 pos = gameObject->tf->worldPos;

	if (bCenter)
	{
		SetRect(&coll,
			pos.x - (float)Width / 2.f,
			pos.y - (float)Height / 2.f,
			pos.x + (float)Width / 2.f,
			pos.y + (float)Height / 2.f);
	}
	else
	{
		SetRect(&coll,
			pos.x,
			pos.y,
			pos.x + Width,
			pos.y + Height);
	}
}

void Collider::SendCollider(Collider * collider)
{
	gameObject->SendCollider(collider);
}
