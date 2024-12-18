#ifndef DECK_H
#define DECK_H

#include <vector>
#include <random>
#include "Card.h"

class Deck {
private:
	std::vector<Card> cards;
	std::default_random_engine engine;

public:
	Deck(bool isUseJoker);

	void	initializeDeck(bool isUseJoker);
	void	shuffle();
	size_t	size() const;
	void	addCard(const Card& card);
	void	drawCard();
	size_t	size() const;
	void	printDeck() const;
};

#endif