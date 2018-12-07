#include "DXUT.h"
#include "Component.h"
#include "GameObject.h"

Component::Component()
	:bEnable(true), gameObject(nullptr)
{
}


Component::~Component()
{
}

void Component::Send(cstr message)
{
	gameObject->Send(message);
}
