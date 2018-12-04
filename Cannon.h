#pragma once
#include "GameObject.h"

class Monster;

enum CannonLevel
{
	E_CANNONLEVEL_1,
	E_CANNONLEVEL_2,
	E_CANNONLEVEL_3,
};

class Cannon :
	public GameObject
{
protected:
	Monster * monster;
	
	Renderer * renderer;
	Animater * animater;
	Collider * collider;

	CannonLevel level;

	bool bInstall;

	float fRgn;

	float fAttackDelay;
	float fAttackAccrues;
	float fDamage;

	int fAttackIndex;

	bool bAttack;

	int iUpgradeCost;
public:
	Cannon();
	virtual ~Cannon();

	virtual void Init()	override;
	virtual void Update(float Et) override;
public:
	virtual void Receive(cstr str) override;

public:
	void InstallTile(const Vector2 &vec);
	
	void Targetidng();
	virtual void Attack(float Et) PURE;

	virtual void Upgrade() PURE;
	void LevelUp();
public:
	void AddAni(cstr aniKey, cstr key, cstr path, int mn, int mx);
	void SetDelay(float d);
	void Play(cstr aniKey);

public:
	bool GetInstall() { return bInstall; }
};
