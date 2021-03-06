#include "stdafx.h"
#include "Dron.h"
#include "Player.h"

Dron::Dron()
{
}


Dron::~Dron()
{
}

void Dron::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Dron.png");
	texture_size = { 0,0,300,300 };
	texture_ex.center = { 150,150 };

	collider_size = { 75,106,223,236 };
	map_render = true;

	tag = "Monster";

	hp = 10;
	x = 1000;
	y = -100;
}

void Dron::Update()
{
	if (GameManager::Get()->game_stop == true)
	{
		return;
	}

	if (x - Player::me->x < 1200)
		awake = true;

	if (awake == false)
		return;

	if (hp <= 0)
		destroy = true;

	if (Player::me->stop == true)
		return;

	image_index += 0.1;
	if (image_index > 2)
		image_index = 0;

	a += 0.1;

	y = -230 + sin(a) * 90;

	if (x > Player::me->x)
	{
		if (wspeed > -18)
			wspeed -= 1;
		texture_ex.image_xscale = 1;
	}
	else
	{
		if (wspeed < 18)
			wspeed += 1;

		texture_ex.image_xscale = -1;
	}

	if (abs(wspeed) < 0.5)
	{
		wspeed = 0;
	}

	if (ObjectManager::Get()->CollidCheck(this, wspeed, 0, "Block") == nullptr)
	{
		x += wspeed;
	}
	else
	{
		if (is_ground == true)
			vspeed = -30;
	}

	


}
