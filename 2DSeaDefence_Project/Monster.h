#pragma once
#include "GameObject.h"



class Hac;
class HpBar;

enum MonsterType
{
	E_MOB01,
	E_MOB02,
	E_MOB03,
	E_MOB04,
	E_BOSS,
};

class Monster :
	public GameObject
{
protected:
	Renderer * renderer;
	Animater * animater;
	Collider * collider;

	HpBar * hpBar;

	vector<Vector2> road;

	Vector2 vDir;
	int node;
	string LookKey;

	float fHp;
	
	float fAtkPower;
	float fSpeed;

	bool bAttack;
	bool bAttackAni;

	float fAttackAccrue;
	float fAttackDelay;

	bool bStun;
	float fStunAccrue;
	float fStunDelay;

	bool bStop;
	float fStopAccrue;
	float fStopDelay;

	int iDeadGold;
	int iScore;

	Hac * target;
public:
	Monster();
	virtual ~Monster();

	virtual void Init() override;
	virtual void Update(float Et) override;
	
public:
	virtual void Receive(const string & message) override;
public:
	void Walking(float Et);
	void SetLook();

	virtual void Attack(float Et);

public:
	void SetHp(float _fHp) { fHp = _fHp; }
	void SetAp(float f) { fAtkPower = f; }
	void SetSpeed(float _fSpeed) { fSpeed = _fSpeed; }
	void SetDeadGold(int i) { iDeadGold = i; }
	void SetScore(int i) { iScore = i; }

	virtual void SetInitRoad();
	
	void SetStun();
	void SetStop();

	void SetHac(Hac * hac) { target = hac; }

	void AddAni(cstr aniKey, cstr keys, cstr paths, int mn, int mx);
public:
	void HitBullet(float fDamage);
	void PickStartNode(const vector<Vector2> & road, Vector2 & pos, int Node);
public:
	vector<Vector2> & GetRoad() { return road; }
};

