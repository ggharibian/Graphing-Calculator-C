#include "Plot.h"

Plot::Plot(graphInfo* info) : _info(info), c(_info) {
	setInfo();
}

void Plot::setInfo()
{ //Calculates the postfix expression for a specific string equation.

	Tokenizer t(_info->equation);

	ShunttingYard s(t.getTokens());

	_postfix = s.getPostFix();

	_info->origin = c(sf::Vector2f(0, 0));
		//The origin is recalculated after every frame in case the user pans 
		//the screen.
}

myVector<sf::Vector2f> Plot::operator()()
{
	setInfo();

	RPN r(_postfix);

	myVector<sf::Vector2f> v;

	for (int i = 0; i <= _info->numPoints - 1; i++){
		sf::Vector2f point;

		point.x = (_info->domain.y - _info->domain.x) / (_info->numPoints - 1) * i + _info->domain.x;
		point.y = r(point.x);

		point = c(point);

		v.push_back(point);
	}	
			//Loop calculates numPoints number of coordinates that are 
			//equadistant from eachother and adds them to a vector to 
			//be used by the graph class.

	return v;
}
