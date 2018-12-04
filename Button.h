#pragma once
#include "Component.h"
class Button :
	public Component
{
private:
	Renderer * renderer;

	RECT re;
	function<void()> Behavior;

	int alpha;

	int Width;
	int Height;
public:
	Button();
	virtual ~Button();

	virtual void Start() override;
	virtual void Update(float Et) override;

	void SetButton(texture * image, const Vector2 & pos, int _Width, int _Height);
	void SetBehavior(function<void()> _Behavior);

	RECT GetRect() { return re; }
};

