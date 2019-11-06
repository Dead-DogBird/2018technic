#include "stdafx.h"
#include "Drum.h"


Drum::Drum()
{
}


Drum::~Drum()
{
}

void Drum::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Drum.png");
	texture_size = { 0,0,250,250 };
	texture_ex.center = { 91,51 };
	collider_size = { 55,42,192,211 };

	map_render = true;

	tag = "Block";
}

void Drum::Update()
{
}
