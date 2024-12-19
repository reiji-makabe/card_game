#ifndef RANDOM_ENGINE
#define RANDOM_ENGINE

#include <random>
#include <chrono>

class RandomEngine {
private:
	static unsigned initializeSeed() {
		return std::chrono::system_clock::now().time_since_epoch().count();
	}

public:
	static std::default_random_engine& getEngine() {
		static std::default_random_engine engine(initializeSeed());
	}

	static int getRandomInt(int min, int max) {
		std::uniform_int_distribution<int> dist(min, max);
		return dist(getEngine());
	}

	static double getRandomDouble(double min, double max) {
		std::uniform_real_distribution<double> dist(min, max);
		return dist(getEngine());
	}
};

#endif