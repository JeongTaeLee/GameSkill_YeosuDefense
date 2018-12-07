#include "DXUT.h"
#include "Slow.h"
#include "Monster.h"
#include"Effect.h"

Slow::Slow()
{

}


Slow::~Slow()
{
}

void Slow::Init()
{
	renderer = AC(Renderer);
	renderer->SetTexture(IMAGE.AddTexture("Slow", "./rs/png/Slow.png"));
	renderer->SetMidCenter();
	iRenderingSort = UI02;

	tf->pos = INPUT.GetScrollPos();

	Rgn = 250;

	fDelay = 0.5f;
	fAccrue = 0.f;

}

void Slow::Update(float Et)
{
	tf->pos = INPUT.GetScrollPos();

	fAccrue += Et;

	if (fDelay < fAccrue)
	{
		if (KEYDOWN(VK_LBUTTON))
			StartSkill();
	}
}

void Slow::StartSkill()
{
	for (auto Iter : OBJECT.GetLists())
	{
		if (Iter->sTag == "Monster")
		{
			Vector2 vLength = Iter->tf->pos - tf->pos;
			float fLength = D3DXVec2Length(&vLength);

			if (fLength < Rgn)
			{
				Monster * mon = (Monster*)Iter;
				mon->SetStun();
				Destroy(this);
			}
		}
	}

	GameObject * object = OBJECT.AddObject(new GameObject, Vector2(WINSIZEX / 2, WINSIZEY / 2));
	object->AC(Effect)->SetEffect("SlowEffect%d", 0, 20);
	object->GC(Renderer)->SetRenderType(D3DXSPRITE_ALPHABLEND);


}
