#include "stdafx.h"
#include "Time.h"
#include "Player.h"


Time::Time()
{
}


Time::~Time()
{
}

void Time::Start()
{
	time = TextureManager::Get()->LoadTexture("Image/Time.png");
	back = TextureManager::Get()->LoadTexture("Image/Time0.png");
	bar = TextureManager::Get()->LoadTexture("Image/Time1.png");
	sun = TextureManager::Get()->LoadTexture("Image/Time2.png");
	texture_size = { 0,0,693,63 };
	texture_ex.center = { 0,0 };
	texture_ex.camera_on = false;
}

void Time::Render()
{
	texture_ex.image_xscale = 1;
	texture_ex.image_yscale = 1;
	texture_ex.center = { 0,0 };
	texture_ex.x = 900;
	texture_ex.y = 970;
	texture_ex.texture_size = texture_size;
	
	texture_ex.texture = back;
	GrapicManager::Get()->TextureRender(texture_ex);

	texture_ex.texture_size = { 0,0,(int)(Player::me->time/7200.0f * 693),63 };

	texture_ex.texture = bar;
	GrapicManager::Get()->TextureRender(texture_ex);

	texture_ex.texture_size = texture_size;
	texture_ex.texture = sun;
	GrapicManager::Get()->TextureRender(texture_ex);

	texture_ex.x = 900;
	texture_ex.y = 1000;
	texture_ex.center = { 50,50 };


	a += 0.1;

	texture_ex.texture_size = { 0,0,100,100 };
	texture_ex.image_xscale = 1 + sin(a) * 0.1;
	texture_ex.image_yscale = 1 + cos(a) * 0.1;
	texture_ex.texture = time;
	GrapicManager::Get()->TextureRender(texture_ex);
}
