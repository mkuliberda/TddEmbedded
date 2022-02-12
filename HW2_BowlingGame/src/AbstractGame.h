class AbstractGame
{
public:
	virtual int score() = 0;
	virtual void roll(int pins_knocked) = 0;
};