#pragma once
#include "Component.h"
class Collider :
	public Component
{
public:
	RECT coll;

	int Width;
	int Height;

	bool bCenter;
public:
	Collider();
	virtual ~Collider();

	virtual void Start()			override;
	virtual void Release()			override;
	virtual void Update(float Et)	override;
	
	
public:
	void SetCollider(int _Width, int _Height, bool _bCenter = true);
public:
	const RECT & GetRect() { return coll; }
public:
	void SendCollider(Collider * collider);
};

