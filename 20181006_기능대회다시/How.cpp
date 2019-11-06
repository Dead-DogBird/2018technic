#include "stdafx.h"
#include "How.h"


How::How()
{
}


How::~How()
{
}

void How::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/HowTo.png");
	texture_size = { 0,0,1920,1080 };
	texture_ex.center = { 960,540 };

	y = -1000;
}

void How::Update()
{
	if (y < 0)
	{
		y += -y /15;
	}

	if (y > -100)
	if (GetAsyncKeyState(VK_LBUTTON))
	{
		
		destroy = true;
	}


}

void How::Click()
{
}
