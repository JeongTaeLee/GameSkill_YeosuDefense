#pragma once
class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void Init()	PURE;
	virtual void Release() PURE;
	virtual void Update(float Et) PURE;
	virtual void Render(LPD3DXSPRITE sprite) PURE;
};

