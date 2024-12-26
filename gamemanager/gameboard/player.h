#ifndef PLAYE_H
#define PLAYE_H

#include <vector>
#include "card.h"

class Player {
private:
	std::vector<Card>	hand;
	int					score = 0;
	int					money = 0;

public:
	Player(int m);

	std::vector<Card>	showHand() const;
	size_t	handSize() const;

	void	receiveCard(const Card& card);
	Card	discardCard(int index);

	int Player::getMoney()	const { return money; }
	int Player::getScore()	const { return score; }
	void Player::setMoney(int num) { money = num; }
	void Player::setScore(int num) { score = num; }
	void Player::addMoney(int num) { money += num }
	void Player::addScore(int num) { score += num }
};
#endif