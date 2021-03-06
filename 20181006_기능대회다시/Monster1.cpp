#include "stdafx.h"
#include "Monster1.h"
#include "Player.h"
#include "EnemyShot.h"

Monster1::Monster1()
{
}


Monster1::~Monster1()
{
}

void Monster1::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Monster.png");
	texture_size = {0,0,300,300 };
	texture_ex.center = { 150,150 };

	collider_size = { 50,38,225,276 };
	map_render = true;

	tag = "Monster";

	hp = 18;
	x = 1000;
	y = -200;
}

void Monster1::Update()
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

	image_index += 0.3;
	if (image_index > 2)
		image_index = 0;

	vspeed += gravity;


	if (ObjectManager::Get()->CollidCheck(this, 0, vspeed, "Block") == nullptr)
	{
		y += vspeed;
		is_ground = false;
	}
	else
	{
		vspeed = 0;
		is_ground = true;
	}

	if (shot_delay <= 0)
	{
		for (int i = 0; i < 3;i++)
		{
			GameObejct * shot = ObjectManager::Get()->CreateObject<EnemyShot>();
			shot->x = x;
			shot->y = y;
			shot->texture_ex.image_angle = D3DXToDegree(atan2(y - Player::me->y, x - Player::me->x)) - 15 + i * 15;//
		}
		shot_delay = 80;
	}
	shot_delay--;
	



	if (x > Player::me->x )
	{
		if (wspeed > -5)
			wspeed -= 1;
		texture_ex.image_xscale = 1;
	}
	else
	{
		if (wspeed < 5)
			wspeed += 1;

		texture_ex.image_xscale = -1;
	}

	if (abs(wspeed) < 0.5)
	{
		wspeed = 0;
	}

	if (ObjectManager::Get()->CollidCheck(this, wspeed, 0,"Block") == nullptr)
	{
		x += wspeed;
	}
	else
	{
		if (is_ground == true)
		vspeed = -30;
	}
}
