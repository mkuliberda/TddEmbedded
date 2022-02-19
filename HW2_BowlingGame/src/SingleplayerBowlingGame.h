#include <array>
#include "BowlingFrame.h"
#include "AbstractBowlingGame.h"
class SingleplayerBowlingGame : public AbstractBowlingGame
{
private:
	std::array<struct bowling_frame_s, 11> frames{};
	int roll_nbr{ 0 };
	int frame_nbr{ 0 };

public:
	int score();
	void roll(int pins_knocked);
};



