#pragma once
#include "Component.h"
class Effect :
	public Component
{
private:
	Renderer * renderer;
    Animater * animater;
public:
	Effect();
	virtual ~Effect();

	virtual void Start()	override;
	virtual void Receive(cstr message) override;
public:
	void SetEffect(cstr key, int mn, int mx, float Delay = 0.1f);
};

