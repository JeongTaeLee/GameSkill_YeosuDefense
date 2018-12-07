#pragma once
#include "Scene.h"

class LoadingScreen;

class LoadScene :
	public Scene
{
private:
	thread thread01;
	thread thread02;
	thread thread03;
	thread thread04;

	LoadingScreen * screen;

	bool bThread01;
	bool bThread02;
	bool bThread03;
	bool bThread04;

	bool CreateButton;
public:
	LoadScene();
	virtual ~LoadScene();

	virtual void Init()	override;
	virtual void Release()	override;
	virtual void Update(float Et)	override;
	virtual void Render(LPD3DXSPRITE sprite) override;

public:
	void Thread01();
	void Thread02();
	void Thread03();
	void Thread04();
};

