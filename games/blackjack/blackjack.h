#ifndef BLACK_JACK_H
#define BLACK_JACK_H

#include "gameboard.h"

class BlackJack {
private:
	GameBoard	&board;

public:
	BlackJack(GameBoard &b) : board(b) {}

	void	play();
};

#endif