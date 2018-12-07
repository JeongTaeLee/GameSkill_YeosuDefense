#include "DXUT.h"
#include "PopScreen.h"


PopScreen::PopScreen()
{
}


PopScreen::~PopScreen()
{
}

void PopScreen::Init()
{
	renderer = AC(Renderer);
	renderer->SetRenderType(D3DXSPRITE_ALPHABLEND);
	iRenderingSort = UI02;

	tf->pos = Vector2(WINSIZEX / 2, WINSIZEY / 2);
}

void PopScreen::Update(float Et)
{
	if (KEYDOWN(VK_ESCAPE))
		Destroy(this);
}

void PopScreen::SetPopScreen(texture * tex)
{
	renderer->SetTexture(tex);
	renderer->SetMidCenter();
}
