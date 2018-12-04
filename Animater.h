#pragma once
#include "Component.h"
class Animater :
	public Component
{
private:
	Renderer * renderer;

	map<string, vector<texture*> *> anis;
	
	string	sNowAni;
	vector<texture*> * vNowAni;

	int count;
	int amount;

	float Delay;
	float Accrue;

	bool bStop;
public:
	Animater();
	virtual ~Animater();

public:
	void Add(cstr aniKey, cstr imagekey, cstr paths, int mn, int mx);
	void Play(cstr aniKey);
	void Stop(int m);

	virtual void Start()	override;
	virtual void Release()	override;
	virtual void Update(float Et)	override;	

public:
	int GetIndex() { return count; }

	string GetNowString() { return sNowAni; }
public:
	void SetDelay(float _Delay) { Delay = _Delay; }
};

