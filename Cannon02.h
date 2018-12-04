#pragma once
#include "Cannon.h"
class Cannon02 :
	public Cannon
{
public:
	Cannon02();
	virtual ~Cannon02();

	virtual void Init()			   override;
	virtual void Attack(float Et)  override;

	virtual void Upgrade()	override;
};

