#include "stdafx.h"
#include "Contaner.h"


Contaner::Contaner()
{
}


Contaner::~Contaner()
{
}

void Contaner::Start()
{
	switch (rand() % 3)
	{
	case 0:
		texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Contaner.png");
		break;
	case 1:
		texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Contaner2.png");
		break;
	case 2:
		texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Contaner3.png");
		break;
	default:
		break;
	}
	
	collider_size = { 17,29,389,243 };//{ 17,29,330,206 };
	texture_size = { 0,0,400,300 };
	texture_ex.center = { 0,0};

	map_render = true;

	tag = "Block";

}

void Contaner::Update()
{
}
