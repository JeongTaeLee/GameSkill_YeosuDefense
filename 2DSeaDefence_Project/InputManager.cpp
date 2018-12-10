#include "DXUT.h"
#include "InputManager.h"


InputManager::InputManager()
	:vMousePos(0.f, 0.f)
{
	memset(nowKey, false, sizeof(bool) * 256);
	memset(oldKey, false, sizeof(bool) * 256);
}


InputManager::~InputManager()
{
}

void InputManager::Update()
{
	memcpy(oldKey, nowKey, sizeof(bool) * 256);
	memset(nowKey, false, sizeof(bool) * 256);

	for (int i = 0; i < 256; ++i)
		nowKey[i] = GetAsyncKeyState(i);
}

const Vector2 InputManager::GetMousePos()
{
	POINT p = { 0 };
	GetCursorPos(&p);
	ScreenToClient(DXUTGetHWND(), &p);

	return Vector2((float)p.x, (float)p.y);
}

const Vector2 InputManager::GetScrollPos()
{
	Vector2 mousePos = GetMousePos();

	mousePos -= CAMERA.GetScoll();
	return mousePos;
}
