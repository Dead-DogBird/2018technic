#include "stdafx.h"
#include "Mission1.h"


Mission1::Mission1()
{
}


Mission1::~Mission1()
{
}

void Mission1::Start()
{
	if (GameManager::Get()->stage == 1)
		texture_ex.texture = TextureManager::Get()->LoadTexture("Image/mission_1.png");
	else
		texture_ex.texture = TextureManager::Get()->LoadTexture("Image/mission_2.png");
	texture_size = { 0,0,1920,81 };
	//texture_ex.center0 = { ,81 };
	texture_ex.camera_on = false;
	y = -200;
}

void Mission1::Update()
{
	if (y < 0)
	{
		y += (0 - y) / 10;
	}

	time++;

	if (time > 300)
	{
		if (y > -200)
		{
			y += (-200 - y) / 10;
		}
	}
}
