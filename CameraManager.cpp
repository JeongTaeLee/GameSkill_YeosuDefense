#include "DXUT.h"
#include "CameraManager.h"


CameraManager::CameraManager()
{
	vEyePos		= Vector2((float)WINSIZEX / 2, (float)WINSIZEY / 2);
	vEyeSize	= Vector2((float)WINSIZEX, (float)WINSIZEY);
	vEyeScale	= Vector3(1.f, 1.f, 1.f);

	D3DXMatrixOrthoLH(&matProj, vEyeSize.x, -vEyeSize.y, 0.f, 1.f);
	
	fAngle		= 0.f;

	vMin = Vector2(0, 0);	
	vMax = Vector2(1920, 1040);
}


CameraManager::~CameraManager()
{
}

void CameraManager::Update()
{
	if (INPUT.GetMousePos().x < 30)
	{
		if((vEyePos.x - 300 * DXUTGetElapsedTime()) > vMin.x + 640)
			vEyePos.x -= 300 * DXUTGetElapsedTime();
	}
	if (INPUT.GetMousePos().x > 1250)
	{
		if ((vEyePos.x + 300 * DXUTGetElapsedTime()) < vMax.x - 640)
			vEyePos.x += 300 * DXUTGetElapsedTime();
	}

	if (INPUT.GetMousePos().y < 30)
	{
		if ((vEyePos.y - 300 * DXUTGetElapsedTime()) > vMin.y + 360)
			vEyePos.y -= 300 * DXUTGetElapsedTime();
	}
	if (INPUT.GetMousePos().y > 690)
	{
		if ((vEyePos.y + 300 * DXUTGetElapsedTime()) < vMax.y - 360)
			vEyePos.y += 300 * DXUTGetElapsedTime();
	}

	vScroll = Vector2(WINSIZEX / 2 - vEyePos.x, WINSIZEY / 2 - vEyePos.y);

	matView = Matrix(  
		vEyeScale.x * cosf(fAngle), vEyeScale.x * sinf(fAngle), 0.f, 0.f,
		vEyeScale.y * sinf(fAngle), vEyeScale.y * cosf(fAngle), 0.f, 0.f,
		0, 0, vEyeScale.z, 0,
		-vEyePos.x * vEyeScale.y * cosf(fAngle) + vEyePos.y * vEyeScale.y * sinf(fAngle),
		-vEyePos.x * vEyeScale.x * sinf(fAngle) - vEyePos.y * vEyeScale.y * cosf(fAngle), 0, 1
	);
}

void CameraManager::SetTransform()
{
	g_device->SetTransform(D3DTS_VIEW, &matView);
	g_device->SetTransform(D3DTS_PROJECTION, &matProj);
}

void CameraManager::SetCameraLock(Vector2 min, Vector2 max)
{
	vMin = min, vMax = max;
}

void CameraManager::SetCameraPos(Vector2 pos)
{
	vEyePos = pos;
}
