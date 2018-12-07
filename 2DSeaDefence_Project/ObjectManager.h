#pragma once
#include "singleton.h"

class GameObject;
class Collider;

class ObjectManager :
	public singleton<ObjectManager>
{
private:
	list<GameObject*>  objects;

	list<Collider*> colliders;

public:
	ObjectManager();
	virtual ~ObjectManager();

	void Reset();

	GameObject * AddObject(GameObject * obj, Vector2 pos = Vector2(0, 0));
	void AddCollider(Collider * collider);
	void DeleteCollider(Collider * collider);
	
	void Update(float Et);
	void Render(LPD3DXSPRITE sprite);

	void DestroyCheck();
	void ColliderCheck();

	list<GameObject*>& GetLists() {
		return objects
			;
	}
};

#define OBJECT ObjectManager::GetInst()