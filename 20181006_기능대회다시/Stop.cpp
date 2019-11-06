#include "stdafx.h"
#include "Stop.h"
#include "Player.h"

Stop::Stop()
{
}


Stop::~Stop()
{
}

void Stop::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Stop.png");
	texture_size = { 0,0,1920,1080 };
	texture_ex.center = { 0,0 };
	texture_ex.camera_on = false;
}

void Stop::Update()
{
	if (Player::me->stop == true)
		texture_ex.image_xscale = 1;
	else
		texture_ex.image_xscale = 0;
}
