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

MainScene::MainScene()
{
}


MainScene::~MainScene()
{
}

void MainScene::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Main.png");
	texture_size = { 0,0,1920,1080 };
	texture_ex.center = { 960,540};

	ObjectManager::Get()->CreateObject<Titile>();
	ObjectManager::Get()->CreateObject<ExitButton>();
	ObjectManager::Get()->CreateObject<StartButton>();
	ObjectManager::Get()->CreateObject<MenuButton>();
}

void MainScene::Update()
{
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		exit(0);
	}
}
