#include "player.h"
#include <stdexcept>

Player::Player(int m) : money(m) {}

std::vector<Card>	Player::showHand() const {
	return hand;
}

size_t	Player::handSize() const {
	return hand.size();
}

void Player::receiveCard(const Card& card) {
	hand.push_back(card);
}

Card discardCard(int index) {
	if (index >= 0 && index < hand.size()) {
		Card card = std::move(hand[index]);
		hand.erase(hand.begin() + index);
	} else {
		throw std::out_of_range("Invalid index for discardCard");
	}
}

int Player::getMoney()	const {
	return money;
}

int Player::getScore()	const {
	return score;
}

void Player::setMoney(int num) {
	money = num;
}

void Player::setScore(int num) {
	score = num;
}

void Player::adjustMoney(int num) {
	money += num
}

void Player::adjustScore(int num) {
	score += num
}
