#include <array>
#include "Frame.h"
#include "AbstractGame.h"
class SinglePlayerGame : public AbstractGame
{
private:
	std::array<struct frame_s, 11> frames{};
	int roll_nbr{ 0 };
	int frame_nbr{ 0 };

public:
	int score();
	void roll(int pins_knocked);
};



