#include "sidebar.h"
#include "constants.h"

Sidebar::Sidebar() {
    
}

Sidebar::Sidebar(float left, float width) :_left(left), _width(width) {
    cout << "Sidebar CTOR: TOP" << endl;

    //set up the sidebar rectangle:
    rect.setFillColor(sf::Color(105, 105, 105)); //(192,192,192)); //silver
    rect.setPosition(sf::Vector2f(left, 0));
    rect.setSize(sf::Vector2f(width, SCREEN_HEIGHT));
    cout << "Sidebar CTOR: about to load font." << endl;

    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    //the font file must be in the "working directory"
    // check projects->run->working directory
    //      [Make sure it's not pointing to the app file]

    if (!font.loadFromFile("Roboto-Thin.ttf")) {
        cout << "Sidebar() CTOR: Font failed to load" << endl;
        cin.get();
        exit(-1);
    }
    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    cout << "Sidebar CTOR: loaded font." << endl;

    //. . . . . text / font problems: . . . . . . . .
    //initializing text object in this way caused problems
    // (hangs!)
    //only when sb_text was a private member and worked fine
    //when it was a public member. Probably not releavant,
    //but still strange!
    //
    //sb_text = sf::Text("Initial String for myTextLabel", font);
    //
    //. . . . . . . . . . . . . . . . . . . . . . . . .
    cout << "Sidebar CTOR: Text object initialized." << endl;
    sb_text.setFont(font);
    sb_text.setCharacterSize(20);
    sb_text.setStyle(sf::Text::Bold);
    sb_text.setFillColor(sf::Color::Yellow);

    ////this is how you would position text on screen:
    //sb_text.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-sb_text.getLocalBounds().height-5));

    history.open("Function_History.txt");

    items.push_back("Function History");

    //Fill the items vector with empty strings so that we can use [] to read them:
    for (int i = 0; i < 33; i++) {
        items.push_back("");
    }

    items.push_back("Press H for Help Menu");

    lastFunctionIndex = 3;

    int numFunctionsInFile = 0;

    string tempFunc;
    while (!history.eof()) {

        getline(history, tempFunc);

        if (tempFunc.size() != 0) {
            numFunctionsInFile++;
        }

        addFunction(tempFunc);

    }

    lastFunctionIndex += numFunctionsInFile;

    cout << "Sidebar: CTOR: Exit." << endl;
}

void Sidebar::draw(sf::RenderWindow& window) {
    const double VERTICAL_LINE_SPACING = 5.0;
    const double LEFT_MARGIN = 10.0;

    window.draw(rect);
    float height = 10;

    for (int i = 0; i < items.getSize(); i++) {
        bool blank = false;
        if (items[i].size() == 0) {
            //empty rows must be taken into account (getLocalBounds())
            //but not drawn
            blank = true;
            sb_text.setString("BLANK");
        }
        else {
            sb_text.setString(items[i]);
        }
        sb_text.setPosition(sf::Vector2f(_left + LEFT_MARGIN, height));
        height += sb_text.getLocalBounds().height + VERTICAL_LINE_SPACING;
        if (!blank)
            window.draw(sb_text);
    }
}

string& Sidebar::operator [](int index) {
    return items[index];
}

void Sidebar::addFunction(string func)
{
    items[lastFunctionIndex++] = func;

    if (lastFunctionIndex >= 25) {
        lastFunctionIndex = 3;
    }
}

void Sidebar::saveHistory()
{
    remove("Function_History.txt");

    ofstream outs;
    outs.open("Function_History.txt");

    int index = 3;

    while (index < 25) {
        outs << items[index++] << endl;
    }

    outs.close();
}

string Sidebar::getEquationFromHistory(double mouseY)
{
    return items[static_cast<int>((mouseY - 10) / (sb_text.getLocalBounds().height + 7)) + 1];
}
