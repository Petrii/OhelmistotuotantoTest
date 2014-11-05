//Kommentointia
#include <iostream>
#include <ctime>

class Dice {
	public:
		void initialize();
		double roll();
};

class Counter {
	public:
		void reset();
		int getCount();
		void increment();
	private:
		int count;
};

class Inspector {
	public:
		void setLimits(double min, double max);
		bool isInLimits(double roll);
	private:
		double min;
		double max;
};

int main() {
	Dice dice;
	Counter counter1, counter2, i;
	Inspector inspector;

	dice.initialize();
	counter1.reset(); counter2.reset(), i.reset();
	inspector.setLimits(0.0, 0.5);
	while (i.getCount() < 100) {
		if (inspector.isInLimits(dice.roll())) {
			counter1.increment();
		} else {
			counter2.increment();
		}

		i.increment();
	}
	std::cout << counter1.getCount() << "\n";
	std::cout << counter2.getCount() << "\n";
	return 0;
}

void Dice::initialize() {
	srand(time(NULL));
}

double Dice::roll() {
	return (rand() / 10000);
}

void Counter::reset() {
	count = 0;
}

int Counter::getCount() {
	return count;
}

void Counter::increment() {
	count++;
}

void Inspector::setLimits(double min, double max) {
	this->min = min;
	this->max = max;
}

bool Inspector::isInLimits(double roll) {
	if (roll >= min && roll <= max) {
		return true;
	} else {
		return false;
	}
}
