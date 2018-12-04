#pragma once
#include "Cannon.h"
class Cannon01 :
	public Cannon
{
public:
	Cannon01();
	virtual ~Cannon01();

	virtual void Init()			   override;
	virtual void Attack(float Et)  override;

	virtual void Upgrade()	override;
};

