#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <ctime>
#include <iostream>
#include "../myVector/myVector.h"
#include "Constants.h"
using namespace std;

class Creature
{
public:

	struct location {	//The location struct will keep track of the row and column
						//position of a creature object in a grid.

		int _row, _col;
				//Varables for row and column positions in the grid.

		location() : _row(-1), _col(-1) {};
				//Default constructor; Sets the location object to an
				//'invalid' value.

		location(int row, int col) : _row(row), _col(col) {};
				//Parameter ctr

		bool isValid() {	//Checks if the location object is within the grid's bounds
			return _row >= 0 && _row < gridHeight&& _col >= 0 && _col < gridWidth;
		}

		friend bool operator ==(const location& lhs, const location& rhs) {
			return lhs._row == rhs._row && lhs._col == rhs._col;
		}

		friend bool operator !=(const location& lhs, const location& rhs) {
			return !(lhs == rhs);
		}

	};

	virtual void draw(location loc, sf::RenderWindow& window);

	Creature(location loc);	//Parameter constructor; Sets creature object to a location.

	bool getMoved();	//Returns the value of '_moved'

	void setMoved(bool moved);	//Sets the value of '_moved'

	virtual void Move(Creature* grid[gridHeight][gridWidth]);	
												//Moves the creature randomly to a space around them

	void MoveTo(Creature* grid[gridHeight][gridWidth], location loc);	
												//Moves the creature to a specific location in the grid.

	virtual void Breed(Creature* grid[gridHeight][gridWidth]); //Creates new 
															   //Creature on
															   //Board.

	virtual int typeOf(); //Returns the type of this creature object (uses the
						  //'constants.h' values)

	int findBlanks(location locs[8],
		Creature* grid[gridHeight][gridWidth]); //Finds all blanks around this
												//creature

	int findThisCreature(location locs[8], 
		Creature* grid[gridHeight][gridWidth], int creatureType); //Finds all
							//creatures of a certain type around this object.

	int findNotThisCreature(location locs[8], 
		Creature* grid[gridHeight][gridWidth], int creatureType); //Finds all
							//creatures not of a certain type around this 
							//object.

	friend ostream& operator <<(ostream& outs, const Creature& c);

private:
	location _loc;	//location of the Creature
	bool _moved;	//flag for if the creature has already moved or not.
};

