#include "gameboard.h"
#include <stdexcept>


Player &GameBoard::getPlayer(PlayerType target) {
	if (target != PlayerType::Player && target != PlayerType::Dealer) {
		throw std::invalid_argument("Invalid PlayerType provided");
	}
	return (target == PlayerType::Player) ? player : dealer;
}

void GameBoard::resetDeck() {
	deck.initializeDeck();
	deck.shuffle();
}

void GameBoard::dealCard(PlayerType target) {
	Player &selectPlayer = getPlayer(target);
	Card card = deck.drawCard();
	selectPlayer.receiveCard(card);
}

void GameBoard::discardAllCard(PlayerType target) {
	Player &selectPlayer = getPlayer(target);
	int size = selectPlayer.handSize();
	while (size > 0) {
		selectPlayer.discardCard(size - 1);
		--size;
	}
}

std::vector<Card> GameBoard::showPlayerCard(PlayerType target) {
	Player &selectPlayer = getPlayer(target);
	return selectPlayer.showHand();
}

int GameBoard::getPlayerScore() {
	return player.getScore();
} 

int GameBoard::getPlayerMoney() {
	return player.getMoney();
}

void GameBoard::adjustPlayerScore(int num) {
	player.adjustScore(num);
}

void GameBoard::adjustPlayerMoney(int num) {
	player.adjustMoney(num);
}

void GameBoard::setPlayerScore(int num) {
	player.setScore(num);
}

void GameBoard::setPlayerMoney(int num) {
	player.setMoney(num);
}
