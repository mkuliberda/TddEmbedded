

class AbstractBowlingGame
{
public:
	const int max_frame_nbr {10};
	const int max_roll_nbr {21};
	virtual int score() = 0;
	virtual void roll(int pins_knocked) = 0;
};