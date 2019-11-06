#include "stdafx.h"
#include "White.h"


White::White()
{
}


White::~White()
{
}

void White::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/White.png");
	texture_size = { 0,0,1920,1080 };
	texture_ex.center = { 0,0 };
	texture_ex.camera_on = false;
}

void White::Update()
{
	alpha -= 2;
	if (alpha <= 0)
	{
		destroy = true;
	}
	texture_ex.image_blend = D3DCOLOR_ARGB(alpha,255, 255, 255);
}
