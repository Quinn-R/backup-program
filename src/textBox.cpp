#include "../inc/textBox.h"

textBox::textBox(sf::Vector2f windowSize, sf::Color clrTextBack1)
{
    
    rectInput.setSize(sf::Vector2f(windowSize.x - 40, 50));
    rectInput.setFillColor(clrTextBack1);
    rectInput.setPosition
    (
        ((window1.getSize().x / 2) - (rectInput.getSize().x / 2)),
        (rectText.getSize().y + 40)
    );
    
    boxInput = rectInput.getGlobalBounds();
    
}

void textBox::update()
{
    
    boxInput = rectInput.getGlobalBounds();
    
    mousePos.x = sf::Mouse::getPosition().x;
    mousePos.y = sf::Mouse::getPosition().y;
    
}

sf::Vector2f textBox::getTextBoxPos();
{
    
    return textBoxPos = rectInput.getPosition();
    
}

sf::FloatRect textBox::getTextBoxBounds();
{
    
    return rectInput.getGlobalBounds();
    
}

bool textBox::isTextBoxHover()
{
    
    if(boxInput.contains(mousePos))
    {
        
        return 1;
        
    }
    
    return 0;
    
}

bool textBox::isTextBoxClicked()
{
    
    if(isTextBoxHover() == 1 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        
        return 1;
        
    }
    
    return 0;
    
}
