#include "stdafx.h"
#include "UI.h"


UI::UI()
{
}


UI::~UI()
{
}

void UI::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/UI.png");
	texture_size = { 0,0,1920,1080 };
	texture_ex.center = { 0,0};
	texture_ex.camera_on = false;
}

void UI::LateUpdate()
{
	//x = Camera::Get()->x;
	//y = Camera::Get()->y;
}
