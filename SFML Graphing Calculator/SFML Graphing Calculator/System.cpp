#include "System.h"

System::System(graphInfo* info) : _info(info), _g(info) {

	if (!_font.loadFromFile("arial.ttf")) {
		cout << "Sidebar() CTOR: Font failed to load" << endl;
		cin.get();
		exit(-1);
	}
			//Loading font stuff.

	_text.setFont(_font);
}

void System::displayFunctionEnterBox(sf::RenderWindow& window, string& function)
{
	sf::RectangleShape functionBox(sf::Vector2f(_info->graphDimensions.x, _info->graphDimensions.y / 8));
	functionBox.setPosition(0, 20);
	functionBox.setFillColor(sf::Color(128, 128, 128, 255));
	functionBox.setOutlineColor(sf::Color::Yellow);
	window.draw(functionBox);
			//Creates a background for the function display.

	_text.setFont(_font);
	_text.setPosition(functionBox.getPosition().x, functionBox.getPosition().y - functionBox.getSize().y / 8);
	_text.setCharacterSize(_info->graphDimensions.y / 8);
	_text.setFillColor(sf::Color::Yellow);
	_text.setString(function);
	window.draw(_text);
			//Displays the function
}

void System::displayHelpWindow(sf::RenderWindow& window)
{
	sf::RectangleShape helpBox(sf::Vector2f(_info->graphDimensions.x / 2, _info->graphDimensions.y / 2));
	helpBox.setPosition(sf::Vector2f(_info->graphDimensions.x / 4, _info->graphDimensions.y / 16));
	helpBox.setFillColor(sf::Color(90, 90, 90, 255));
	helpBox.setOutlineColor(sf::Color::Yellow);
	window.draw(helpBox);
			//Background of the help window.

	_text.setFont(_font);
	_text.setCharacterSize(25);
	_text.setPosition(sf::Vector2f(helpBox.getPosition().x + helpBox.getSize().x / 2 - 60, helpBox.getPosition().y + 15));
	_text.setFillColor(sf::Color(230, 150, 230, 255));
	_text.setString("Help Screen");
	window.draw(_text);
			//Title font of the help window.

	_text.setPosition(sf::Vector2f(helpBox.getPosition().x + 10, _text.getPosition().y + _text.getCharacterSize() + 5));

	const int arrSize = 9;
	string arr[arrSize];

	arr[0] = "Up Arrow: Pans the Screen Upwards";
	arr[1] = "Down Arrow: Pans the Screen Downwards";
	arr[2] = "Right Arrow: Pans the Screen to the Right";
	arr[3] = "Left Arrow: Pans the Screen to the Left";
	arr[4] = "Enter: Zooms into the Middle of the Screen";
	arr[5] = "Right-Shift: Zooms out of the Middle of the Screen";
	arr[6] = "F: Opens Pop-Up for Function Input";
	arr[7] = "R: Resets the Domain and Range back to Default";
	arr[8] = "H: Opens / Closes the Help Window";
			//All info the will be displayed against the help window.

	for (int i = 0; i < arrSize; i++) {
		_text.setString(arr[i]);
		_text.setPosition(sf::Vector2f(helpBox.getPosition().x + 10, _text.getPosition().y + _text.getCharacterSize() + 10));
		window.draw(_text);
	}		//Draws all the items to the window to be displayed.



	_text.setCharacterSize(30);
	_text.setString("");
}

void System::Step(int command, double mouseX, double mouseY)
{
	int domainx = _info->domain.x, domainy = _info->domain.y;

	switch (command) {

	case 1:
		_info->domain.x += ((domainy - domainx) * 0.1);
		_info->domain.y += ((domainy - domainx) * 0.1);
				//Shifts both endpoints to the right.
		break;
	case 2:
		_info->domain.x -= ((domainy - domainx) * 0.1);
		_info->domain.y -= ((domainy - domainx) * 0.1);
				//Shifts both endpoints to the left.
		break;
	case 3:
		_info->range.x += ((domainy - domainx) * 0.1);
		_info->range.y += ((domainy - domainx) * 0.1);
		//Shifts both endpoints to the left.
		break;

	case 4:
		_info->range.x -= ((domainy - domainx) * 0.1);
		_info->range.y -= ((domainy - domainx) * 0.1);
		//Shifts both endpoints to the left.
		break;

	case 5:
		_info->domain.x += ((domainy - domainx) * 0.1);
		_info->domain.y -= ((domainy - domainx) * 0.1);
		_info->range.x += ((domainy - domainx) * 0.1);
		_info->range.y -= ((domainy - domainx) * 0.1);
				//Shifts both endpoints inwards, causing the graph to zoom in.
		break;
	case 6:
		_info->domain.x -= ((domainy - domainx) * 0.1);
		_info->domain.y += ((domainy - domainx) * 0.1);
		_info->range.x -= ((domainy - domainx) * 0.1);
		_info->range.y += ((domainy - domainx) * 0.1);
				//Shifts both endpoints outwards, causing the graph to zoom 
				//out.
		break;
	case 7:
		_info->domain = sf::Vector2f(-10, 10);
		_info->range = sf::Vector2f(-10, 10);
				//Resets all endpoints to default values.
		break;
	}
	_g.update();
		//Recieves new points for the graph
}

void System::Draw(sf::RenderWindow& window)
{
	_g.draw(window);
		//Draws the graph.
}
