#include "card.h"

std::string Card::toString() const {
	std::string	S, R;

	if (rank <= 10) {
		R = std::to_string(static_cast<int>(rank));
	} else {
		switch(rank) {
			case Rank::Jack:	R = "J"; break;
			case Rank::Queen:	R = "Q"; break;
			case Rank::King:	R = "K"; break;
			case Rank::Joker:	R = "J"; break;
			default: R = "?"; break;
		}
	}
	switch (suit) {
		case Suit::Heart:	S = "H"; break;
		case Suit::Spade:	S = "S"; break;
		case Suit::Diamond:	S = "D"; break;
		case Suit::Club:	S = "C"; break;
		case Suit::Joker:	S = "J"; break;
		default: S = "?"; break;
	}
	return S + R;
}