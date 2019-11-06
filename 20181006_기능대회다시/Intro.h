#pragma once
class Intro : public GameObejct
{
public:
	Intro();
	~Intro();

	LPDIRECT3DTEXTURE9 intro_1;
	LPDIRECT3DTEXTURE9 intro_2;
	LPDIRECT3DTEXTURE9 intro_3;


	int time = 0;
	int scene = 1;


	void Start();
	void Update();
};

