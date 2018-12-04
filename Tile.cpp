#include "DXUT.h"
#include "Tile.h"
#include "Cannon.h"

Tile::Tile()
	:renderer(nullptr), cannon(nullptr)
{
	sTag = "Tile";
}


Tile::~Tile()
{
}

void Tile::Init()
{
	renderer = AC<Renderer>();
	renderer->SetTexture(IMAGE.AddTexture("Tile", "./rs/png/Tiles.png"));
	renderer->SetCenterPos(Vector3(80.f / 2.f, 80.f / 2.f, 0.f));
	iRenderingSort = BACKGROUND02;

	collider = AC<Collider>();
	collider->SetCollider(80, 80, true);
}

void Tile::OnCollider(Collider * otherColl)
{
	if (otherColl->GetObj()->sTag == "Cannon")
	{
		if (cannon)
			return;

		if (KEYDOWN(VK_LBUTTON))
		{
			if (PtInRect(&collider->coll, { (LONG)INPUT.GetScrollPos().x, (LONG)INPUT.GetScrollPos().y }))
			{	
				cannon = (Cannon*)otherColl->GetObj();
				cannon->InstallTile(tf->pos);
			}
		}
	}
}
