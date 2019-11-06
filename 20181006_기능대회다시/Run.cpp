#include "stdafx.h"
#include "Run.h"


Run::Run()
{
}


Run::~Run()
{
}

void Run::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Run.png");
	texture_size = { 0,0,300,300 };
	texture_ex.center = { 150,150 };
	x = -100;
	y = 0;
}

void Run::Update()
{
	a += 0.1;

	texture_ex.image_xscale = 1 + sin(a) * 0.1;
	texture_ex.image_yscale = 1 - sin(a) * 0.1;

	y = sin(a) * 30;
}
