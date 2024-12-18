#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "player.h"
#include "deck.h"

enum class PlayerType {
	Dealer, Player
};

class GameBoard {
private:
	Player	dealer;
	Player	player; // todo:Not expandable enogh - For example, no multiplayer support
	Deck	deck;
//	Card	PickPocket; todo

	Player &getPlayer(PlayerType target);

public:
	void resetDeck();

	void dealCard(PlayerType target);

	void discardAllCard(PlayerType target);

	std::vector<Card> showPlayerCard(PlayerType target);

	int getPlayerScore();
	int getPlayerMoney();
	void adjustPlayerScore(int num);
	void adjustPlayerMoney(int num);
	void setPlayerScore(int num);
	void setPlayerMoney(int num);
};

#endif