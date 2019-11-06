#pragma once
class HpUI : public GameObejct
{
public:
	HpUI();
	~HpUI();

	float a = 0;

	LPDIRECT3DTEXTURE9 hp;
	LPDIRECT3DTEXTURE9 hpout;

	void Start();
	void Render();
};

