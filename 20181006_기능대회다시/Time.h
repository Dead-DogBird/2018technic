#pragma once
class Time : public GameObejct
{
public:
	Time();
	~Time();

	float a = 0;

	LPDIRECT3DTEXTURE9 time;

	LPDIRECT3DTEXTURE9 back;
	LPDIRECT3DTEXTURE9 bar;
	LPDIRECT3DTEXTURE9 sun;

	void Start();
	void Render();
};

