#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "../../../!includes/myVector/myVector.h"
#include "graphInfo.h"
#include "Plot.h"

using namespace std;

class Graph
{
public:
	Graph(graphInfo* info);
	void update();	//Updates internal objects with new graph info values
	void draw(sf::RenderWindow& window); //Draws shapes to the screen
										 //resembling a graph.
private:
	graphInfo* _info;
	myVector<sf::Vector2f> _points; //Vector of cartesian coordinates.
	Plot _plotter;	//Object that helps translate points to coords
	sf::Font font;
	sf::Text myTextLabel;
};


#endif // !GRAPH_H