#include "DXUT.h"
#include "LoadingScreen.h"
#include "Button.h"
#include "PopScreen.h"

LoadingScreen::LoadingScreen()
	:bChangeScreen(false), bComplate(false)
{
}


LoadingScreen::~LoadingScreen()
{
}

void LoadingScreen::Init()
{
	renderer = AC(Renderer);
	animater = AC(Animater);

	animater->Add("Intro", "Intro%d", "./rs/png/INTRO/INTRO00%02d.png", 0, 30);
	animater->Add("Main", "MainScreen%d", "./rs/png/MAIN/MAIN00%02d.png", 0, 20);
	renderer->SetRenderType(D3DXSPRITE_ALPHABLEND);

	animater->Play("Intro");
	animater->SetDelay(0.05f);
}


void LoadingScreen::Receive(const string & message)
{
	if (message == "EndAnimation")
	{
		if (bChangeScreen && !bComplate)
		{
			bComplate = true;
			animater->Play("Main");
			
			GameObject * object = OBJECT.AddObject(new GameObject, Vector2(WINSIZEX / 2, 160));
			object->AC(Renderer)->SetTexture(IMAGE.AddTexture("Logo", "./rs/png/MAIN/A.png"));
			object->GC(Renderer)->SetRenderType(D3DXSPRITE_ALPHABLEND);
			object->GC(Renderer)->SetMidCenter();
			object->iRenderingSort = UI01;

			object = OBJECT.AddObject(new GameObject);
			Button * button = object->AC(Button);
			button->SetButton(IMAGE.AddTexture("GameStart", "./rs/png/MAIN/B1.png"),
				Vector2(WINSIZEX / 2, 400), 153, 40);
			button->SetBehavior([]() { SCENE.ChanScene("Ingame"); });
			object->iRenderingSort = UI01;

			object = OBJECT.AddObject(new GameObject);
			button = object->AC(Button);
			button->SetButton(IMAGE.AddTexture("GameAdvice", "./rs/png/MAIN/B2.png"),
				Vector2(WINSIZEX / 2, 480), 153, 40);
			button->SetBehavior([&]() { CreatePop(IMAGE.AddTexture("Advice", "./rs/png/MAIN_A/MAIND2.png")); });
			object->iRenderingSort = UI01;

			object = OBJECT.AddObject(new GameObject);
			button = object->AC(Button);
			button->SetButton(IMAGE.AddTexture("GameWay", "./rs/png/MAIN/B3.png"),
				Vector2(WINSIZEX / 2, 560), 153, 40);
			button->SetBehavior([&]() { CreatePop(IMAGE.AddTexture("Wav", "./rs/png/MAIN_A/MAIND1.png")); });
			object->iRenderingSort = UI01;

			object = OBJECT.AddObject(new GameObject);
			button = object->AC(Button);
			button->SetButton(IMAGE.AddTexture("GameExit", "./rs/png/MAIN/B4.png"),
				Vector2(WINSIZEX / 2, 640), 153, 40);
			button->SetBehavior([]() { PostQuitMessage(0); });
			object->iRenderingSort = UI01;
		}
	}
}

void LoadingScreen::SetChangeScreen()
{
	if (bChangeScreen)
		return;

	bChangeScreen = true;
}

GameObject * LoadingScreen::CreatePop(texture * tex )
{
	PopScreen * pop = new PopScreen;
	OBJECT.AddObject(pop);

	pop->SetPopScreen(tex);
	return pop;
}
