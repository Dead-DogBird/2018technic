#include "stdafx.h"
#include "StartButton.h"
#include "stdafx.h"
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

StartButton::StartButton()
{
}


StartButton::~StartButton()
{
}

void StartButton::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Start.png");
	texture_size = { 0,0,480,179 };
	texture_ex.center = { 238,81 };

	collider_size = { 0,0,480,179 };

	x = 1000;

	//x = 300;
	y = 50;
}

void StartButton::LateUpdate()
{
	if (x > 300)
		x -= (x - 300) / 15;
}

void StartButton::Click()
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


	inst = ObjectManager::Get()->CreateObject<Dron>();
	inst->x = 3000;
	inst->y = -300;

	inst = ObjectManager::Get()->CreateObject<Dron>();
	inst->x = 9000;
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

	//ObjectManager::Get()->CreateObject<White>();
}
