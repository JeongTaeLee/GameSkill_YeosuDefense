#pragma once
class MainGame
{
private:
	LPD3DXSPRITE sprite;
public:
	MainGame();
	virtual ~MainGame();

	void Init();
	void Release();
	void Update();
	void Render();

	void LostDevice() { sprite->OnLostDevice(); }
	void ResetDevice() { sprite->OnResetDevice(); }
};

