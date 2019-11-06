#pragma once

#include "Singleton.h"

template <class T>
class Singleton;

#include "TextureEx.h"



class GrapicManager : public Singleton<GrapicManager>
{
public:
	GrapicManager();
	~GrapicManager();

	HWND window;
	LPDIRECT3D9 direct;
	LPDIRECT3DDEVICE9 device;
	LPD3DXSPRITE sprite;

	void Init();
	void Update();
	void Render();
	void TextureRender(TextureEx ex);

};

