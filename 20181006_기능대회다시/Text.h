#pragma once
class Text : public GameObejct
{
public:
	Text();
	~Text();

	int text = 0;

	void Start();
	void Update();
	void Render();
};

