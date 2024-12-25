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
	GameBoard(int money, bool useJoker) : dealer(0), player(money), deck(useJoker) {}

	void resetDeck();

	void dealCard(PlayerType target);

	void discardAllCard(PlayerType target);

	std::vector<Card> showPlayerCard(PlayerType target);

	int GameBoard::getPlayerScore() { return player.getScore(); } 
	int GameBoard::getPlayerMoney() { return player.getMoney(); }
	void GameBoard::adjustPlayerScore(int num) { player.adjustScore(num); }
	void GameBoard::adjustPlayerMoney(int num) { player.adjustMoney(num); }
	void GameBoard::setPlayerScore(int num) { player.setScore(num); }
	void GameBoard::setPlayerMoney(int num) { player.setMoney(num); }
};

#endif