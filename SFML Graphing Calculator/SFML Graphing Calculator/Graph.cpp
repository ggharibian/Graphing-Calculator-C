#include "Graph.h"

Graph::Graph(graphInfo* info) : _info(info), _plotter(info) {}

void Graph::update()
{
	if (_info->equation.size() != 0)
		_points = _plotter();
		//Recieves a vector of points to graph to the canvas.
}

void Graph::draw(sf::RenderWindow& window)
{
	sf::CircleShape circle(1);
	sf::RectangleShape line(sf::Vector2f(5,_info->graphDimensions.y));
	line.setPosition(sf::Vector2f(_info->origin.x + line.getSize().x / 2, 0));
	window.draw(line);
		//Vertical Graph Axis 

	line = sf::RectangleShape(sf::Vector2f(_info->graphDimensions.x, 5));
	line.setPosition(sf::Vector2f(0, _info->origin.y - line.getSize().y / 2));
	window.draw(line);
		//Horizontal Graph Axis 

	circle.setFillColor(sf::Color(255, 0, 0, 255));
		//Dot representing a point on the graph.
	if (_info->equation.size() != 0) {

		for (int i = 0; i < _points.getSize(); i++) {
			circle.setPosition(_points[i].x - circle.getRadius() / 2, 
				_points[i].y - circle.getRadius());
			circle.setFillColor(sf::Color(static_cast<int>(255 * i /
				_info->numPoints), 255 - static_cast<int>(255 * i /
					_info->numPoints), 255 - static_cast<int>(255 * i / 
						_info->numPoints), 255));
			window.draw(circle);
		}		//For loop draws all the points to the window.
	}
}
