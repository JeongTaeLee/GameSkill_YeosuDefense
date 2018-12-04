#include "DXUT.h"
#include "GameObject.h"
#include "transform.h"

GameObject::GameObject()
	:bDestroy(false), iRenderingSort(0), bActive(true)
{
	tf = new transform;
	components.push_back(tf);
}


GameObject::~GameObject()
{
	for (auto Iter : components)
	{
		Iter->Release();
		SAFE_DELETE(Iter);
	}
}

void GameObject::CUpdate(float Et)
{
	for (auto Iter : components)
	{
		if(Iter->GetEnable())
			Iter->Update(Et);
	}
}

void GameObject::CRender(LPD3DXSPRITE sprite)
{
	tf->SetTransform(sprite);
	for (auto Iter : components)
	{
		if(Iter->GetEnable())
			Iter->Render(sprite);
	}
}

void GameObject::Send(cstr str)
{
	Receive(str);
	for (auto Iter : components)
		Iter->Receive(str);
}

void GameObject::SendCollider(Collider * collider)
{
	OnCollider(collider);
	for (auto Iter : components)
		Iter->OnCollider(collider);
}
