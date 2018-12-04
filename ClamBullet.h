#pragma once
#include "cBullet.h"
class ClamBullet :
	public cBullet
{
private:
	Vector2 vStartPos;
	Vector2 vDestPos;

	Vector2 vSpeed;

	float g; 

	float fDestTime; 
	float fHeight;
	float fDestHeight; 

	float fAccrueTime;	

	float fMaxHeight;		
	float fMaxAchieveTime;

	bool  bAttackStart;
public:
	ClamBullet();
	virtual ~ClamBullet();

	virtual void Init()	override;
	virtual void Update(float Et)	override;

	void PreCalculate();
	void SetClamBullet(Vector2 _vStartPos, Vector2 _vDestPos, float MaxAchiveTime);

public:
	virtual void OnCollider( Collider * collider);
};

