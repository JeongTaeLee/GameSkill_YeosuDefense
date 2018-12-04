#pragma once
#include "singleton.h"

class InputManager :
	public singleton<InputManager>
{
private:
	bool nowKey[256];
	bool oldKey[256];

	Vector2 vMousePos;

	
public:
	InputManager();
	virtual ~InputManager();

	void Update();
	
	bool KeyDown(int i)		{ return nowKey[i] == true && oldKey[i] == false; }
	bool KeyUp(int i)		{ return nowKey[i] == false && oldKey[i] == true; }
	bool KeyPress(int i)	{ return nowKey[i] == true && oldKey[i] == true; }

	const Vector2 & GetMousePos();
	const Vector2 & GetScrollPos();
};

#define INPUT InputManager::GetInst()

#define KEYDOWN(i) INPUT.KeyDown(i)
#define KEYUP(i) INPUT.KeyUp(i)
#define KEYPRESS(i) INPUT.KeyPress(i)

