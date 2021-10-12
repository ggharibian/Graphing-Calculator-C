#ifndef CONSTANTS_H
#define CONSTANTS_H

enum {

	CREATURE, 
	PREDATOR, 
	PREY, 
	WALL, 

	gridWidth = 45, 
	gridHeight = 45, 
	turnsUntilBreedingPredator = 8,
	turnsUntilStarvationPredator = 3,
	turnsUntilBreedingPrey = 3,

	SCREENWIDTH = 2000,
	SCREENHEIGHT = 2000,
	CELLWIDTH = SCREENWIDTH / gridWidth,
	CELLHEIGHT = SCREENWIDTH / gridHeight,

	FRAMERATE = 0


};

#endif // !CONSTANTS_H
