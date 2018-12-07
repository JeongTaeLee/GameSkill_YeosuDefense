#pragma once
#include "singleton.h"

class Scene;

class SceneManager :
	public singleton<SceneManager>
{
private:
	map<string, Scene*> scenes;

	Scene * nowScene;
	Scene * nextScene;
public:
	SceneManager();
	virtual ~SceneManager();

	Scene * AddScene(cstr str, Scene * scene);
	Scene * ChanScene(cstr str);

	void Update(float Et);
	void Render(LPD3DXSPRITE sprite);
};

#define SCENE SceneManager::GetInst()

