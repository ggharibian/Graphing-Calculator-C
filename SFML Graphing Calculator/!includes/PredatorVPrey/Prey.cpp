#include "Prey.h"

Prey::Prey(location loc) : Creature(loc), _turnSinceBreeding(0) {}

void Prey::Move(Creature* grid[gridHeight][gridWidth])
{
	if (!getMoved()) {
				//Checks if the prey has moved already.

		Creature::Move(grid);
				//Call to superclass move function.

		setMoved(true);

		_turnSinceBreeding++;
	}
}

void Prey::Breed(Creature* grid[gridHeight][gridWidth])
{
	if (_turnSinceBreeding > turnsUntilBreedingPrey) {
				//Checks to see if the prey has survived a certain amount of
				//turns since last breeding.

		_turnSinceBreeding = 0;

		Creature::location emptySpaces[8];

		int size = findBlanks(emptySpaces, grid);

		if (size > 0) {
				//Checks 
			Creature::location loc;

			loc = emptySpaces[rand() % size];

			grid[loc._row][loc._col] = new Prey(loc);
		}

	}
}

int Prey::typeOf()
{
	return PREY;
}

void Prey::draw(Creature::location l, sf::RenderWindow& window)
{
	sf::CircleShape circ;
	circ.setRadius(CELLWIDTH / 2.0);
	circ.setPosition(sf::Vector2f(l._row * CELLHEIGHT + 1, l._col * CELLWIDTH + 1));
	circ.setFillColor(sf::Color(173, 216, 230, 255));
	window.draw(circ);
}

ostream& operator<<(ostream& outs, const Prey& c)
{
	return (outs << "O");
}