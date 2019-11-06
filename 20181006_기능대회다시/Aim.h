#pragma once
class Aim : public GameObejct
{
public:
	Aim();
	~Aim();

	static Aim * me;
	float a = 0;

	void Start();
	void Update();
	void Render();
	void LateRender();
};

