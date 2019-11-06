#pragma once
#include "GameObejct.h"

class White : public GameObejct
{
public:
	White();
	~White();

	int alpha = 255;
	//float a = 0.1;

	void Start();
	void Update();
	//void Render();
};

