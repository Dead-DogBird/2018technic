#pragma once
class TextureEx
{
public:
	LPDIRECT3DTEXTURE9 texture;

	float x = 0;
	float y = 0;
	float z = 0;

	float image_xscale = 1;
	float image_yscale = 1;
	float image_angle = 0;
	POINT center = {0,0};
	RECT texture_size = {0,0,0,0};

	D3DCOLOR image_blend = D3DCOLOR_ARGB(255, 255, 255, 255);

	bool camera_on = true;
};