#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "common.h"

class textBox
{
    
private:
    
    sf::Color clrTextBack1;
    
    sf::RectangleShape rectInput;
    
    sf::FloatRect boxInput;
    
    sf::Vector2f textBoxPos;
    sf::Vector2f mousePos;
    
    sf::Font fnt1;
    
    sf::Text txt1;
    
public:
    
    textBox(sf::Vector2f windowSize, sf::Color clrTextBack1);
    
    void update();
    
    sf::Vector2f getTextBoxPos();
    sf::FloatRect getTextBoxBounds();
    
    bool isTextBoxHover();
    bool isTextBoxClicked();
    
};

#endif
