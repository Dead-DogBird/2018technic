#pragma once
#include "TextureEx.h"
using namespace std;

class GameObejct
{
public:
	GameObejct();
	~GameObejct();

	float x = 0;
	float y = 0;
	float z = 0 ;

	string tag= "";

	bool destroy = false;
	bool dont_destroy = false;
	bool map_render = false;

	TextureEx texture_ex;
	RECT collider_size = {0,0,0,0};
	RECT texture_size = { 0,0,0,0 };
	float image_index = 0;

	virtual void Start();
	virtual void EUpdate();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();
	virtual void LateRender();
	void MiniMapRender();
};