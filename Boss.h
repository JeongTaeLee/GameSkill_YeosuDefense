#pragma once
#include "Monster.h"

enum BOSSSTATE
{
	E_WALK,
	E_ATTACK,
};

class Boss :
	public Monster
{
private:
	BOSSSTATE eBossState;

	float fCreateAccrue;
	float fCreateDelay;

	int count = 0;

	bool bBossAttack;
	bool bMobCreate;
public:
	Boss();
	virtual ~Boss();

	virtual void Init()				override;
	virtual void Update(float Et)	override;	

public:
	virtual void SetInitRoad() override;
public:
		
	virtual void Receive(cstr message) override;

	void CreateMonster(MonsterType mobType);
};

