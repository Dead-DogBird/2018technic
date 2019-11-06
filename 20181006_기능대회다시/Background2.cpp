#include "stdafx.h"
#include "Background2.h"


Background2::Background2()
{
}


Background2::~Background2()
{
}

void Background2::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Background2.png");
	texture_size = { 0,0,1920,1080 };
	texture_ex.center = { 960,540 };
}

void Background2::LateUpdate()
{
	x = Camera::Get()->x;
	y = Camera::Get()->y;
}
