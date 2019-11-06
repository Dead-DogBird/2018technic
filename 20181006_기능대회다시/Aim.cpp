#include "stdafx.h"
#include "Aim.h"


Aim* Aim::me = nullptr;

Aim::Aim()
{
}


Aim::~Aim()
{
}

void Aim::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Camera.png");
	texture_size = { 0,0,100,100};
	texture_ex.center = { 50,50};

	dont_destroy = true;

	me = this;
}

void Aim::Update()
{
	a += 0.1;

	texture_ex.image_xscale = 1 + sin(a) * 0.2;
	texture_ex.image_yscale = 1 + cos(a) * 0.2;

	POINT mouse_point;
	GetCursorPos(&mouse_point);
	ClientToScreen(GrapicManager::Get()->window, &mouse_point);

	ShowCursor(false);

	x = mouse_point.x - SCREEN_WIDTH/2 + Camera::Get()->x;
	y = mouse_point.y - SCREEN_HEIGHT /2 + Camera::Get()->y;

	//x = Camera::Get()->x;
	//y = Camera::Get()->y;
}

void Aim::Render()
{
}

void Aim::LateRender()
{
	//exit(0);
	texture_ex.x = x;
	texture_ex.y = y;
	texture_ex.texture_size = { texture_size.right * (int)image_index,texture_size.top,texture_size.right * (int)image_index + texture_size.right,texture_size.bottom };
	//texture_ex.x = x;

	GrapicManager::Get()->TextureRender(texture_ex);
}
