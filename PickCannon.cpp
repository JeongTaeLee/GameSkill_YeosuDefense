#include "DXUT.h"
#include "PickCannon.h"
#include "Cannon.h"
#include "Button.h"


PickCannon::PickCannon()
	:cannon(nullptr)
{
}


PickCannon::~PickCannon()
{
}

void PickCannon::Init()
{
	button = OBJECT.AddObject(new GameObject);
	button->iRenderingSort = UI02;

	Button * Cbutton = button->AC(Button);
	Cbutton->SetButton(IMAGE.AddTexture("UpgradeButton", "./rs/png/UI/UI_UPGRADE.png"), Vector2(0, 0), 153, 40);
	Cbutton->SetBehavior([]() {INGAME.UpgradeCannon(); });
	button->GC(Renderer)->SetRenderType(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
	button->SetActive(false);

}

void PickCannon::Update(float Et)
{
	Pick();
}

void PickCannon::Pick()
{
	if (KEYDOWN(VK_LBUTTON))
	{
		auto list = OBJECT.GetLists();

		bool pick = false;

		for (auto Iter : list)
		{
			if (Iter->sTag == "Cannon")
			{
				POINT pt = { INPUT.GetScrollPos().x, INPUT.GetScrollPos().y };
				
				RECT re02 = button->GC(Button)->GetRect();
				if (PtInRect(&re02, pt))
				{
					pick = true;
					return;
				}

				Cannon * temp = (Cannon*)Iter;
				if (!temp->GetInstall())
					return;

				RECT re = Iter->GC(Collider)->GetRect();
				
				if (PtInRect(&re, pt))
				{
					if (cannon)
					{
						cannon->GC(Renderer)->SetColor(OrginColor);
						cannon = nullptr;
					}

					INGAME.SetPickCannon(cannon = (Cannon*)Iter);
					cannon->GC(Renderer)->SetColor(D3DCOLOR_XRGB(150, 150, 150));

					button->tf->pos = cannon->tf->pos;
					button->tf->pos.y -= 80;
					button->SetActive(true);

					pick = true;
				}
			}
		}

		
		if (!pick)
		{
			if (cannon)
			{
				cannon->GC(Renderer)->SetColor(OrginColor);
				INGAME.SetPickCannon(cannon = nullptr);
				button->SetActive(false);
			}
			
		}
	}

}

void PickCannon::Upgrade()
{

}
