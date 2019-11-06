#pragma once
class GameManager : public Singleton<GameManager>
{
public:
	GameManager();
	~GameManager();

	int stage = 0;
	int score = 0;
	int high_score = 0;

	bool game_stop = false;;


	int delay = 0;



	bool cheat_hp = false;

	void Update();

};

