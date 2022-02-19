#include "MultiplayerBowlingGame.h"


void MultiplayerBowlingGame::roll(int pins_knocked, std::string _player_name) {
    
}

void MultiplayerBowlingGame::addPlayer(std::string _player_name) {
    this->players.emplace(_player_name, Player(this->players.size(), _player_name));
}

Player MultiplayerBowlingGame::getCurrentPlayer() const {
    for (const auto &current_player : this->players){
        if (this->current_player_index == current_player.second.index){
            return current_player.second;
        }
    }
    raise(SIGTERM);
    return Player(0, "");
}

int MultiplayerBowlingGame::score(std::string _player_name) {
    return 1;    
}
