#include "DXUT.h"
#include "NumUI.h"


NumUI::NumUI()
{
	
}


NumUI::~NumUI()
{
}

void NumUI::Init()
{
	sprintf(GoldStr, "%06d", INGAME.GetGold());
	sprintf(MpStr, "%06d", INGAME.GetMp());
	sprintf(Score, "%06d", INGAME.GetScore());
	sprintf(WaveCount, "%d", 0);
	sprintf(WaveTime, "%02d", 60);
	

	iRenderingSort = UI02;
}

void NumUI::Update(float Et)
{
	sprintf(GoldStr, "%06d", INGAME.GetGold());
	sprintf(MpStr, "%06d", INGAME.GetMp());
	sprintf(Score, "%06d", INGAME.GetScore());

	sprintf(WaveCount, "%d", INGAME.GetNowWave());
	
	int IWaveTime = 60 - (int)INGAME.GetNowTime();
	sprintf(WaveTime, "00:%02d", IWaveTime);
}

void NumUI::Render(LPD3DXSPRITE sprite)
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	IMAGE.drawText(sprite, WaveCount, Vector2(1190, 58), 30, 10);
	IMAGE.drawText(sprite, WaveTime, Vector2(1135, 100), 40, 10);

	IMAGE.drawText(sprite, GoldStr, Vector2(1150, 270), 20, 10);
	IMAGE.drawText(sprite, MpStr, Vector2(1150, 335), 20, 10);
	IMAGE.drawText(sprite, Score, Vector2(1145,	183), 25, 20);
	sprite->End();
}
