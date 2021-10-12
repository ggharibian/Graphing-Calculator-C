#ifndef ANIMATE_H
#define ANIMATE_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Sidebar.h"
#include "System.h"
#include "Constants.h"
#include "graphInfo.h"

using namespace std;

class Animate
{
public:
    Animate(graphInfo* info = new graphInfo());
    ~Animate();
    void run(); //Runs the graph program
    void processEvents(); //Processes user input
    void update(); //Makes changes in the graph
    void render(); //Creates the graph
    void Draw(); //Displays the graph
private:
    string userFunction;                //The user inputted function.
    bool help_window_displaying;        //bool checking if the help window is
                                        //displaying
    bool f_entered;                     //bool checking if the user has pressed
                                        //the f key.
    bool functionInputted;              //bool for if a function has been 
                                        //inputted
    sf::RenderWindow window;
    System system;                      //container for all the animated objects
    int command;                        //command to send to system
    sf::Font font;                      //font to draw on main screen
    sf::Text myTextLabel;               //text to draw on main screen
    bool mouseIn;                       //mouse is in the screen
    Sidebar sidebar;                    //rectangular message sidebar
    graphInfo* _info;                   //The info for the graph
    double mouseX, mouseY;              //The x and y coordinates of the mouse
};


#endif // !ANIMATE_H