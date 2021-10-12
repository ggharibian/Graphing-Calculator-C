#include "Animate.h"

//Regular Old Animate Class; Nothing special to see here 

Animate::Animate(graphInfo* info): _info(info), 
sidebar(info->graphDimensions.x, info->graphDimensions.x * 0.25)
{
    system = System(_info);
            //New system object; makes changes to the graph info from the user

    window.create(sf::VideoMode(info->graphDimensions.x * 1.25, 
        info->graphDimensions.y), _info->equation);
            //Window to display the graph in.

    window.setFramerateLimit(0);


    myTextLabel = sf::Text("Initial String for myTextLabel", font);
    myTextLabel.setCharacterSize(20);
    myTextLabel.setStyle(sf::Text::Bold);
    myTextLabel.setFillColor(sf::Color::Green);
    myTextLabel.setPosition(sf::Vector2f(10,
        info->graphDimensions.y - myTextLabel.getLocalBounds().height - 5));

    f_entered = false;
}

Animate::~Animate()
{
    delete _info;
}

void Animate::Draw() {
    //Look at the data and based on the data, draw shapes on window object.

    system.Draw(window);

    if (f_entered)
        system.displayFunctionEnterBox(window, userFunction);

    if (help_window_displaying)
        system.displayHelpWindow(window);

    sidebar.draw(window);
}

void Animate::update() {
    //cause changes to the data for the next frame

    if (mouseIn) {
        mouseX = sf::Mouse::getPosition(window).x;
        mouseY = sf::Mouse::getPosition(window).y;
    }

    if (command == 8) {
        _info->equation = sidebar.getEquationFromHistory(mouseY);
    }

    system.Step(command, mouseX, mouseY);

    if (functionInputted) {
        sidebar.addFunction(_info->equation);
        functionInputted = false;
    }

    command = 0;

}
void Animate::render() {
    window.clear();
    Draw();
    window.display();
}



void Animate::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))//or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
            // window closed
        case sf::Event::Closed:
            window.close();
            break;

        case sf::Event::MouseMoved:
            mouseX = event.mouseMove.x;
            mouseY = event.mouseMove.y;
            //Do something with it if you need to...
            break;

        case sf::Event::MouseEntered:
            mouseIn = true;
                    //Sets mouseIn trigger to true; helps for recording the
                    //mouses location within in the graph.
            break;

        case sf::Event::MouseLeft:
            mouseIn = false;
                    //Resets the mouseIn trigger.
            break;

        case sf::Event::MouseButtonReleased:
            if (mouseIn && event.mouseButton.button == sf::Mouse::Left)
            {
                if (mouseX >= .8 * 1.25 * _info->graphDimensions.x) {
                    command = 8;
                }
            }
            break;
        case sf::Event::TextEntered:
            if (event.text.unicode < 128) {
                        //We check to make sure that the inputted text is
                        //within the ascii table that is accessible with a 
                        //keyboard.

                if (!f_entered && static_cast<char>(event.text.unicode) 
                    == 'f') {
                    f_entered = true;
                            //Bool triggered when f is entered.
                }
                else if (f_entered) {
                    
                    if (static_cast<char>(event.text.unicode) == '\b') {
                        if (!userFunction.empty())
                                    //Deletes the last character of the
                                    //function
                            userFunction = userFunction.substr(0, 
                                userFunction.length() - 1);
                    }
                    else {
                        userFunction += static_cast<char>(event.text.unicode);
                    }
                }
            }
            break;

            // key pressed
        case sf::Event::KeyPressed:
            switch (event.key.code) {

            case sf::Keyboard::Escape:
                window.close();
                break;

            case sf::Keyboard::Left:
                command = 2;
                break;
            case sf::Keyboard::Right:
                command = 1;
                break;
            case sf::Keyboard::Up:
                command = 3;
                break;
            case sf::Keyboard::Down:
                command = 4;
                break;
            case sf::Keyboard::RShift:
                command = 6;
                break;
            case sf::Keyboard::R:
                if (!f_entered)
                    command = 7;
                break;
                        //Each command value corresponds to a specific action
                        //of the system class that will call it. 
            case sf::Keyboard::H:
                if (!f_entered)
                    help_window_displaying = !help_window_displaying;
                        //alternates between displaying and not displaying the
                        //help menu.
                break;

            case sf::Keyboard::Enter:
                if (f_entered) {
                    f_entered = false;
                    _info->equation = userFunction;
                    userFunction = "";
                    functionInputted = true;
                }
                else {
                    command = 5;
                }
                break;

            default:
                break;
            }
        }
    }
}
void Animate::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render(); //clear/draw/display
    }

    sidebar.saveHistory();
            //Saves the sidebar history to a file in the projects' directory
}