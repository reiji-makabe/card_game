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

	int		getMoney()	const;
	int		getScore()	const;
	void	setMoney(int num);
	void	setScore(int num);
	void	adjustMoney(int num);
	void	adjustScore(int num);
};

#endif