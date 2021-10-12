#include "Grid.h"

Grid::Grid(int numPredators, int numPrey)
{
	for (int i = 0; i < gridHeight; i++) {
		for (int e = 0; e < gridHeight; e++) {

			if (i == 0 || e == 0 || i == gridHeight - 1 || e == gridWidth - 1) {
				_grid[i][e] = new Wall(Creature::location(i, e));
						//Places walls in the edge spaces.
			}
			else {
				_grid[i][e] = nullptr;
						//Places nullptr in the inside of the grid.
			}
		}
	}

	fillGrid(numPredators, numPrey);
}

Grid::Grid(const Grid& g)
{
	for (int i = 0; i < gridHeight; i++) {
		for (int e = 0; e < gridWidth; e++) {
			if (g._grid[i][e] != nullptr) {

				switch (g._grid[i][e]->typeOf()) {
						//Checks the type of the current location in g; needed
						//for creating a new dynamic creature object of the
						//correct type.
				case CREATURE:
					_grid[i][e] = new Creature(Creature::location(i, e));
					break;
				case PREDATOR:
					_grid[i][e] = new Predator(Creature::location(i, e));
					break;
				case PREY:
					_grid[i][e] = new Prey(Creature::location(i, e));
					break;
				case WALL:
					_grid[i][e] = new Wall(Creature::location(i, e));
					break;

				}
			}
			else {
				_grid[i][e] = nullptr;
			}
		}
	}
}

Grid& Grid::operator=(const Grid& g)
{
	if (this == &g) {
		return *this;
	}

	for (int i = 0; i < gridHeight; i++) {
		for (int e = 0; e < gridWidth; e++) {

			if (_grid[i][e] != nullptr) {
				//Deallocates all creatures in the grid.

				delete _grid[i][e];
				_grid[i][e] = nullptr;

			}
		}
	}

	for (int i = 0; i < gridHeight; i++) {
		for (int e = 0; e < gridWidth; e++) {

			if (g._grid[i][e] != nullptr) {

				switch (g._grid[i][e]->typeOf()) {
						//Checks the type of the current location in g; needed
						//for creating a new dynamic creature object of the
						//correct type.

				case CREATURE:
					_grid[i][e] = new Creature(Creature::location(i, e));
					break;
				case PREDATOR:
					_grid[i][e] = new Predator(Creature::location(i, e));
					break;
				case PREY:
					_grid[i][e] = new Prey(Creature::location(i, e));
					break;
				case WALL:
					_grid[i][e] = new Wall(Creature::location(i, e));
					break;

				}
			}
			else {
				_grid[i][e] = nullptr;
			}
		}
	}
}

Grid::~Grid()
{
	for (int i = 0; i < gridHeight; i++) {
		for (int e = 0; e < gridWidth; e++) {
			if (_grid[i][e] != nullptr) {
				delete _grid[i][e];
			}
		}
	}
}

void Grid::fillGrid(int numPredators, int numPrey)
{
	Creature::location loc;

	while (numPredators > 0) {
		loc = Creature::location(rand() % (gridHeight - 2) + 1, rand() % (gridWidth - 2) + 1);
				//Gets a random location the grid to add the new predator.

		if (_grid[loc._row][loc._col] == nullptr) {
				//Checks if the location has not been filled, otherwise new
				//location is chosen.

			_grid[loc._row][loc._col] = new Predator(loc);
			numPredators--;
		}

	}

	while (numPrey > 0) {
		loc = Creature::location(rand() % (gridHeight - 2) + 1, rand() % (gridWidth - 2) + 1);
				//Gets a random location the grid to add the new predator.
		if (_grid[loc._row][loc._col] == nullptr) {
				//Checks if the location has not been filled, otherwise new
				//location is chosen.

			_grid[loc._row][loc._col] = new Prey(loc);
			numPrey--;

		}
	}
}

void Grid::moveAll()
{
	for (int i = 1; i < gridHeight - 1; i++) {

		for (int e = 1; e < gridWidth - 1; e++) {

	if (_grid[i][e] != nullptr && _grid[i][e]->typeOf() == PREDATOR)
				_grid[i][e]->Move(_grid);

		}
	}
			//Moves all predator objects; Predator moving has priority over prey.

	for (int i = 1; i < gridHeight - 1; i++) {

		for (int e = 1; e < gridWidth - 1; e++) {

			if (_grid[i][e] != nullptr && _grid[i][e]->typeOf() == PREY)
				_grid[i][e]->Move(_grid);

		}
	}
			//Moves all prey objects.

	resetAllMoves();
}

void Grid::breedAll()
{
	for (int i = 1; i < gridHeight - 1; i++) {

		for (int e = 1; e < gridWidth - 1; e++) {

			if (_grid[i][e] != nullptr && _grid[i][e]->typeOf() != WALL)
				_grid[i][e]->Breed(_grid);

		}
	}
			//Calls the breed functions of predators and prey.
}

void Grid::killAll()
{
	for (int i = 1; i < gridHeight - 1; i++) {

		for (int e = 1; e < gridWidth - 1; e++) {

			if (_grid[i][e] != nullptr && _grid[i][e]->typeOf() == PREDATOR) {
				if (static_cast<Predator*>(_grid[i][e])->Die()) {
					_grid[i][e] = nullptr;
				}
			}
		}
	}
			//Calls the kill function for all predators.
}

void Grid::nextGeneration()
{
	moveAll();
	breedAll();
	killAll();
}

void Grid::resetAllMoves()
{
	for (int i = 1; i < gridHeight - 1; i++) {

		for (int e = 1; e < gridWidth - 1; e++) {

			if (_grid[i][e] != nullptr && _grid[i][e]->typeOf() != WALL)
				_grid[i][e]->setMoved(false);

		}
	}
			//Resets the moves for all predators and prey.
}

void Grid::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < gridHeight; i++) {
		for (int e = 0; e < gridWidth; e++) {
			if (_grid[i][e] != nullptr)
				_grid[i][e]->draw(Creature::location(i, e), window);
		}
	}
}

void Grid::commandInput(double mouseX, double mouseY, int command){
	int mouseRowIndex = static_cast<int>(mouseX) / CELLWIDTH;
	int mouseColIndex = static_cast<int>(mouseY) / CELLHEIGHT;

	if (command == 3 || mouseRowIndex >= 1 && mouseRowIndex < gridHeight - 1 && mouseColIndex >= 1 && mouseColIndex < gridWidth - 1) {
		switch (command) {
		case 1:
			if (_grid[mouseRowIndex][mouseColIndex] != nullptr)
				delete _grid[mouseRowIndex][mouseColIndex];
			_grid[mouseRowIndex][mouseColIndex] = new Prey(Creature::location(mouseRowIndex, mouseColIndex));
			break;
		case 2:
			if (_grid[mouseRowIndex][mouseColIndex] != nullptr)
				delete _grid[mouseRowIndex][mouseColIndex];
			_grid[mouseRowIndex][mouseColIndex] = new Predator(Creature::location(mouseRowIndex, mouseColIndex));
			break;
		case 3:
			for (int i = 1; i < gridHeight - 1; i++) {
				for (int e = 1; e < gridWidth -1; e++) {
					if (_grid[i][e] != nullptr) {
						delete _grid[i][e];
						_grid[i][e] = nullptr;
					}
				}
			}
			break;
		}
	}
}

ostream& operator<<(ostream& outs, const Grid& grid)
{
	for (int i = 0; i < gridHeight; i++) {

		outs << "|";

		for (int e = 0; e < gridWidth; e++) {

			if (grid._grid[i][e] != nullptr) {

				switch (grid._grid[i][e]->typeOf()) {
							//Checks the type of the creature in order to
							//print the correct output.

				case CREATURE:
					outs << *static_cast<Creature*>(grid._grid[i][e]);
					break;
				case PREDATOR:
					outs << *static_cast<Predator*>(grid._grid[i][e]);
					break;
				case PREY:
					outs << *static_cast<Prey*>(grid._grid[i][e]);
					break;
				case WALL:
					outs << *static_cast<Wall*>(grid._grid[i][e]);
					break;

				default:
					outs << "";
				}
			}
			else {
				outs << " ";
			}
			outs << "|";
		}
		outs << endl;
	}

	return outs;
}
