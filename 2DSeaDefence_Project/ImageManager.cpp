#include "DXUT.h"
#include "ImageManager.h"


ImageManager::ImageManager()
{
}


ImageManager::~ImageManager()
{
	for (auto Iter : textures)
	{
		SAFE_RELEASE(Iter.second->lpTex);
		SAFE_DELETE(Iter.second);
	}
	textures.clear();
}

texture * ImageManager::AddTexture(cstr str, cstr path)
{
	auto find = textures.find(str);

	if (find != textures.end())
		return find->second;

	LPDIRECT3DTEXTURE9 lpTex;
	D3DXIMAGE_INFO info;

	if (D3DXCreateTextureFromFileExA(g_device, path.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, nullptr, &lpTex) == S_OK)
	{
		return textures.insert(make_pair(str, new texture(lpTex, info))).first->second;
	}

	DEBUG_LOG("LoadTexture Error! : " << str << " " << path);
	return nullptr;
}

void ImageManager::AddTextures(cstr str, cstr path, int mn, int mx)
{
	for (int i = mn; i <= mx; ++i)
	{
		char key[256];
		sprintf(key, str.c_str(), i);

		char p[256];
		sprintf(p, path.c_str(), i);

		AddTexture(key, p);
	}
}

void ImageManager::drawText(LPD3DXSPRITE sprite, cstr str, const Vector2 & pos, int size, int bold, D3DCOLOR color)
{
	LPD3DXFONT font;
	D3DXCreateFontA(g_device, size, 0, bold, 1, false, DEFAULT_CHARSET, 0, 0, 0, "±¼¸²", &font);

	Matrix mat;
	D3DXMatrixTranslation(&mat, pos.x, pos.y, 0.f);
	sprite->SetTransform(&mat);

	RECT re = { 0 };
	font->DrawTextA(sprite, str.c_str(), -1, &re, DT_NOCLIP, color);

	SAFE_RELEASE(font);
}

