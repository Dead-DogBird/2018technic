#include "stdafx.h"
#include "MenuButton.h"
#include "How.h"

MenuButton::MenuButton()
{
}


MenuButton::~MenuButton()
{
}

void MenuButton::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/How.png");
	texture_size = { 0,0,467,176 };
	texture_ex.center = { 238,81 };

	collider_size = { 0,0,477,163 };

	x = 1000;
	y = 200;
}

void MenuButton::LateUpdate()
{
	if (x > 300)
		x -= (x - 300) / 20;
	delay--;
}

void MenuButton::Click()
{
	if (delay <= 0)
	{
		delay = 30;
		ObjectManager::Get()->CreateObject<How>();
	}
	
}
