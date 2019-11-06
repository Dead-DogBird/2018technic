#include "stdafx.h"
#include "GameManager.h"
#include "Player.h"
#include "MainScene.h"
#include "LaserGun.h"
#include "Sniper.h"
#include "Gun.h"
GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

void GameManager::Update()
{
	if (cheat_hp == true)
		Player::me->hp = 5;

	if (GetAsyncKeyState(VK_F1))
	{
		cheat_hp = true;
	}

	if (GetAsyncKeyState(VK_F2))
	{
		//while (true)
		{
			GameObejct * inst = ObjectManager::Get()->FindWithTag("Monster");

			//if (inst == nullptr)
			//	break;
			if (inst != nullptr)
				inst->destroy = true;
			
		}
	}


	if (GetAsyncKeyState(VK_F3))
	{
		Camera::Get()->x = 0;
		Camera::Get()->y = 0;
		Camera::Get()->size = 1;
		Camera::Get()->rotation = 0;
		ObjectManager::Get()->Clear();
		ObjectManager::Get()->CreateObject<MainScene>();


	}

	if (GetAsyncKeyState(VK_F5))
	{
		game_stop = true;
	}
	else
	{
		game_stop = false;
	}

	if (delay <= 0)
	{
		if (GetAsyncKeyState(VK_F4))
		{
			if (Player::me->gun_num == 2)
			{
				Player::me->gun->destroy = true;
				Player::me->gun = ObjectManager::Get()->CreateObject<Gun>();
				Player::me->gun_num = 0;
			}
			else if (Player::me->gun_num == 0)
			{
				Player::me->gun->destroy = true;
				Player::me->gun = ObjectManager::Get()->CreateObject<LaserGun>();
				Player::me->gun_num = 1;
			}
			else if (Player::me->gun_num == 1)
			{
				Player::me->gun->destroy = true;
				Player::me->gun = ObjectManager::Get()->CreateObject<Sniper>();
				Player::me->gun_num = 2;
			}
			delay = 30;
		}
	}
	
	if (delay > 0)
		delay--;
}
