#include "DXUT.h"
#include "Stop.h"
#include "Monster.h"

Stop::Stop()
{
}


Stop::~Stop()
{
}

void Stop::Init()
{
	tf->pos = Vector2(WINSIZEX / 2, WINSIZEY / 2);

	renderer = AC(Renderer);
	renderer->SetTexture(IMAGE.AddTexture("SlowEffect1", " "));
	renderer->SetMidCenter();
	renderer->SetRenderType(D3DXSPRITE_ALPHABLEND);
	iRenderingSort = UI02;	

	alpha = 0;

	bDown = false;

	Delay = 1.5f;
	Accrue = 0.f;

	renderer->SetColor(D3DCOLOR_ARGB(alpha, 255, 255, 255));

	for (auto Iter : OBJECT.GetLists())
	{
		if (Iter->sTag == "Monster")
		{
			Monster * monster = (Monster*)Iter;
			monster->SetStop();
		}
	}
}

void Stop::Update(float Et)
{
	if (!bDown)
	{
		if (alpha < 255)
			alpha += 5;
		else
		{
			Accrue += Et;

			if (Accrue > Delay)
				bDown = true;
		}
	}
	else
	{
		if (alpha > 0)
			alpha -= 5;
		else
			Destroy(this);
	}



	renderer->SetColor(D3DCOLOR_ARGB(alpha, 255, 255, 255));
}
