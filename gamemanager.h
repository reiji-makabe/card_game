#ifndef GAME_MANAGER
#define GAME_MANAGER

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

	void	startBlackJack();
	void	startPoker();

public:
	GameManager() : mode(GameRule::Start), board {}

	void	getGameMode();
	void	startGame();
};

#endif