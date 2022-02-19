#include <vector>
#include <string>
#include <map>
#include "SingleplayerBowlingGame.h"

class Player
{
public:
	Player(uint8_t _index, std::string _name):
		index(_index),
		name(_name)
		{};
	~Player(){};
	uint8_t index;
	std::string name{};
	SingleplayerBowlingGame game_state{};
};

class MultiplayerBowlingGame
{
private:
	std::map<std::string, Player> players;
	int general_frame_nbr { 0 };
	int current_player_index { 0 };

public:
	void addPlayer(std::string _player_name);
	Player getCurrentPlayer() const;
	int score(std::string _player_name);
	void roll(int pins_knocked, std::string _player_name);
};

