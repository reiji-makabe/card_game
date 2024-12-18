#include "deck.h"
#include <chrono>
#include <algorithm>

Deck::Deck(bool isUseJoker) {
	// create random engine
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	engine = std::default_random_engine(seed);

	initializeDeck(isUseJoker);
}

void Deck::initializeDeck(bool isUseJoker) {
	cards.clear();

	for (int s = 0; s < 4; ++s) {
		for (int r = 1; r <= 13; ++r) {
			cards.emplace_back(static_cast<Suit>(s), static_cast<Rank>(r));
		}
	} if (isUseJoker) {
		cards.emplace_back(Suit::Joker, Rank::Joker);
	}
}

void Deck::shuffle() {
	std::shuffle(cards.begin(), cards.end(), engine);
}

size_t Deck::size() const {
	return cards.size();
}

void Deck::addCard(const Card& card) {
	cards.push_back(card);
}

void Deck::drawCard() {
	if (cards.empty()) {
		throw std::out_of_range("Deck is empty");
	}
	Card card = std::move(cards.back());
	cards.pop_back();
	return card;
}

size_t Deck::size() const { return cards.size(); }

void Deck::printDeck() const {
	int i = 0;
	for (const auto& card : cards) {
		std::cout << card.toString() << " ";
		i++;
		if (i == 13) {
			i = 0;
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}