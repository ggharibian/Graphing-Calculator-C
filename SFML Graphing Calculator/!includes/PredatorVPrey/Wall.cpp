#include "Wall.h"

Wall::Wall(location loc) : Creature(loc) {}

int Wall::typeOf()
{
	return WALL;
}

void Wall::draw(Creature::location l, sf::RenderWindow& window)
{
	sf::RectangleShape rect;

	rect.setSize(sf::Vector2f(CELLHEIGHT, CELLWIDTH));

	rect.setFillColor(sf::Color(230, 230, 230, 255));

	rect.setPosition(sf::Vector2f(l._row * CELLHEIGHT + 1, l._col * CELLWIDTH + 1));

	window.draw(rect);
}

ostream& operator<<(ostream& outs, const Wall& c)
{
	return (outs << "Z");
}
