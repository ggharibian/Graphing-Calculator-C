#ifndef GRAPHINFO
#define GRAPHINFO

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

struct graphInfo {
    string
        equation;

    sf::Vector2f
        graphDimensions = sf::Vector2f(1200, 800),
        origin,
        domain = sf::Vector2f(-10, 10),
        range = sf::Vector2f(-10, 10);
    int
        numPoints = 10000;
};

#endif // !GRAPHINFO