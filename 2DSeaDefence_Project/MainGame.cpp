#include "DXUT.h"
#include "MainGame.h"
#include "Ingame.h"
#include "LoadScene.h"

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}

void MainGame::Init()
{
	D3DXCreateSprite(g_device, &sprite);

	SCENE.AddScene("Ingame", new Ingame);
	SCENE.AddScene("Load", new LoadScene);
	SCENE.ChanScene("Load");
}

void MainGame::Release()
{
	SAFE_RELEASE(sprite);

	ImageManager::ReleaseInst();
	SceneManager::ReleaseInst();
	ObjectManager::ReleaseInst();
	CameraManager::ReleaseInst();
	InputManager::ReleaseInst();
	IngameManager::ReleaseInst();
}

void MainGame::Update()
{
	INPUT.Update();
	SCENE.Update(DXUTGetElapsedTime());
}

void MainGame::Render()
{
	SCENE.Render(sprite);
}
