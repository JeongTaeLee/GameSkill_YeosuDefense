#include "DXUT.h"
#include "SceneManager.h"
#include "Scene.h"

SceneManager::SceneManager()
	:nowScene(nullptr), nextScene(nullptr)
{
}


SceneManager::~SceneManager()
{
	if (nowScene)
		nowScene->Release();

	nowScene = nullptr;
	nextScene = nullptr;

	for (auto Iter : scenes)
		SAFE_DELETE(Iter.second);
	scenes.clear();
}

Scene * SceneManager::AddScene(cstr str, Scene * scene)
{
	auto find = scenes.find(str);

	if (find != scenes.end())
		return find->second;

	scenes.insert(make_pair(str, scene));
	return scene;
}

Scene * SceneManager::ChanScene(cstr str)
{
	auto find = scenes.find(str);

	if (find == scenes.end())
		return nullptr;

	nextScene = find->second;
	return nextScene;
}

void SceneManager::Update(float Et)
{
	if (nextScene)
	{
		if (nowScene)
		{
			nowScene->Release();
			nowScene = nullptr;
		}
		nextScene->Init();
		nowScene = nextScene;
		nextScene = nullptr;
	}
	if (nowScene)
		nowScene->Update(Et);
}

void SceneManager::Render(LPD3DXSPRITE sprite)
{
	if (nowScene)
		nowScene->Render(sprite);
}
