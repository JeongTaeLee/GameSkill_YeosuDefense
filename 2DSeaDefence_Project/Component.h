#pragma once

class GameObject;

class Component
{
protected:
	GameObject * gameObject;

	bool bEnable;
public:
	Component();
	virtual ~Component();

	virtual void Release() {}

	virtual void Start() {}
	virtual void Update(float Et) {}
	virtual void Render(LPD3DXSPRITE sprite) {}
public:
	virtual void OnCollider(Collider * collider) {}
public:
	GameObject * GetObj() { return gameObject; }
	bool GetEnable() { return bEnable; }
public:
	void SetObject(GameObject * object) { gameObject = object; }
	void SetEnable(bool _bEnable) { bEnable = _bEnable; }
public:
	virtual void Receive(cstr message) {}
	virtual void Send(cstr message) final;
};

