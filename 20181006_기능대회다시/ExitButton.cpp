#include "stdafx.h"
#include "ExitButton.h"


ExitButton::ExitButton()
{
}


ExitButton::~ExitButton()
{
}

void ExitButton::Start()
{
	//if (GetAsyncKeyState(LEFTBUTTON))

	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Exit.png");
	texture_size = { 0,0,477,163 };
	texture_ex.center = { 238,81 };

	collider_size = { 0,0,477,163 };

	x = 1000;
	y = 350;
}

void ExitButton::LateUpdate()
{
	if (x > 300)
		x -= (x - 300) / 25;
}

void ExitButton::Click()
{
	exit(0);
}
