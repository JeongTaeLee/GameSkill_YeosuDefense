#include "DXUT.h"
#include "Ingame.h"
#include "Map01.h"
#include "Button.h"
#include "PickCannon.h"
#include "NumUI.h"
#include "BubbleCreater.h"


#include "Victroy.h"

void CreateUI()
{
	GameObject * object = OBJECT.AddObject(new GameObject, Vector2(1280 - 200, 0));
	object->AC(Renderer)->SetTexture(IMAGE.AddTexture("BackUI", "./rs/png/UI/UIA.png"));
	object->GC(Renderer)->SetRenderType(D3DXSPRITE_ALPHABLEND);
	object->iRenderingSort = UI02;
	

	object = OBJECT.AddObject(new GameObject);
	Button * button = object->AC(Button);
	button->SetButton(IMAGE.AddTexture("Cannon01_Button", "./rs/png/UI/UI_TURRET1.png"),
		Vector2(1187, 560), 153, 40);
	button->SetBehavior([]() { INGAME.BuyCannon01(); });
	object->iRenderingSort = UI02;

	object = OBJECT.AddObject(new GameObject);
	button = object->AC(Button);
	button->SetButton(IMAGE.AddTexture("Cannon02_Button", "./rs/png/UI/UI_TURRET2.png"),
		Vector2(1187, 610), 153, 40);
	button->SetBehavior([]() { INGAME.BuyCannon02(); });
	object->iRenderingSort = UI02;

	object = OBJECT.AddObject(new GameObject);
	button = object->AC(Button);
	button->SetButton(IMAGE.AddTexture("Cannon03_Button", "./rs/png/UI/UI_TURRET3.png"),
		Vector2(1187, 660), 153, 40);
	button->SetBehavior([]() { INGAME.BuyCannon03(); });
	object->iRenderingSort = UI02;

	object = OBJECT.AddObject(new GameObject);
	button = object->AC(Button);
	button->SetButton(IMAGE.AddTexture("SlowSkill_Button", "./rs/png/UI/UI_SKILL1.png"),
		Vector2(1187, 425), 153, 40);
	button->SetBehavior([]() { INGAME.BuySlow(); });
	object->iRenderingSort = UI02;

	object = OBJECT.AddObject(new GameObject);
	button = object->AC(Button);
	button->SetButton(IMAGE.AddTexture("STopkill_Button", "./rs/png/UI/UI_SKILL2.png"),
		Vector2(1187, 475), 153, 40);
	button->SetBehavior([]() { INGAME.BuyStop(); });
	object->iRenderingSort = UI02;

	object = OBJECT.AddObject(new GameObject);
	button = object->AC(Button);
	button->SetButton(IMAGE.AddTexture("Stop_Button", "./rs/png/UI/UIB1.png"),
		Vector2(1157, 35), 50, 50);
	button->SetBehavior([]() { INGAME.SetStop(!INGAME.GetStop()); });
	object->iRenderingSort = UI02;

	object = OBJECT.AddObject(new GameObject);
	button = object->AC(Button);
	button->SetButton(IMAGE.AddTexture("Time_Button", "./rs/png/UI/UIB2.png"),
		Vector2(1217, 35), 50, 50);
	button->SetBehavior([]() { INGAME.SetTime(!INGAME.GetTime()); });
	object->iRenderingSort = UI02;


	object = OBJECT.AddObject(new NumUI);

	OBJECT.AddObject(new PickCannon);

	OBJECT.AddObject(new BubbleCreater());
}

Ingame::Ingame()
	:fManaAccrue(0.f), fManaDelay(5.f)
{
}


Ingame::~Ingame()
{
}

void Ingame::Init()
{

	INGAME.CreateMap();

	CreateUI();
}

void Ingame::Release()
{
	OBJECT.Reset();
}

void Ingame::Update(float Et)
{
	fManaAccrue += Et;
	if (fManaDelay < fManaAccrue)
	{
		fManaAccrue = 0.f;
		INGAME.AddMp(10);
	}

	CAMERA.Update();
	OBJECT.Update(INGAME.GetETime());
}

void Ingame::Render(LPD3DXSPRITE sprite)
{
	CAMERA.SetTransform();
	OBJECT.Render(sprite);
}
