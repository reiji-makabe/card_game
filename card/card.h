#ifndef CARD_H
#define CARD_H

#include <string>

enum class Rank {
	Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Joker
};

enum class Suit {
	Heart, Spade, Diamond, Club, Joker
};

class Card {
private:
	Suit	suit;
	Rank	rank;

public:
	Card(Suit s, Rank r) : suit(s), rank(r) {}
	Suit getSuit() const { return suit; }
	Rank getRank() const { return rank; }
	std::string toString() const;

};

#endif