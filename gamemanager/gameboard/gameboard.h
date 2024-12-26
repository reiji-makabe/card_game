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
	bool	isUseJocker;
//	Card	PickPocket; todo

	Player &getPlayer(PlayerType target);

public:
	GameBoard() : dealer(0), player(0), deck(true) isUseJocker(true) {}

	void resetDeck();

	void	dealCard(PlayerType target);
	void	discardAllCard(PlayerType target);

	std::vector<Card> showPlayerCard(PlayerType target);

	int		getPlayerScore() { return player.getScore(); } 
	int		getPlayerMoney() { return player.getMoney(); }
	void	addPlayerScore(int num) { player.addScore(num); }
	void	addPlayerMoney(int num) { player.addMoney(num); }
	void	setPlayerScore(int num) { player.setScore(num); }
	void	setPlayerMoney(int num) { player.setMoney(num); }
	void	setUseJoker(bool is) { isUseJocker = is; }
};

#endif