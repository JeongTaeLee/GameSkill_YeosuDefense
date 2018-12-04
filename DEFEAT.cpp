#include "DXUT.h"
#include "DEFEAT.h"
#include "Button.h"

DEFEAT::DEFEAT()
	:bButton(false)
{
}


DEFEAT::~DEFEAT()
{
}

void DEFEAT::Init()
{
	renderer = AC(Renderer);
	renderer->SetTexture(IMAGE.AddTexture("Defeat", "./rs/png/UI2/DEFEAT.png"));

	iAlpha = 0;
	renderer->SetColor(D3DCOLOR_ARGB(iAlpha, 255, 255, 255));
	renderer->SetRenderType(D3DXSPRITE_ALPHABLEND);

	iRenderingSort = UI02;
}

void DEFEAT::Update(float Et)
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
		button->SetButton(IMAGE.AddTexture("CONTINUE", "./rs/png/UI2/CONTINUE.png"),
			Vector2(WINSIZEX / 2, 450), 153, 40);
		button->SetBehavior([]() { INGAME.ContinueStage(); });
		object->iRenderingSort = UI02;
		bButton = true;
	}
}
