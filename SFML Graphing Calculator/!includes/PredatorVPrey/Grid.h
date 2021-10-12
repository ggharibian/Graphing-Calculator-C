#pragma once
#include <iostream>
#include "Creature.h"
#include "Predator.h"
#include "Prey.h"
#include "Wall.h"
using namespace std;

class Grid
{
public:
	Grid(int numPredators = 0, int numPrey = 0); //Creates a new grid with certain
										 //number of predators and prey.

	//Big Three

	Grid(const Grid& g);

	Grid& operator =(const Grid& g);

	~Grid();

	void fillGrid(int numPredators, int numPrey); //Fills the grid with
												  //predators and prey.

	void moveAll();	//Moves all predators and prey on the board.

	void breedAll();//Calls the breed function of all predators and prey.

	void killAll(); //Calls the kill function of all predators.

	void nextGeneration();	//Moves the grid to the next generation.

	void resetAllMoves();	//Resets all move flags for creatures.

	void draw(sf::RenderWindow& window);

	void commandInput(double mouseX, double ymouse, int command);

	friend ostream& operator <<(ostream& outs, const Grid& grid);
private:
	Creature* _grid[gridHeight][gridWidth];
};

