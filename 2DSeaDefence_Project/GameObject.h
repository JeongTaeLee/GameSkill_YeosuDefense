#pragma once

#include "Component.h"

class transform;

class GameObject
{
public:
	string sTag;

	transform * tf;

	int iRenderingSort;
public:
	vector<Component*> components;

	bool bDestroy;
	bool bActive;
public:
	GameObject();
	virtual ~GameObject();

	virtual void Init() {}

	void CUpdate(float Et);
	virtual void Update(float Et) {}

	void CRender(LPD3DXSPRITE sprite);
	virtual void Render(LPD3DXSPRITE sprite) {}
public:
	virtual void Send(cstr str) final;
	virtual void Receive(cstr str) {}

	virtual void OnCollider(Collider * collider) {}
	void SendCollider(Collider * collider);

	void SetActive(bool _bActive) { bActive = _bActive; };
	bool GetActive() { return bActive; }
public:
	bool GetDestroy() { return bDestroy; }
	void Destroy(GameObject* object) { object->bDestroy = true; }
public:
	template<class t>
	t * AC()
	{
		t * com = new t;
		com->SetObject(this);

		com->Start();

		components.push_back(com);

		return com;

	}
	template<class t>
	t * GC()
	{
		for (auto Iter : components)
		{
			t * com = dynamic_cast<t*>(Iter);

			if (com)
				return com;
		}
		
		return nullptr;
	}

public:
	static bool RenerSorting(GameObject * object01, GameObject * object02)
	{
		if (object01->iRenderingSort < object02->iRenderingSort)
			return true;

		return false;
	}
	static bool YSorting(GameObject * object01, GameObject * object02)
	{	
		if (object01->iRenderingSort == object02->iRenderingSort)
		{
			if (object01->tf->pos.y < object02->tf->pos.y)
				return true;
		}

		return false;
	}
};

#define AC(t) AC<t>()
#define GC(t) GC<t>()

