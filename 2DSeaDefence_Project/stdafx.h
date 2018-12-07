#pragma once

enum system
{
	WINSIZEX = 1280,
	WINSIZEY = 720,
};

enum Sort
{
	BACKGROUND01,
	BACKGROUND02,
	INGAME01,
	INGAME02,
	EFFECT01,
	EFFECT02,
	UI01,
	UI02,
};

enum MonsterInfo
{
	MOB01_A = 5,
	MOB01_H = 30,
	MOB01_S = 60,
	MOB01_G = 100,
	MOB01_SC = 100,

	MOB02_A = 10,
	MOB02_H = 70,
	MOB02_S = 50,
	MOB02_G = 200,
	MOB02_SC = 200,

	MOB03_A = 10,
	MOB03_H = 20,
	MOB03_S = 70,
	MOB03_G = 300,
	MOB03_SC = 300,

	MOB04_A = 15,
	MOB04_H = 80,
	MOB04_S = 30,
	MOB04_G = 400,
	MOB04_SC = 400,
	
	BOSS_A = 10,
	BOSS_H = 500,
	BOSS_S = 20,

	CANNON01_A = 10,
	CANNON01_D = 4,
	CANNON01_R = 200,

	CANNON01_2_A = 12,
	CANNON01_2_D = 3,
	CANNON01_2_R = 200,

	CANNON01_3_A = 15,
	CANNON01_3_D = 2,
	CANNON01_3_R = 200,

	CANNON02_A = 5,
	CANNON02_D = 3,
	CANNON02_R = 200,

	CANNON02_2_A = 7,
	CANNON02_2_D = 2,
	CANNON02_2_R = 200,

	CANNON02_3_A = 10,
	CANNON02_3_D = 1,
	CANNON02_3_R = 200,

	CANNON03_A = 10,
	CANNON03_D = 5,
	CANNON03_R = 250,

	CANNON03_2_A = 12,
	CANNON03_2_D = 4,
	CANNON03_2_R = 250,

	CANNON03_3_A = 15,
	CANNON03_3_D = 3,
	CANNON03_3_R = 250,

	HAC_H = 100,
};

#define g_device DXUTGetD3D9Device()

#ifdef DEBUG
#define DEBUG_LOG(s) cout << s << endl
#else
#define DEBUG_LOG(s)
#endif

typedef D3DXVECTOR2 Vector2;
typedef D3DXVECTOR3 Vector3;
typedef D3DCOLOR    Color;
typedef D3DXMATRIX Matrix;

#define OrginColor D3DCOLOR_XRGB(255, 255, 255)
#define cstr const string & 

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <functional>
#include <thread>

using namespace std;

#include "Func.h"

#include "ImageManager.h"
#include "InputManager.h"
#include "CameraManager.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "IngameManager.h"

#include "transform.h"	
#include "Renderer.h"
#include "Collider.h"
#include "Animater.h"
#include "GameObject.h"