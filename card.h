#include <iostream>
#include <vector>
#include <random>
#include <chrono>

enum class Rank {
	Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Joker
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

	std::string toString() const {
		std::string	S;
		int			R = static_cast<int>(rank);

		switch (suit) {
			case Suit::Heart:	S = "H"; break;
			case Suit::Spade:	S = "S"; break;
			case Suit::Diamond:	S = "D"; break;
			case Suit::Club:	S = "C"; break;
			case Suit::Joker:	S = "J"; break;
			default: S = "?"; break;
		}
		return S + std::to_string(R);
	}
};

class Deck {
private:
	std::vector<Card> cards;
	std::default_random_engine engine;

public:
	Deck() {
		// create random engine
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		engine = std::default_random_engine(seed);

		// add cards
		for (int s=0; s<4; s++) {
			for (int r=0; r<13; r++) {
				cards.emplace_back(static_cast<Suit>(s), static_cast<Rank>(r));
			}
		}
		cards.emplace_back(Suit::Joker, Rank::Joker);
	}

	void shuffle() {
		std::shuffle(cards.begin(), cards.end(), engine);
	}

	size_t size() const {
		return cards.size();
	}

	void printDeck() const {
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
};

int	main(void) {
	Deck deck;
	deck.printDeck();
	std::cout << "shuffling...\n";
	deck.shuffle();
	deck.printDeck();
	return 0;
}
