#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "gameboard.h"
#include "snarkbot.h"

// When treating a non-console as screen output,
// create a new display class and have the game manager class manage it

enum class GameRule {
	Start, BlackJack, Poker, End
};

class GameManager {
private:
	GameRule	mode;
	GameBoard	board;

public:
	GameManager() : mode(GameRule::Start), board { board.setPlayerMoney(1000); }
	// todo:Change starting amount depending on difficulty?

	void	getGameMode();
	void	startGame();
};

#endif