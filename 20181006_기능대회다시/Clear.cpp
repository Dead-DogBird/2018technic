#include "stdafx.h"
#include "Clear.h"
#include "MainScene.h"
#include "Block.h"
#include "Aim.h"
#include "Player.h"
#include "ExitButton.h"
#include "StartButton.h"
#include "MenuButton.h"
#include "Titile.h"
#include "Contaner.h"
#include "UI.h"
#include "White.h"
#include "Monster1.h"
#include "Dron.h"
#include "Run.h"
#include "Medic.h"
#include "Drum.h"
#include "Mission1.h"
#include "HpUI.h"
#include "Stop.h"
#include "Time.h"
#include "Monster2.h"
#include "Background.h"
#include "Background2.h"
#include "Boss_1.h"
#include "Boss_2.h"

Clear::Clear()
{
}


Clear::~Clear()
{
}

void Clear::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Clear.png");
	texture_size = { 0,0,1920,1080 };
	texture_ex.center = { 0,0};
	texture_ex.camera_on = false;

	y = -1000;
}

void Clear::EUpdate()
{
	GameManager::Get()->game_stop = true;
	
	if (Camera::Get()->size < 2)
		Camera::Get()->size += 0.1;

	if (y < 0)
	{
		y += -y / 15;
	}

	if (y > -50)
		if (GetAsyncKeyState(VK_LBUTTON) || GetAsyncKeyState(VK_SPACE))
	{
			if (fail == true)
			{
				GameManager::Get()->stage--;
			}

			if (GameManager::Get()->stage == 0)
			{
				ObjectManager::Get()->Clear();

				ObjectManager::Get()->CreateObject<Background>();

				GameManager::Get()->stage = 1;

				for (int i = 0; i < 40; i++)
				{
					GameObejct * inst = ObjectManager::Get()->CreateObject<Block>();
					inst->x = -1200 + i * 500;
				}

				GameObejct * inst = ObjectManager::Get()->CreateObject<Contaner>();
				inst->x = 1500;
				inst->y = 130;

				inst = ObjectManager::Get()->CreateObject<Contaner>();
				inst->x = 1680;
				inst->y = 130 - 200;

				inst = ObjectManager::Get()->CreateObject<Contaner>();
				inst->x = 3000;
				inst->y = 130;

				inst = ObjectManager::Get()->CreateObject<Contaner>();
				inst->x = 4000;
				inst->y = 130;

				inst = ObjectManager::Get()->CreateObject<Contaner>();
				inst->x = 4400;
				inst->y = 130;

				inst = ObjectManager::Get()->CreateObject<Contaner>();
				inst->x = 5500;
				inst->y = 130;

				inst = ObjectManager::Get()->CreateObject<Contaner>();
				inst->x = 7000;
				inst->y = 130;

				inst = ObjectManager::Get()->CreateObject<Contaner>();
				inst->x = 8000;
				inst->y = 130;

				inst = ObjectManager::Get()->CreateObject<Contaner>();
				inst->x = 9500;
				inst->y = 130;


				inst = ObjectManager::Get()->CreateObject<Drum>();
				inst->x = 800;
				inst->y = 200;

				inst = ObjectManager::Get()->CreateObject<Drum>();
				inst->x = 2300;
				inst->y = 200;

				inst = ObjectManager::Get()->CreateObject<Drum>();
				inst->x = 3600;
				inst->y = 200;

				inst = ObjectManager::Get()->CreateObject<Drum>();
				inst->x = 3600;
				inst->y = 30;

				inst = ObjectManager::Get()->CreateObject<Drum>();
				inst->x = 4300;
				inst->y = 0;

				inst = ObjectManager::Get()->CreateObject<Drum>();
				inst->x = 6000;
				inst->y = 200;

				inst = ObjectManager::Get()->CreateObject<Drum>();
				inst->x = 7000;
				inst->y = 200;



				inst = ObjectManager::Get()->CreateObject<Medic>();
				inst->x = 300;
				inst->y = 200;

				inst = ObjectManager::Get()->CreateObject<Monster2>();
				inst->x = 5000;
				inst->y = -300;

				inst = ObjectManager::Get()->CreateObject<Dron>();
				inst->x = 6000;
				inst->y = -300;

				inst = ObjectManager::Get()->CreateObject<Monster1>();
				inst->x = 8000;
				inst->y = -300;

				inst = ObjectManager::Get()->CreateObject<Monster1>();
				inst->x = 10000;
				inst->y = -300;


				//ObjectManager::Get()->CreateObject<Dron>();



				ObjectManager::Get()->CreateObject<Player>();

				ObjectManager::Get()->CreateObject<Run>();


				ObjectManager::Get()->CreateObject<UI>();

				ObjectManager::Get()->CreateObject<HpUI>();
				ObjectManager::Get()->CreateObject<Time>();

				ObjectManager::Get()->CreateObject<Mission1>();

				ObjectManager::Get()->CreateObject<Stop>();
			}
			//GameManager::Get()->game_stop = false;
		// 스테이지 1이라면
		else if (GameManager::Get()->stage == 1)
		{
			GameManager::Get()->game_stop = false;

			GameManager::Get()->stage = 2;

			ObjectManager::Get()->Clear();

			ObjectManager::Get()->CreateObject<Background2>();

			for (int i = 0; i < 40; i++)
			{
				GameObejct * inst = ObjectManager::Get()->CreateObject<Block>();
				inst->x = -1200 + i * 500;
			}

			Camera::Get()->x = 0;
			Camera::Get()->y = 0;
			Camera::Get()->size = 1;
			Camera::Get()->rotation = 0;


			GameObejct * inst;

			inst = ObjectManager::Get()->CreateObject<Drum>();
			inst->x = 800;
			inst->y = 250;

			inst = ObjectManager::Get()->CreateObject<Drum>();
			inst->x = 2300;
			inst->y = 200;

			inst = ObjectManager::Get()->CreateObject<Drum>();
			inst->x = 3600;
			inst->y = 200;

			inst = ObjectManager::Get()->CreateObject<Drum>();
			inst->x = 3600;
			inst->y = 30;

			inst = ObjectManager::Get()->CreateObject<Drum>();
			inst->x = 4300;
			inst->y = 0;

			inst = ObjectManager::Get()->CreateObject<Drum>();
			inst->x = 6000;
			inst->y = 200;

			inst = ObjectManager::Get()->CreateObject<Drum>();
			inst->x = 7000;
			inst->y = 200;

			inst = ObjectManager::Get()->CreateObject<Medic>();
			inst->x = 300;
			inst->y = 200;

			inst = ObjectManager::Get()->CreateObject<Boss_2>();
			inst->x = 5000;
			inst->y = -300;

			inst = ObjectManager::Get()->CreateObject<Boss_1>();
			inst->x = 12000;
			inst->y = -300;

			inst = ObjectManager::Get()->CreateObject<Dron>();
			inst->x = 6000;
			inst->y = -300;

			inst = ObjectManager::Get()->CreateObject<Monster2>();
			inst->x = 8000;
			inst->y = -300;

			inst = ObjectManager::Get()->CreateObject<Monster1>();
			inst->x = 10000;
			inst->y = -300;


			//ObjectManager::Get()->CreateObject<Dron>();



			ObjectManager::Get()->CreateObject<Player>();

			ObjectManager::Get()->CreateObject<Run>();


			ObjectManager::Get()->CreateObject<UI>();

			ObjectManager::Get()->CreateObject<HpUI>();
			ObjectManager::Get()->CreateObject<Time>();

			ObjectManager::Get()->CreateObject<Mission1>();

			ObjectManager::Get()->CreateObject<Stop>();
		}
		else if (GameManager::Get()->stage == 2)
		{
			//점수
			Camera::Get()->x = 0;
			Camera::Get()->y = 0;
			Camera::Get()->size = 1;
			Camera::Get()->rotation = 0;
			ObjectManager::Get()->Clear();
			ObjectManager::Get()->CreateObject<MainScene>();
		}
	}
}
