#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "common.h"

class textBox
{

private:

    sf::Color clrTextBack1;
    sf::Color clrTextBack2;

    sf::Vector2f textBoxPos;
    sf::Vector2f textBoxSize;
    //sf::Vector2f mousePos;

    sf::RectangleShape rectInput;

    sf::FloatRect boxInput;
    sf::FloatRect windowSize;

    std::string fntLoc;
    std::string inputString;

    sf::Font fnt1;

    sf::Text txt1;

public:

    textBox(sf::Color clr1, sf::Color clr2, sf::Vector2f txtBxPos, sf::Vector2f txtBxSize, sf::FloatRect winSize, std::string fntLc);

    sf::Vector2f getTextBoxPos();

    sf::FloatRect getTextBoxBounds();

    void userInput(sf::Event textEvent);
    void update();
    bool isTextBoxHover(sf::Vector2f mousePos);
    bool isTextBoxClicked(sf::Vector2f mousePos);
    bool changeTextBox(bool inUse);
    
    sf::RectangleShape getRectInput();

};

#endif
