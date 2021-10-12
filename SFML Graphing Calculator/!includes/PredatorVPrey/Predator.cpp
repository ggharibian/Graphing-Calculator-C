#include "Predator.h"

Predator::Predator(location loc) : Creature(loc), _turnSinceBreeding(0), _turnSinceLastMeal(0) {}

void Predator::Move(Creature* grid[gridHeight][gridWidth]){

	if (!getMoved()) {

		Creature::location preySpaces[8];

		int size = findThisCreature(preySpaces, grid, PREY);

		if (size > 0) {
				//Checks if there are any preys near the predator.

			Creature::location loc;

			loc = preySpaces[rand() % size];

				//Finds a random prey space.

			delete grid[loc._row][loc._col];
				//Deletes the prey for the grid.

			grid[loc._row][loc._col] = nullptr;

			Creature::MoveTo(grid, loc);

			_turnSinceLastMeal = 0;
		}
		else {
			Creature::Move(grid);
			_turnSinceLastMeal++;
		}

		_turnSinceBreeding++;
	}
}

void Predator::Breed(Creature* grid[gridHeight][gridWidth])
{
	if (_turnSinceBreeding > turnsUntilBreedingPredator) {
				//Checks to see if the predator has survived a certain number
				//of generations since Breeding.

		Creature::location emptySpaces[8];

		int size = findBlanks(emptySpaces, grid);

		if (size > 0) {
					//Checks if there are any empty spaces around the 
					//creature.

			Creature::location loc;

			
			loc = emptySpaces[rand() % size];


			grid[loc._row][loc._col] = new Predator(loc);
				//A new Predator is created in the grid.

			_turnSinceBreeding = 0;
		}

	}
}

bool Predator::Die()
{
	if (_turnSinceLastMeal > turnsUntilStarvationPredator) {
				//Checks to see how many turns have passed since last meal
		delete this;
		return true;
				//returns true if the predator has been killed.
	}

	return false;
			//return false if not kill.
}

int Predator::typeOf()
{
	return PREDATOR;
}

void Predator::draw(Creature::location l, sf::RenderWindow& window)
{

	sf::CircleShape circ(CELLWIDTH / 2.0, 4);
	circ.setPosition(sf::Vector2f(l._row * CELLHEIGHT + 1, l._col * CELLWIDTH + 1));
	circ.setFillColor(sf::Color(255, 0, 0, 255));
	window.draw(circ);

}

ostream& operator<<(ostream& outs, const Predator& c)
{
	return (outs << "X");
}
