#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"
#include "randomengine.h"

class Deck {
private:
	std::vector<Card> cards;

public:
	Deck(bool isUseJoker);

	void	initializeDeck(bool isUseJoker);
	void	shuffle();
	void	addCard(const Card& card);
	void	drawCard();
	void	printDeck() const;

	size_t size() const { return cards.size(); }

};

#endif