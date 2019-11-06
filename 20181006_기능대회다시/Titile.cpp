#include "stdafx.h"
#include "Titile.h"


Titile::Titile()
{
}


Titile::~Titile()
{
}

void Titile::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Title.png");
	texture_size = { 0,0,938,280 };
	texture_ex.center = { 469,140};

	x = -100;
	y = -300;
}

void Titile::Update()
{
	a += 0.06;

	texture_ex.image_xscale = 1 + sin(a) * 0.2;
	texture_ex.image_yscale = 1 + cos(a) * 0.2;
	texture_ex.image_angle = cos(a) * 5;
}
