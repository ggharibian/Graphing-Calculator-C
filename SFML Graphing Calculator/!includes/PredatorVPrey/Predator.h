#pragma once
#include "Creature.h"
#include "Grid.h"

class Predator: public Creature
{
public:

	Predator(location loc); //Parameter constructor; Sets predator object to a location.

	void Move(Creature* grid[gridHeight][gridWidth]);	//Moves the Predator;
														//Prioritizes eating
														//first.

	void Breed(Creature* grid[gridHeight][gridWidth]);	//Creates new predator
									//object and resets the breeding cooldown.

	bool Die();	//Kills the Predator if it has been alive for too long.

	virtual int typeOf();

	friend ostream& operator <<(ostream& outs, const Predator& c);

	void draw(Creature::location l, sf::RenderWindow& window);

private:
	int _turnSinceLastMeal;	//Number of turns since last meal
	int _turnSinceBreeding;	//Number of turns since last Breeding
};

