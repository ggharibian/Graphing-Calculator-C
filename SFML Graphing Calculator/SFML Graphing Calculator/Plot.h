#ifndef PLOT_H
#define PLOT_H

#include "../../../!includes/myVector/myVector.h"
#include "graphInfo.h"
#include "CoordinateTranslator.h"
#include "../../../!includes/Shuntting Yard/ShunttingYard.h"
#include "../../../!includes/Shuntting Yard/Tokenizer.h"
#include "../../../!includes/Shuntting Yard/RPN.h"
#include <SFML/Graphics.hpp>
class Plot
{
public:

	Plot(graphInfo* info);

	void setInfo(); //Updates graph info.

	myVector<sf::Vector2f> operator ()();	//Returns a vector of screen coordinates.

public:
	graphInfo* _info;
	Queue<Token*> _postfix; //A queue of a equation in postfix notation.
	CoordinateTranslator c; //Object that translates coordinates to and from 
							//screen and cartesian points.
};

#endif // !PLOT_H

