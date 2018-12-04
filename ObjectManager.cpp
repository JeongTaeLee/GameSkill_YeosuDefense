#include "DXUT.h"
#include "ObjectManager.h"
#include "GameObject.h"
#include "transform.h"
#include "Collider.h"

ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}

void ObjectManager::Reset()
{
	for (auto Iter : objects)
		SAFE_DELETE(Iter);
	objects.clear();
}

GameObject * ObjectManager::AddObject(GameObject * obj, Vector2 pos)
{
	if (obj)
	{
		obj->tf->pos = pos;
		obj->Init();
		obj->tf->Update();
	
		objects.push_back(obj);
		return obj;
	}
	return nullptr;
}

void ObjectManager::AddCollider(Collider * collider)
{
	for (auto Iter : colliders)
	{
		if (Iter == collider)
			return;
	}
	
	colliders.push_back(collider);
}

void ObjectManager::DeleteCollider(Collider * collider)
{
	for (auto Iter = colliders.begin(); Iter != colliders.end();)
	{
		if ((*Iter) == collider)
		{
			Iter = colliders.erase(Iter);
			break;
		}
		else
			++Iter;
	}
}


void ObjectManager::Update(float Et)
{
	DestroyCheck();

	for (auto Iter : objects)
	{
		if (!Iter->GetActive())
			continue;

		Iter->CUpdate(Et);
		Iter->Update(Et);
		Iter->tf->Update();
	}

	ColliderCheck();
}

void ObjectManager::Render(LPD3DXSPRITE sprite)
{
	objects.sort(GameObject::RenerSorting);
	objects.sort(GameObject::YSorting);

	for (auto Iter : objects)
	{
		if (!Iter->GetActive())
			continue;
		Iter->tf->SetTransform(sprite);
		Iter->Render(sprite);
		Iter->CRender(sprite);
	}
}

void ObjectManager::DestroyCheck()
{
	for (auto Iter = objects.begin(); Iter != objects.end();)
	{
		if ((*Iter)->GetDestroy())
		{
			SAFE_DELETE((*Iter));
			Iter = objects.erase(Iter);
		}
		else
			++Iter;
	}
}

void ObjectManager::ColliderCheck()
{
	for (auto Iter : colliders)
	{
		if (Iter->GetObj()->GetDestroy())
			continue;

		if (!Iter->GetEnable())
			continue;

		for (auto Iter02 : colliders)
		{
			if (Iter == Iter02)
				continue;
			
			if (Iter02->GetObj()->GetDestroy())
				continue;

			if (!Iter02->GetEnable())
				continue;

			RECT re;
			if (IntersectRect(&re, &Iter->GetRect(), &Iter02->GetRect()))
			{
				Iter->SendCollider(Iter02);
				Iter02->SendCollider(Iter);
			}
		}
	}
}
