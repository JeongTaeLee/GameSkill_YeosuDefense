#pragma once
#include "cBullet.h"
class MBullet :
	public cBullet
{
private:
	Vector2 vDir;

	float fSpeed;
public:
	MBullet();
	virtual ~MBullet();
	
	virtual void Init()	override;
	virtual void Update(float Et)	override;

	virtual void OnCollider(Collider *coll) override;
	
	void SetMBullet(Vector2 startPos, Vector2 endPos);
};

