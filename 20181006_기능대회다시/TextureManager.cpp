#include "stdafx.h"
#include "TextureManager.h"


TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

LPDIRECT3DTEXTURE9 TextureManager::LoadTexture(string path)
{
	for (int i = 0; i < texture_vector.size(); i++)
	{
		if ((texture_vector[i].path) == path)
		{
			return texture_vector[i].texture;
		}
	}

	AddTexture(path);

	return LoadTexture(path);
}

void TextureManager::AddTexture(string path)
{
	TextureInfo info;
	info.path = path;

	if (FAILED(D3DXCreateTextureFromFileEx(GrapicManager::Get()->device, path.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, 0,
		NULL, NULL, &info.texture)))
		exit(0);

	texture_vector.push_back(info);
}
