#include "gamemanager.cpp"
#include <iostream>
#include <limit>



void displayInsult(SnarkBot::MessageType type) {
	static bool flag = false;
	std::string msg;

	if (flag) {
		std::cout << "Bye.\n";
		exit(0); // todo:Maybe exit isn't appropriate because of destructors and such
	}

	msg = SnarkBot::getRandMsg(type);
	if (msg == "") {
		std::cout << "Are you satisfied now? It seems my vocabulary is insufficient to praise you any further.\n";
		std::cout << "Please choose whether to end the game or proceed properly.\n";
		flag = true;
	}
	std::cout << msg << std::endl;
}

void GameManager::getGameMode() {
	std::cout << "Welcome player!\nWhat games do you play?\n";
	std::cout << "1:Black Jack\n2:Draw Poker\n";

	int num;

	// input process
	while (true) {
		std::cin >> num;

		if (std::cin) {
			if (static_cast<int>(GameRule::Start) <= num && num <= static_cast<int>(GameRule::End)) {
				break;
			} else {
				displayInsult(SnarkBot::MessageType::WrongNumber);
			}
		} else {
			displayInsult(SnarkBot::MessageType::NotNumber);
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), "\n");
		}
	}
	mode = static_cast<GameRule>(num);
}

void GameManager::startGame() {
	switch (mode) {
		case GameRule::BlackJack:
			startBlackJack();
			break;
		case GameRule::Poker:
			startPoker();
			break;
		default:
			break;
			// throw exception
	}
}