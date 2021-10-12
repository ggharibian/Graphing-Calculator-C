#include "Creature.h"
#include <random>
#include <ctime>

void Creature::draw(location loc, sf::RenderWindow& window)
{

}

Creature::Creature(location loc): _loc(loc), _moved(false)
{
	srand(time(NULL));
}

bool Creature::getMoved()
{
	return _moved;
}

void Creature::setMoved(bool moved)
{
	_moved = moved;
}

void Creature::Move(Creature* grid[gridHeight][gridWidth])
{
	Creature::location emptySpaces[8];

	int size = findBlanks(emptySpaces, grid);
			//Sets emptySpaces to a list of empty spaces around the creature.

	if (size > 0) {
				//Checks if there are any empty spaces around the creature.

		Creature::location loc;

		loc = emptySpaces[rand() % size];
					//Randomly finds an empty space for the creature to move 
					//to.
				//The loop runs until a valid location has been chosen.
				//Note: this method has been used multiple times in all child
				//classes
		MoveTo(grid, loc);

	}
}

void Creature::MoveTo(Creature* grid[gridHeight][gridWidth], location loc)
{
	if (grid[loc._row][loc._col] == nullptr && !_moved) {
				//Only moves the creature if it hasn't already moved, and the
				//space is empty.

		//////////
		Creature* c = grid[_loc._row][_loc._col];

		grid[_loc._row][_loc._col] = nullptr;

		grid[loc._row][loc._col] = c;

		_loc = loc;
		//////////
				//Moves the creature to a new location

		setMoved(true);
				//triggers moved flag so creature doesn't move again.
	}
}
int Creature::findBlanks(Creature::location locs[8], Creature* grid[gridHeight][gridWidth])
{
	int index = 0;

	for (int i = _loc._row - 1; i <= _loc._row + 1; i++) {
		for (int e = _loc._col - 1; e <= _loc._col + 1; e++) {
					//Double foor loop iterates through all elements around
					//the creature in a 3 x 3 grid.

			if (Creature::location(i, e) != _loc && Creature::location(i, e).isValid() && grid[i][e] == nullptr) {

				locs[index++] = Creature::location(i, e);

			}

		}
	}

	return index;
}

int Creature::findThisCreature(Creature::location locs[8],
	Creature* grid[gridHeight][gridWidth], int creatureType)
{
	int index = 0;

	for (int i = _loc._row - 1; i <= _loc._row + 1; i++) {
		for (int e = _loc._col - 1; e <= _loc._col + 1; e++) {
					//Double foor loop iterates through all elements around
					//the creature in a 3 x 3 grid.

			if (Creature::location(i, e) != _loc &&
				Creature::location(i, e).isValid() && grid[i][e] != nullptr &&
				grid[i][e]->typeOf() == creatureType) {

						//Checks if the current location is empty, inside the
						//grid, and of the specific creature type

				locs[index++] = Creature::location(i, e);

			}

		}
	}

	return index;
}

int Creature::findNotThisCreature(Creature::location locs[8], Creature* grid[gridHeight][gridWidth], int creatureType)
{
	int index = 0;

	for (int i = _loc._row - 1; i <= _loc._row + 1; i++) {
		for (int e = _loc._col - 1; e <= _loc._col + 1; e++) {
					//Double foor loop iterates through all elements around
					//the creature in a 3 x 3 grid.

			if (Creature::location(i, e) != _loc && 
				Creature::location(i, e).isValid() && grid[i][e] != nullptr &&
				grid[i][e]->typeOf() != creatureType) {
					//Checks if the current location is in the grid, and of
					//the same creature type as desired

				locs[index++] = Creature::location(i, e);

			}

		}
	}

	return index;
}

void Creature::Breed(Creature* grid[gridHeight][gridWidth])
{
	Creature::location emptySpaces[8];

	int size = findBlanks(emptySpaces, grid);

	if (size > 0) {
				//Checks if there are any empty spaces around the creature.

		Creature::location loc;
		
		loc = emptySpaces[rand() % size];

		grid[loc._row][loc._col] = new Creature(loc);
				//Creates a new creature in an empty spaces.
	}
}

int Creature::typeOf()
{
	return CREATURE;
}

ostream& operator<<(ostream& outs, const Creature& c)
{
	return (outs << "C");
}
