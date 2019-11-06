#pragma once
class LaserGun : public GameObejct
{
public:
	LaserGun();
	~LaserGun();

	LPDIRECT3DTEXTURE9 gun;
	LPDIRECT3DTEXTURE9 laser;

	void Start();
	void Update();
	void Render();
};

