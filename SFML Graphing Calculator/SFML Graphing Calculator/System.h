#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <SFML\Graphics\RenderWindow.hpp>
#include "Graph.h"
#include "graphInfo.h"

using namespace std;

class System
{
public:
	System(graphInfo* info = new graphInfo());	//Constructor; passes in
												//dynamic graphInfo object

	void Step(int command, double mouseX, double mouseY); //Processes user
														  //input commands

	void displayFunctionEnterBox(sf::RenderWindow& window, string& function);
													//Display's the UI for
													//function input.

	void displayHelpWindow(sf::RenderWindow& window);
												//Displays the help menu UI

	void Draw(sf::RenderWindow& window);	//Draws the graph.

private:

	sf::Font _font;
	sf::Text _text;
			//Font and text stuff. 

	graphInfo* _info;	//info pointer; same info through all classes.
	Graph _g;		//Private graph object that will display all changes.
};

#endif // !SYSTEM_H

