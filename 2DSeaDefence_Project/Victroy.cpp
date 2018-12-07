#include "DXUT.h"
#include "Victroy.h"
#include "Button.h"

Victroy::Victroy()
	:bButton(false)
{
}


Victroy::~Victroy()
{
}

void Victroy::Init()
{
	renderer = AC(Renderer);
	renderer->SetTexture(IMAGE.AddTexture("Victory","./rs/png/UI2/VICTORY.png"));

	iAlpha = 0;
	renderer->SetColor(D3DCOLOR_ARGB(iAlpha, 255, 255, 255));
	renderer->SetRenderType(D3DXSPRITE_ALPHABLEND);

	iRenderingSort = UI02;
}

void Victroy::Update(float Et)
{
	if (bButton)
		return;

	if (iAlpha < 255)
	{
		iAlpha += 3;
		renderer->SetColor(D3DCOLOR_ARGB(iAlpha, 255, 255, 255));
	}
	else
	{
		GameObject * object = OBJECT.AddObject(new GameObject);
		Button * button = object->AC(Button);
		button->SetButton(IMAGE.AddTexture("NEXT_STAGE", "./rs/png/UI2/NEXT_STAGE.png"),
			Vector2(WINSIZEX / 2, 450), 153, 40);
		button->SetBehavior([]() { INGAME.NextStage(); });
		object->iRenderingSort = UI02;
		bButton = true;
	}
}
