#include "snarkbot.h"

#include <vector>
#include <string>
#include "randomengine.h"

const std::vector<std::string> SnarkBot::wrongnum = {
		"Oh, what a bold explorer you are!",
		"Fascinating! Who knew nonexistent numbers could inspire?",
		"You're testing reality—too bad that number's from another universe.",
		"Bravo! You dared venture into the realm of the nonexistent.",
		"That number's in a parallel universe, beyond the limits of reality.",
};

const std::vector<std::string> SnarkBot::nonum = {
		"I see! You've invented your own numeric system. Bold move!",
		"Nice try! But letters and symbols don't work as numbers... yet.",
		"Ah, looks like we're playing Scrabble, not entering numbers!",
		"Wow, a word instead of a number? I admire your linguistic skills.",
		"Your challenge to the concept of numbers is impressive, but I'm too primitive for that.",
		"I see, abstract art meets numbers. But I'm too literal for it.",
};

std::vector<int> SnarkBot::usedWrongnum;
std::vector<int> SnarkBot::usedNonum;

std::string SnarkBot::getRandMsg(SnarkBot::MessageType mes) {
	std::vector<std::string> *msgs;
	std::vector<std::string> *usedmsgs;

	if (mes == SnarkBot::MessageType::WrongNumber) {
		msgs = &SnarkBot::wrongnum;
		usedmsgs = &SnarkBot::usedWrongnum;
	} else if (mes == SnarkBot::MessageType::NotNumber) {
		msgs = &nonum;
		usedmsgs = &usedNonum;
	} else {
		return ""; // todo: exception
	}

	if (msgs->size() == usedmsgs->size()) {
		return "";
	}

	int index;
	std::string result;

	do {
		index = RandomEngine::getRandomInt(0, msgs.size() - 1);
	} while (std::find(usedmsgs->begin(), usedmsgs->end(), index) != usedmsgs->end());

	result = (*msgs)[index];
	usedmsgs->push_back(index);
	return result;
}
