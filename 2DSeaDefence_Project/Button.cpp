#include "DXUT.h"
#include "Button.h"


Button::Button()
	:renderer(nullptr), Behavior(nullptr), alpha(255)
{
}


Button::~Button()
{
}

void Button::Start()
{
	renderer = gameObject->GC(Renderer);

	if (!renderer)
		renderer = gameObject->AC(Renderer);

	gameObject->iRenderingSort = UI01;
	renderer->SetRenderType(D3DXSPRITE_ALPHABLEND);
}

void Button::Update(float Et)
{	
	POINT mousePos;
	
	if (renderer->dwRenderType == D3DXSPRITE_ALPHABLEND)
	{	
		mousePos.x = INPUT.GetMousePos().x;
		mousePos.y = INPUT.GetMousePos().y;
	}
	else
	{
		mousePos.x = INPUT.GetScrollPos().x;
		mousePos.y = INPUT.GetScrollPos().y;
	}

	if (PtInRect(&re, mousePos))
	{
		if (alpha > 150)
			alpha -= 5;

		if (KEYDOWN(VK_LBUTTON))
			Behavior();

	}
	else
		alpha = 255;
	renderer->SetColor(D3DCOLOR_ARGB(255, alpha, alpha, alpha));

	Vector2 pos = gameObject->tf->pos;

	SetRect(&re,
		(int)pos.x - Width / 2,
		(int)pos.y - Height / 2,
		(int)pos.x + Width / 2,
		(int)pos.y + Height / 2);
}

void Button::SetButton(texture * image, const Vector2 & pos, int _Width, int _Height)
{
	renderer->SetTexture(image);

	gameObject->tf->pos = pos;

	Width = _Width;
	Height = _Height;

	SetRect(&re,
		(int)pos.x - Width / 2,
		(int)pos.y - Height / 2,
		(int)pos.x + Width / 2,
		(int)pos.y + Height / 2);

	renderer->SetCenterPos(Vector3(image->info.Width / 2, image->info.Height / 2, 0));
}

void Button::SetBehavior(function<void()> _Behavior)
{
	Behavior = _Behavior;
}
