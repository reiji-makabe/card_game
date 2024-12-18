#include "deck.h"
#include "gameboard.h"

int	main(void) {
	Deck deck;
	deck.printDeck();
	std::cout << "shuffling...\n";
	deck.shuffle();
	deck.printDeck();
	return 0;
}