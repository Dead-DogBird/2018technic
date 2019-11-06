#include "stdafx.h"
#include "Block.h"


Block::Block()
{
}


Block::~Block()
{
}

void Block::Start()
{
	if (GameManager::Get()->stage == 1)
		texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Block.png");
	else
		texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Block2.png");
	collider_size = { 0,180,500,500 };
	texture_size = { 0,0,500,500 };

	map_render = true;
	texture_ex.center = { 0,0 };

	tag ="Block";

	x = 0;

	y = 200;
}
