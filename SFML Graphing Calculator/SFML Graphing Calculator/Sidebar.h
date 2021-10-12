#ifndef SIDEBAR_H
#define SIDEBAR_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "../../../!includes/myVector/myVector.h"
using namespace std;


class Sidebar
{
public:
    Sidebar();
    Sidebar(float left, float width);
    void draw(sf::RenderWindow& window);
    string& operator [](int index);
    void addFunction(string func);

    void saveHistory();
    string getEquationFromHistory(double mouseY);
private:
    sf::RectangleShape rect;            //sidebar rectangle
    myVector<string> items;               //strings to place on the sidebar
    sf::Font font;                      //used to draw text
    sf::Text sb_text;                   //used to draw strings on the window object

    float _left;
    float _width;

    int lastFunctionIndex;

    ifstream history;
};

#endif // SIDEBAR_H