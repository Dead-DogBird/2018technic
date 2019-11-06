#include "stdafx.h"
#include "GameObejct.h"


GameObejct::GameObejct()
{
}


GameObejct::~GameObejct()
{
}

void GameObejct::Start()
{
}

void GameObejct::EUpdate()
{
}

void GameObejct::Update()
{
}

void GameObejct::LateUpdate()
{
}

void GameObejct::Render()
{
	texture_ex.x = x;
	texture_ex.y = y;
	texture_ex.texture_size = { texture_size.right * (int)image_index,texture_size.top,texture_size.right * (int)image_index + texture_size.right,texture_size.bottom};
	//texture_ex.x = x;

	GrapicManager::Get()->TextureRender(texture_ex);
}

void GameObejct::LateRender()
{
}

void GameObejct::MiniMapRender()
{
	if (map_render == false)
		return;
	float imaege_xscale = texture_ex.image_xscale;
	float imaege_yscale = texture_ex.image_yscale;
	bool camera_on = texture_ex.camera_on;
	texture_ex.x = x / 10 + 100;
	texture_ex.y = y / 10 + 100;
	texture_ex.texture_size = { texture_size.right * (int)image_index,texture_size.top,texture_size.right * (int)image_index + texture_size.right,texture_size.bottom };
	texture_ex.image_xscale = imaege_xscale * 0.1;
	texture_ex.image_yscale = imaege_yscale * 0.1;

	texture_ex.camera_on = false;

	GrapicManager::Get()->TextureRender(texture_ex);

	texture_ex.camera_on = camera_on;

	texture_ex.image_xscale = imaege_xscale;
	texture_ex.image_yscale = imaege_yscale;

}
