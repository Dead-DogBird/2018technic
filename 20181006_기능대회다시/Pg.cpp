#include "stdafx.h"
#include "Pg.h"


Pg::Pg()
{
}


Pg::~Pg()
{
}

void Pg::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/PG.png");
	texture_size = { 0,0,100,100 };
	texture_ex.center = { 50,50 };

	texture_ex.image_xscale += rand() % 10 / 3.0f;
	texture_ex.image_yscale += rand() % 10 / 3.0f;

}

void Pg::Update()
{
	alpha -= alpha / 10;
	texture_ex.image_blend = D3DCOLOR_ARGB((int)alpha, 255, 255, 255);


	//texture_ex.image_blend -= (texture_ex.image) / 10;
	texture_ex.image_xscale -= (texture_ex.image_xscale) / 10;
	texture_ex.image_yscale -= (texture_ex.image_yscale) / 10;
}
