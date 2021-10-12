#pragma once
#include "Grid.h"
#include "Creature.h"
class Prey: public Creature
{
public:
	Prey(location loc); //Parameter constructor; Sets prey object to a location.

	void Move(Creature* grid[gridHeight][gridWidth]);	//Moves the prey.

	void Breed(Creature* grid[gridHeight][gridWidth]);	//Creates new prey
									//object and resets the breeding cooldown.

	int typeOf();

	void draw(Creature::location l, sf::RenderWindow& window);

	friend ostream& operator <<(ostream& outs, const Prey& c);
private:
	int _turnSinceBreeding; //Number of turns since last breeding.
};

