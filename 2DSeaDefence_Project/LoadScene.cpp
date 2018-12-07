#include "DXUT.h"
#include "LoadScene.h"
#include "Button.h"
#include "LoadingScreen.h"

LoadScene::LoadScene()
	:bThread01(false), bThread02(false), bThread03(false), bThread04(false), CreateButton(false)
{
}


LoadScene::~LoadScene()
{
}

void LoadScene::Init()
{
	screen = new LoadingScreen;
	OBJECT.AddObject(screen);


	if (!INGAME.bLoadingComplete)
	{
		thread01 = thread([&]() {Thread01(); });
		thread02 = thread([&]() {Thread02(); });
		thread03 = thread([&]() {Thread03(); });
		thread04 = thread([&]() {Thread04(); });
		INGAME.bLoadingComplete = true;
	}
	else
	{
		CreateButton = true;
		screen->SetChangeScreen();
	}

	CAMERA.Update();
}

void LoadScene::Release()
{
	OBJECT.Reset();
}

void LoadScene::Update(float Et)
{
	Sleep(1);

	if (bThread01 &&
		bThread02 &&
		bThread03 &&
		bThread04 &&
		!CreateButton)
	{
		if (thread01.joinable())
			thread01.join();

		if (thread02.joinable())
			thread02.join();

		if (thread03.joinable())
			thread03.join();

		if (thread04.joinable())
			thread04.join();

		CreateButton = true;
		screen->SetChangeScreen();
	}
	
	OBJECT.Update(INGAME.GetETime());
}

void LoadScene::Render(LPD3DXSPRITE sprite)
{
	CAMERA.SetTransform();
	OBJECT.Render(sprite);
}

void LoadScene::Thread01()
{
	IMAGE.AddTextures("Cannon01_01_%d", "./rs/png/ClamCannon_A/ClamCannon_A00%02d.png", 0, 20);
	IMAGE.AddTextures("Cannon01_02_%d", "./rs/png/ClamCannon_B/ClamCannon_B00%02d.png", 0, 20);
	IMAGE.AddTextures("Cannon01_03_%d", "./rs/png/ClamCannon_C/ClamCannon_C00%02d.png", 0, 20);

	IMAGE.AddTextures("Cannon02_01_%d", "./rs/png/CoralCannon_A/CoralCannon_A00%02d.png", 0, 20);
	IMAGE.AddTextures("Cannon02_02_%d", "./rs/png/CoralCannon_B/CoralCannon_B00%02d.png", 0, 20);
	IMAGE.AddTextures("Cannon02_03_%d", "./rs/png/CoralCannon_C/CoralCannon_C00%02d.png", 0, 20);

	IMAGE.AddTextures("Cannon03_01_%d", "./rs/png/SACannon_A/SACannon_A00%02d.png", 0, 20);
	IMAGE.AddTextures("Cannon03_02_%d", "./rs/png/SACannon_B/SACannon_B00%02d.png", 0, 20);
	IMAGE.AddTextures("Cannon03_03_%d", "./rs/png/SACannon_C/SACannon_C00%02d.png", 0, 20);

	//Mob01
	IMAGE.AddTextures("Mob01_DWalk%d", "./rs/png/Mob01_Walk/MonsterA_Walk1_%d.png", 1, 10);
	IMAGE.AddTextures("Mob01_DLWalk%d", "./rs/png/Mob01_Walk/MonsterA_Walk2_%d.png", 1, 10);
	IMAGE.AddTextures("Mob01_LWalk%d", "./rs/png/Mob01_Walk/MonsterA_Walk3_%d.png", 1, 10);
	IMAGE.AddTextures("Mob01_ULWalk%d", "./rs/png/Mob01_Walk/MonsterA_Walk4_%d.png", 1, 10);
	IMAGE.AddTextures("Mob01_UWalk%d", "./rs/png/Mob01_Walk/MonsterA_Walk5_%d.png", 1, 10);
	IMAGE.AddTextures("Mob01_URWalk%d", "./rs/png/Mob01_Walk/MonsterA_Walk6_%d.png", 1, 10);
	IMAGE.AddTextures("Mob01_RWalk%d", "./rs/png/Mob01_Walk/MonsterA_Walk7_%d.png", 1, 10);
	IMAGE.AddTextures("Mob01_DRWalk%d", "./rs/png/Mob01_Walk/MonsterA_Walk8_%d.png", 1, 10);
	IMAGE.AddTextures("Mob01_Attack%d", "./rs/png/Mob01_Attack/MonsterA_Attack6_%d.png", 1, 10);

	bThread01 = true;
}

void LoadScene::Thread02()
{
	//Mob02
	IMAGE.AddTextures("Mob02_DWalk%d", "./rs/png/Mob02_Walk/MonsterB_Walk1_%d.png", 1, 10);
	IMAGE.AddTextures("Mob02_DLWalk%d", "./rs/png/Mob02_Walk/MonsterB_Walk2_%d.png", 1, 10);
	IMAGE.AddTextures("Mob02_LWalk%d", "./rs/png/Mob02_Walk/MonsterB_Walk3_%d.png", 1, 10);
	IMAGE.AddTextures("Mob02_ULWalk%d", "./rs/png/Mob02_Walk/MonsterB_Walk4_%d.png", 1, 10);
	IMAGE.AddTextures("Mob02_UWalk%d", "./rs/png/Mob02_Walk/MonsterB_Walk5_%d.png", 1, 10);
	IMAGE.AddTextures("Mob02_URWalk%d", "./rs/png/Mob02_Walk/MonsterB_Walk6_%d.png", 1, 10);
	IMAGE.AddTextures("Mob02_RWalk%d", "./rs/png/Mob02_Walk/MonsterB_Walk7_%d.png", 1, 10);
	IMAGE.AddTextures("Mob02_DRWalk%d", "./rs/png/Mob02_Walk/MonsterB_Walk8_%d.png", 1, 10);
	IMAGE.AddTextures("Mob02_Attack%d", "./rs/png/Mob02_Attack/MonsterB_Attack6_%d.png", 1, 10);

	//Mob03
	IMAGE.AddTextures("Mob03_DWalk%d", "./rs/png/Mob03_Walk/MonsterC_Walk1_%d.png", 1, 10);
	IMAGE.AddTextures("Mob03_DLWalk%d", "./rs/png/Mob03_Walk/MonsterC_Walk2_%d.png", 1, 10);
	IMAGE.AddTextures("Mob03_LWalk%d", "./rs/png/Mob03_Walk/MonsterC_Walk3_%d.png", 1, 10);
	IMAGE.AddTextures("Mob03_ULWalk%d", "./rs/png/Mob03_Walk/MonsterC_Walk4_%d.png", 1, 10);
	IMAGE.AddTextures("Mob03_UWalk%d", "./rs/png/Mob03_Walk/MonsterC_Walk5_%d.png", 1, 10);
	IMAGE.AddTextures("Mob03_URWalk%d", "./rs/png/Mob03_Walk/MonsterC_Walk6_%d.png", 1, 10);
	IMAGE.AddTextures("Mob03_RWalk%d", "./rs/png/Mob03_Walk/MonsterC_Walk7_%d.png", 1, 10);
	IMAGE.AddTextures("Mob03_DRWalk%d", "./rs/png/Mob03_Walk/MonsterC_Walk8_%d.png", 1, 10);
	IMAGE.AddTextures("Mob03_Attack%d", "./rs/png/Mob03_Attack/MonsterC_Attack6_%d.png", 1, 10);

	bThread02 = true;;
}

void LoadScene::Thread03()
{
	//Mob04
	IMAGE.AddTextures("Mob04_DWalk%d", "./rs/png/Mob04_Walk/MonsterD_Walk1_%d.png", 1, 10);
	IMAGE.AddTextures("Mob04_DLWalk%d", "./rs/png/Mob04_Walk/MonsterD_Walk2_%d.png", 1, 10);
	IMAGE.AddTextures("Mob04_LWalk%d", "./rs/png/Mob04_Walk/MonsterD_Walk3_%d.png", 1, 10);
	IMAGE.AddTextures("Mob04_ULWalk%d", "./rs/png/Mob04_Walk/MonsterD_Walk4_%d.png", 1, 10);
	IMAGE.AddTextures("Mob04_UWalk%d", "./rs/png/Mob04_Walk/MonsterD_Walk5_%d.png", 1, 10);
	IMAGE.AddTextures("Mob04_URWalk%d", "./rs/png/Mob04_Walk/MonsterD_Walk6_%d.png", 1, 10);
	IMAGE.AddTextures("Mob04_RWalk%d", "./rs/png/Mob04_Walk/MonsterD_Walk7_%d.png", 1, 10);
	IMAGE.AddTextures("Mob04_DRWalk%d", "./rs/png/Mob04_Walk/MonsterD_Walk8_%d.png", 1, 10);
	IMAGE.AddTextures("Mob04_Attack%d", "./rs/png/Mob04_Attack/MonsterD_Attack6_%d.png", 1, 10);

	//Boss
	IMAGE.AddTextures("Boss_DWalk%d", "./rs/png/Boss_Walk/BossMonster_Walk1_%d.png", 1, 10);
	IMAGE.AddTextures("Boss_DLWalk%d", "./rs/png/Boss_Walk/BossMonster_Walk2_%d.png", 1, 10);
	IMAGE.AddTextures("Boss_LWalk%d", "./rs/png/Boss_Walk/BossMonster_Walk3_%d.png", 1, 10);
	IMAGE.AddTextures("Boss_ULWalk%d", "./rs/png/Boss_Walk/BossMonster_Walk4_%d.png", 1, 10);
	IMAGE.AddTextures("Boss_UWalk%d", "./rs/png/Boss_Walk/BossMonster_Walk5_%d.png", 1, 10);
	IMAGE.AddTextures("Boss_URWalk%d", "./rs/png/Boss_Walk/BossMonster_Walk6_%d.png", 1, 10);
	IMAGE.AddTextures("Boss_RWalk%d", "./rs/png/Boss_Walk/BossMonster_Walk7_%d.png", 1, 10);
	IMAGE.AddTextures("Boss_DRWalk%d", "./rs/png/Boss_Walk/BossMonster_Walk8_%d.png", 1, 10);

	bThread03 = true;
}

void LoadScene::Thread04()
{


	IMAGE.AddTextures("BossA_DWalk%d", "./rs/png/Boss_Attack/BossMonster_Attack1_%d.png", 1, 10);
	IMAGE.AddTextures("BossA_DLWalk%d", "./rs/png/Boss_Attack/BossMonster_Attack2_%d.png", 1, 10);
	IMAGE.AddTextures("BossA_LWalk%d", "./rs/png/Boss_Attack/BossMonster_Attack3_%d.png", 1, 10);
	IMAGE.AddTextures("BossA_ULWalk%d", "./rs/png/Boss_Attack/BossMonster_Attack4_%d.png", 1, 10);
	IMAGE.AddTextures("BossA_UWalk%d", "./rs/png/Boss_Attack/BossMonster_Attack5_%d.png", 1, 10);
	IMAGE.AddTextures("BossA_URWalk%d", "./rs/png/Boss_Attack/BossMonster_Attack6_%d.png", 1, 10);
	IMAGE.AddTextures("BossA_RWalk%d", "./rs/png/Boss_Attack/BossMonster_Attack7_%d.png", 1, 10);
	IMAGE.AddTextures("BossA_DRWalk%d", "./rs/png/Boss_Attack/BossMonster_Attack8_%d.png", 1, 10);

	// ClamBullet
	IMAGE.AddTextures("ClamBullet%d", "./rs/png/ClamBullet/A00%02d.png", 0, 20);

	//Effect
	IMAGE.AddTextures("ClamEffect%d", "./rs/png/EFEECTA/Effect%d.png", 1, 5);

	//CoreEffect
	IMAGE.AddTextures("HacEffect%d", "./rs/png/EFEECTB/Effect%d.png", 1, 5);

	//LEffect
	IMAGE.AddTextures("LFireEffect%d", "./rs/png/LEffect/EffectC%d.png", 1, 3);
	IMAGE.AddTextures("LHitEffect%d", "./rs/png/LEffect/EffectB%d.png", 1, 3);

	//SlowEffect
	IMAGE.AddTextures("SlowEffect%d", "./rs/png/SLOWLY/Slowly00%02d.png", 0, 20);

	IMAGE.AddTextures("Hac%d", "./rs/png/Hac/Nexus00%02d.png", 0, 20);

	bThread04 = true;
}
