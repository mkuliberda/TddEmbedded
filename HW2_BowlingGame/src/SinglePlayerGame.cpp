#include "SinglePlayerGame.h"

int SinglePlayerGame::score()
{
	int final_score = 0;

	for (struct frame_s &frame: this->frames) {
		final_score += (frame.scores[0] + frame.scores[1] + frame.bonus);
	}

	return final_score;
}

void SinglePlayerGame::roll(int pins_knocked)
{
	if (this->roll_nbr < 21) {
		if (this->roll_nbr % 2 == 0) { //this is 1st roll in frame
			if (this->frame_nbr == 10 && this->frames[this->frame_nbr].extra_roll == false) {
				this->frames[this->frame_nbr].scores[0] = 0;
			}
			else {
				this->frames[this->frame_nbr].scores[0] = pins_knocked;
			}
			if (this->frames[this->frame_nbr].after_strike == true) {
				this->frames[this->frame_nbr-1].bonus += pins_knocked;
			}
			if (pins_knocked == 10) {
				this->frames[this->frame_nbr + 1].after_strike = true;
				this->frames[this->frame_nbr].strike = true;
				if (this->frame_nbr == 9) { //last frame special case
					this->frames[this->frame_nbr + 1].extra_roll = true;
					this->frames[this->frame_nbr + 1].after_strike = false;
					this->frames[this->frame_nbr + 1].after_spare = false;
					this->frames[this->frame_nbr].strike = false;
					this->roll_nbr--;
				}
				this->roll_nbr++;
			}
			if (this->frames[this->frame_nbr].after_spare == true) {
				this->frames[this->frame_nbr-1].bonus += pins_knocked;
			}
		}
		if (this->roll_nbr % 2 == 1) {	//this is 2nd roll in frame
			if (this->frames[this->frame_nbr].strike == false) {
				this->frames[this->frame_nbr].scores[1] = pins_knocked;
			}
			if (this->frames[this->frame_nbr].after_strike == true) {
				this->frames[this->frame_nbr-1].bonus += pins_knocked;
			}
			if (this->frames[this->frame_nbr].scores[0] + this->frames[this->frame_nbr].scores[1] == 10 && this->frames[this->frame_nbr].scores[0] != 10) { //this is spare
				this->frames[this->frame_nbr + 1].after_spare = true;
				if (this->frame_nbr == 9) { //special case for last frame
					this->frames[this->frame_nbr + 1].extra_roll = true;
					this->frames[this->frame_nbr + 1].after_spare = false;
					this->frames[this->frame_nbr + 1].after_strike = false;
				}
			}
		}
	this->frame_nbr += (roll_nbr % 2);
	this->roll_nbr ++;
	}
}
