#include "../inc/textBox.h"

/*##############################

This is required to run the opening and closing of the textbox code

if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
{
    if(txtBx.isTextBoxClicked(mousePos) == 1)
    {

        txtBx.changeTextBox(1);

    }
    else if(txtBx.isTextBoxClicked(mousePos) == 0)
    {

        txtBx.changeTextBox(0);

    }
}

##############################*/

textBox::textBox(sf::Color clr1, sf::Color clr2, sf::Vector2f txtBxPos, sf::Vector2f txtBxSize, sf::FloatRect winSize, std::string fntLc)
{

    clrTextBack1 = clr1;
    clrTextBack2 = clr2;

    textBoxPos = txtBxPos;
    textBoxSize = txtBxSize;
    //mousePos = msePos;
    windowSize = winSize;

    rectInput.setSize(textBoxSize);
    rectInput.setFillColor(clrTextBack1);
    rectInput.setPosition(windowSize.width / 2 - (textBoxPos.x + textBoxSize.x) / 2, 400 );

    boxInput = rectInput.getGlobalBounds();

    fntLoc = fntLc;

    if(! fnt1.loadFromFile(fntLoc))
    {

        std::cout << std::endl << "ERROR: Issue loading font " << fntLoc << "." << std::endl;

    }

}

sf::Vector2f textBox::getTextBoxPos()
{

    return textBoxPos = rectInput.getPosition();

}

sf::FloatRect textBox::getTextBoxBounds()
{

    return rectInput.getGlobalBounds();

}

bool textBox::isTextBoxHover(sf::Vector2f mousePos)
{

    if(boxInput.contains(mousePos))
    {

        return 1;

    }

    return 0;

}

bool textBox::isTextBoxClicked(sf::Vector2f mousePos)
{

    if(isTextBoxHover(mousePos) == 1 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {

        return 1;

    }

    return 0;
    
}

void textBox::userInput(sf::Event textEvent)
{
    
    if(textEvent.type == sf::Event::TextEntered)
    {
        if (textEvent.text.unicode == 8 && inputString.size() > 0)
        {

            inputString.erase(inputString.size() - 1, 1);

        }
        
        else if ((textEvent.text.unicode >= '!' && textEvent.text.unicode <= '}') || textEvent.text.unicode <= ' ' && inputString.size() != 48)
        {
            
            inputString += (textEvent.text.unicode);
            
        }
        
        std::cout << inputString << std::endl;
        
    }

}

/*void textBox::update()
{

    boxInput = rectInput.getGlobalBounds();

    //mousePos.x = sf::Mouse::getPosition(window1).x;
    //mousePos.y = sf::Mouse::getPosition(window1).y;
    
    std::cout << mousePos.x << ", " << mousePos.y << std::endl;

}*/


bool textBox::changeTextBox(bool inUse)
{

    //update();

    if(inUse == 1)
    {

        rectInput.setFillColor(clrTextBack2);
        //return 1;

    }
    else
    {

        rectInput.setFillColor(clrTextBack1);
        //return 0;

    }
}


sf::RectangleShape textBox::getRectInput()
{

    return rectInput;

}
