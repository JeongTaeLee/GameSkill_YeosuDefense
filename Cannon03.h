#pragma once
#include "Cannon.h"
class Cannon03 :
	public Cannon
{
public:
	Cannon03();
	virtual ~Cannon03();

	virtual void Init()			   override;
	virtual void Attack(float Et)  override;

	virtual void Upgrade()	override;
};

