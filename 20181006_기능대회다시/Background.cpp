#include "stdafx.h"
#include "Background.h"


Background::Background()
{
}


Background::~Background()
{
}

void Background::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Background.png");
	texture_size = { 0,0,1920,1080 };
	texture_ex.center = { 960,540 };

	//collider_size = { 0,0,480,179 };
}

void Background::LateUpdate()
{
	x = Camera::Get()->x;
	y = Camera::Get()->y;
}
