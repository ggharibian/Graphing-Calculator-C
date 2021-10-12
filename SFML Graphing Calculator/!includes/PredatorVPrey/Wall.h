#pragma once
#include "Creature.h"
class Wall: public Creature
{
public:
	Wall(location loc);

	virtual int typeOf();

	friend ostream& operator <<(ostream& outs, const Wall& c);

	void draw(Creature::location l, sf::RenderWindow& window);
private:

};

