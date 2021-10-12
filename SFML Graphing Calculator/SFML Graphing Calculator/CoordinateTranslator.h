#ifndef COORDINATETRANSLATOR_H
#define COORDINATETRANSLATOR_H

#include "graphInfo.h"
#include <SFML/Graphics.hpp>
using namespace std;

class CoordinateTranslator
{
public:
	CoordinateTranslator(graphInfo* info);

	sf::Vector2f translatePointToScreen(sf::Vector2f point); //Translates 
															 //points to 
															 //screen coords.

	sf::Vector2f operator ()(sf::Vector2f point); //Calls 
												  //translatePointToScreen().

private:
	graphInfo* _info;
};


#endif // !COORDINATETRANSLATOR_H
