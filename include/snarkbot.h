#ifndef SNARK_BOT
#define SNARK_BOT

#include <vector>
#include <string>
#include <algorithm>
#include "randomengine.h"

enum class MessageType {
	WrongNumber, NotNumber
};

class SnarkBot {
private:
	static const std::vector<std::string> wrongnum;
	static const std::vector<std::string>;

	static const std::vector<int> usedWrongnum;
	static const std::vector<int> usedNonum;

public:
	static std::string getRandMsg(MessageType mes);
};

#endif