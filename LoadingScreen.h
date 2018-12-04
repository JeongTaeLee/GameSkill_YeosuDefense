#pragma once
#include "GameObject.h"
class LoadingScreen :
	public GameObject
{
private:
	Renderer * renderer;
	Animater * animater;

	bool bComplate;
	bool bChangeScreen;
public:
	LoadingScreen();
	virtual ~LoadingScreen();

	virtual void Init()	override;
public:
	virtual void Receive(const string & key) override;

public:
	void SetChangeScreen();
	GameObject * CreatePop(texture * tex);
};

