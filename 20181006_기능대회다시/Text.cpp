#include "stdafx.h"
#include "Text.h"


Text::Text()
{
}


Text::~Text()
{
}

void Text::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Text.png");
	texture_size = { 0,0,250,30 };
	texture_ex.center = { 0,0 };
	//collider_size = { 55,42,192,211 };

	map_render = true;

	tag = "Block";
}

void Text::Update()
{
}

void Text::Render()
{

}
