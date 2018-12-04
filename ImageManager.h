#pragma once
#include "singleton.h"

struct texture
{
	LPDIRECT3DTEXTURE9	lpTex;
	D3DXIMAGE_INFO		info;

	texture(LPDIRECT3DTEXTURE9 _lpTex, D3DXIMAGE_INFO _info)
		:lpTex(_lpTex), info(_info)
	{}
};

class ImageManager :
	public singleton<ImageManager>
{
private:
	map<string, texture * > textures;
public:
	ImageManager();
	virtual ~ImageManager();

	texture *	AddTexture(cstr str, cstr path);
	void		AddTextures(cstr str, cstr path, int mn, int mx);

	void drawText(LPD3DXSPRITE sprite, cstr str, const Vector2 & pos, int size, int bold, D3DCOLOR color = OrginColor);
};

#define IMAGE ImageManager::GetInst()
