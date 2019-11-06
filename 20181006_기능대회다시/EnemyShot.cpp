#include "stdafx.h"
#include "EnemyShot.h"
#include "Pg.h"
#include "Player.h"
#include "Ouch.h"

EnemyShot::EnemyShot()
{
}


EnemyShot::~EnemyShot()
{
}

void EnemyShot::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/EnemyShot.png");
	texture_size = { 0,0,100,100 };
	texture_ex.center = { 50,50 };
	collider_size = { 30,30,70,70 };

	texture_ex.image_xscale = 1.5;
	texture_ex.image_yscale = 1.5;

	//watag = "Monster";
	
}

void EnemyShot::Update()
{
	if (GameManager::Get()->game_stop == true)
	{
		return;
	}
	if (Player::me->stop == true)
		return;

	x -= cos(D3DXToRadian(texture_ex.image_angle)) * 12;
	y -= sin(D3DXToRadian(texture_ex.image_angle)) * 12;

	destroy_time++;


	if (destroy_time > 600)
	{
		destroy = true;

	}

	GameObejct * monster = ObjectManager::Get()->CollidCheck(this, 0, 0, "Player");

	if (Player::me->damage_time <= 0)
		if (monster != nullptr)
		{
			ObjectManager::Get()->CreateObject<Ouch>();
			Camera::Get()->size = 1.4;
			Camera::Get()->rotation = 30;
			if (x > Player::me->x)
			{
				Player::me->wspeed = -50;
				Player::me->vspeed = -20;
				Pg * p = ObjectManager::Get()->CreateObject<Pg>();
				p->x = x;
				p->y = y;
			}
			else
			{
				Player::me->wspeed = 50;
				Player::me->vspeed = -20;
				Pg * p = ObjectManager::Get()->CreateObject<Pg>();
				p->x = x;
				p->y = y;
			}
			Player::me->hp -= 1;
			Player::me->damage_time = 20;
			destroy = true;
		}

	if (ObjectManager::Get()->CollidCheck(this, 0, 0, "Block"))
	{

		Pg * p = ObjectManager::Get()->CreateObject<Pg>();
		p->x = x;
		p->y = y;
		destroy = true;
	}
}
