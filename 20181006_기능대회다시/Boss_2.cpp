#include "stdafx.h"
#include "Boss_2.h"
#include "Player.h"
#include "EnemyShot.h"

Boss_2::Boss_2()
{
}


Boss_2::~Boss_2()
{
}

void Boss_2::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Boss_2.png");
	texture_size = { 0,0,500,500 };
	texture_ex.center = { 250,250 };

	collider_size = { 100,100,400,400 };
	map_render = true;

	tag = "Monster";

	hp = 20;
	x = 1000;
	y = -100;
}

void Boss_2::Update()
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

	if (shot_delay <= 0)
	{
		for (int i = 0; i < 3;i++)
		{
			GameObejct * shot = ObjectManager::Get()->CreateObject<EnemyShot>();
			shot->x = x;
			shot->y = y;
			shot->texture_ex.image_angle = D3DXToDegree(atan2(y - Player::me->y, x - Player::me->x)) -30 + i * 30;//
		}
		shot_delay = 80;
	}
	shot_delay--;

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
