#include "stdafx.h"
#include "Player.h"
#include "Gun.h"
#include "Aim.h"
#include "Shot.h"
#include "Pg.h"
#include "Ouch.h"
#include "LaserGun.h"
#include "JumpPt.h"
#include "MedicPt.h"
#include "Sniper.h"
#include "Clear.h"
#include "StopItem.h"
Player * Player::me = nullptr;

Player::Player()
{
}


Player::~Player()
{
}

void Player::Start()
{
	me = this;
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Player.png");
	texture_size = { 0,0,75,75 };
	texture_ex.center = {37,37 };

	tag = "Player";

	map_render = true;

	y = -400;

	collider_size = { 0,0,75,75 };

	gun = ObjectManager::Get()->CreateObject<Gun>();
}

void Player::Update()
{
	if (GameManager::Get()->game_stop == true)
	{
		return;
	}
	

	//넥스트 또는 엔딩
	if (clear == false)
	if (ObjectManager::Get()->FindWithTag("Monster") == nullptr)
	{
		//exit(0);
		ObjectManager::Get()->CreateObject<Clear>();
		clear = true;
	}

	
		

	if (damage_time > 0)
		texture_ex.image_blend = D3DCOLOR_ARGB(180, 255,0,0);
	else
		texture_ex.image_blend = D3DCOLOR_ARGB(255,255,255,255);

	GameObejct * monster = ObjectManager::Get()->CollidCheck(this, 0, 0, "Monster");

	if (damage_time <= 0)
	if (monster != nullptr)
	{
		ObjectManager::Get()->CreateObject<Ouch>();
		Camera::Get()->size = 1.4;
		Camera::Get()->rotation = 30;
		if (monster->x > x)
		{
			wspeed = -50;
			vspeed = -20;
			Pg * p = ObjectManager::Get()->CreateObject<Pg>();
			p->x = x;
			p->y = y;
		}
		else
		{
			wspeed = 50;
			vspeed = -20;
			Pg * p = ObjectManager::Get()->CreateObject<Pg>();
			p->x = x;
			p->y = y;
		}
		hp -= 1;
		damage_time = 20;
	}
	damage_time--;

	if (hp <= 0)
	{
		if (clear == false)
		{
			//exit(0);
			Clear * inst = ObjectManager::Get()->CreateObject<Clear>();
			inst->texture_ex.texture = texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Fail.png");
			inst->fail = true;
			clear = true;
		}
	}

	if (y < -600)
	{
		vspeed = 0;
		y = -600;
	}
		
	time-=1;
	if (time <= 0)
	{
		if (clear == false)
		{
				//exit(0);
				Clear * inst = ObjectManager::Get()->CreateObject<Clear>();
				inst->texture_ex.texture = texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Fail.png");
				inst->fail = true;
				clear = true;
		}
	}

	gun->x = x;
	gun->y = y + 35;

	a += 0.1;
	
	vspeed += gravity;

	if (ObjectManager::Get()->CollidCheck(this, 0, 0, "Medic") != nullptr)
	{
		

		if (Camera::Get()->size < 2)
			Camera::Get()->size += 0.1;

		if (heal_delay <= 0)
		{
			if (hp < 5)
				hp++;

			ObjectManager::Get()->CreateObject<MedicPt>();

			heal_delay = 50;
		}
		if (heal_delay > 0)
			heal_delay--;
		

	}

	if (ObjectManager::Get()->CollidCheck(this,0, vspeed, "Block") == nullptr)
	{
		y += vspeed;
		is_ground = false;
	}
	else
	{
		vspeed = 0;
		is_ground = true;
		more_jump = -20;
	}

	if (damage_time <= 0)
	if (GetAsyncKeyState('A'))
	{
		//x -= 10;
		if (wspeed > -20)
			wspeed -= 2;
		dire = -1;
		
	}

	if (damage_time <= 0)
	if (GetAsyncKeyState('D'))
	{
		if (wspeed < 20)
			wspeed += 2;
		dire = 1;
	}

	
	if (ObjectManager::Get()->CollidCheck(this, wspeed,0, "Block") == nullptr)
	{
		x += wspeed;
	}
	else
	{
		wspeed = 0;
	}
	

	if (GetAsyncKeyState('F'))
	{
		if (item_delay <= 0)
		{
			ObjectManager::Get()->CreateObject<StopItem>();
			item_delay = 600;
		}
	}
	item_delay--;

	if (!GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT))
	{
		wspeed -= wspeed/ 10;
	}
		
	if (GetAsyncKeyState('W'))
	{
		if (is_ground == true)
		{
			GameObejct * inst = ObjectManager::Get()->CreateObject<JumpPt>();
			inst->x = x;
			inst->y = y;

			vspeed = -23;
		}
		else
		{
			//vspeed += more_jump;
			more_jump /= 20;
		}
			
	}
	
	

	

	

	gun->texture_ex.image_angle =  D3DXToDegree(atan2(y - Aim::me->y, x - Aim::me->x));

	Camera::Get()->x += (x - Camera::Get()->x) / 8;
	Camera::Get()->y += (y - Camera::Get()->y) / 8;

	//Camera::Get()->x = x + (Aim::me->x - x) * 500;

	if (Camera::Get()->y > 200)
	{
		Camera::Get()->y = 200;
	}

	if (Aim::me->x > x)
	{
		//exit(0);
		gun->texture_ex.image_xscale = -1;
		gun->texture_ex.image_angle -= 180;
	}
	else
	{
		gun->texture_ex.image_xscale = 1;
	}

	if (x < 0)
		x = 0;


	//gun->texture_ex.image_angle += 5;
	//x++;
	//y++;
	//texture_ex.image_angle += 2;
	texture_ex.image_xscale = dire + sin(a) * 0.2;
	texture_ex.image_yscale = 1 + cos(a) * 0.1;
}
