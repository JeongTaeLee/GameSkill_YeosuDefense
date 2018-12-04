#pragma once
#include "singleton.h"
class CameraManager :
	public singleton<CameraManager>
{
private:
	Vector2 vEyePos;
	Vector2 vEyeSize;
	Vector3 vEyeScale;

	Vector2 vScroll;

	Vector2 vMin;
	Vector2 vMax;

	float fAngle;

	Matrix matView;
	Matrix matProj;
public:
	CameraManager();
	virtual ~CameraManager();

	void Update();
	
	void SetTransform();
	void SetCameraLock(Vector2 min, Vector2 max);
	void SetCameraPos(Vector2 pos);

	const Vector2 & GetScoll() { return vScroll; }
};

#define CAMERA CameraManager::GetInst()

