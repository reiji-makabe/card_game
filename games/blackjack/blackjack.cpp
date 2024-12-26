#include "blackjack.h"
#include <iostream>

/* using setw

todo displayGameScreen()

+----------------------+----------------------+
|      [Score]         |      [Money]         |
|      17              |      1000            |
+----------------------+----------------------+

Dealer: ♣10 ? 
Player: ♠A ♡K | Score: 17

---------------------------------------------
[1] Hit   [2] Stand   [3] Double Down
---------------------------------------------
Choose an option:
*/

void	BlackJack::play() {
	bool	isGameActive = true;

	// todo: displayGameScreen();
	cout << "Welcome, Player!\n";
	while (isGameActive) {
		cout << "Dealing...\n";
		for (int i=0; i<2; i++) {
			board.dealCard(PlayerType::Dealer);
			board.dealCard(PlayerType::Player);
		}
	}
}