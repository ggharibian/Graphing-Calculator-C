#include "CoordinateTranslator.h"

CoordinateTranslator::CoordinateTranslator(graphInfo* info) : _info(info) {

}

sf::Vector2f CoordinateTranslator::translatePointToScreen(sf::Vector2f point)
{
	sf::Vector2f translatedPoint;

	double scalex = _info->graphDimensions.x / (_info->domain.y - _info->domain.x);
	double scaley = _info->graphDimensions.y / (_info->range.y - _info->range.x);

	translatedPoint.x = (point.x - _info->domain.x) * scalex;
	translatedPoint.y = (_info->range.y - point.y) * scaley;

			//NOTE: This expression for translating points is not very 
			//intuitive for this project. I plan on making the coordinate
			//translation to be independant of the origin's location in the
			//future but I need to implement a matrix first. ;)
	
	return translatedPoint;
}

sf::Vector2f CoordinateTranslator::operator()(sf::Vector2f point)
{
	return translatePointToScreen(point);
}
