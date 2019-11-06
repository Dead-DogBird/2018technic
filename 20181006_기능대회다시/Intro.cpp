#include "stdafx.h"
#include "Intro.h"
#include "MainScene.h"
#include "White.h"

Intro::Intro()
{
}


Intro::~Intro()
{
}

void Intro::Start()
{
	intro_1 = TextureManager::Get()->LoadTexture("Image/Intro/1.png");
	intro_2 = TextureManager::Get()->LoadTexture("Image/Intro/2.png");
	texture_ex.texture = intro_1;
	intro_3 = TextureManager::Get()->LoadTexture("Image/Intro/3.png");
	texture_size = { 0,0,1920,1080 };
	texture_ex.center = { 0,0 };
	texture_ex.camera_on = false;
}

void Intro::Update()
{
	time+=1;

	if (GetAsyncKeyState(VK_SPACE))
	{
		scene = 3;
		time = 210;
	}

	
	if (time <= 50)
	{
		texture_ex.image_blend = D3DCOLOR_ARGB((int)(time/50.0f * 255), 255, 255, 255);
	}
	else if (time <= 180)
	{
		texture_ex.image_blend = D3DCOLOR_ARGB(255, 255, 255, 255);
	}
	else 
	{
		texture_ex.image_blend = D3DCOLOR_ARGB(255 - (int)((time-180)/40.0f * 255),255,255,255);
	}


	if (time >= 220)
	{
		time = 0;
		scene++;
		if (scene == 2)
		{
			texture_ex.texture = intro_2;
		}
		else if(scene == 3)
		{
			texture_ex.texture = intro_3;
		}
		else if (scene == 4)
		{
			
			ObjectManager::Get()->CreateObject<MainScene>();
			ObjectManager::Get()->CreateObject<White>();
		}
		
	}
}
