#include "DXUT.h"
#include "BubbleCreater.h"
#include "Bubble.h"

BubbleCreater::BubbleCreater()
	:fCreateAccrue(2.f), fCreateDelay(2.f)
{
}


BubbleCreater::~BubbleCreater()
{
}

void BubbleCreater::Init()
{
	for (int i = 0; i < 20; i++)
	{
		Bubble * bubble = new Bubble;
		OBJECT.AddObject(bubble);
		bubble->SetActive(false);
		
		Waters.push_back(bubble);
	}
}

void BubbleCreater::Update(float Et)
{
	fCreateAccrue += Et;

	if (fCreateAccrue > fCreateDelay)
	{
		fCreateAccrue = 0.f;


		Bubble * b = nullptr;
		for (auto Iter : Waters)
		{
			if (!Iter->GetActive())
				b = Iter;
		}

		if (b)
			b->SetBubble();
	}
}
