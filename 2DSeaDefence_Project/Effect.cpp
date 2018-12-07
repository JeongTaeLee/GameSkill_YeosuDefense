#include "DXUT.h"
#include "Effect.h"


Effect::Effect()
{
}


Effect::~Effect()
{
}

void Effect::Start()
{
	renderer = gameObject->AC(Renderer);
	animater = gameObject->AC(Animater);
	
	gameObject->iRenderingSort = EFFECT01;
}

void Effect::Receive(cstr message)
{
	if (message == "EndAnimation")
	{
		animater->SetEnable(false);
		gameObject->Destroy(gameObject);
	}
}

void Effect::SetEffect(cstr key, int mn, int mx, float Delay)
{
	animater->SetDelay(Delay);
	animater->Add(key, key, " ", mn, mx);
	animater->Play(key);	
	renderer->SetMidCenter();
}
