#include "../inc/textBox.h"

textBox::textBox(sf::Color clr1, sf::Color clr2, sf::Vector2f txtBxPos, sf::Vector2f txtBxSize, sf::Vector2f winSize, std::string fntLc)
{

    clrTextBack1 = clr1;
    clrTextBack2 = clr2;

    textBoxPos = txtBxPos;
    textBoxSize = txtBxSize;
    //mousePos = msPos;
    windowSize = winSize;

    /*rectInput.setSize(sf::Vector2f(windowSize.x - 40, 50));
    rectInput.setFillColor(clrTextBack1);
    rectInput.setPosition
    (
        ((window1.getSize().x / 2) - (rectInput.getSize().x / 2)),
        (rectText.getSize().y + 40)
    );*/

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

std::string textBox::userInput(sf::Event textEvent)
{
    if(textEvent.type == sf::Event::TextEntered)
    {
        if (textEvent.text.unicode == 8 && inputString.size() > 0 && isTextBoxClicked() == 1)
        {

            inputString.erase(inputString.size() - 1, 1);

        }

    }

}

void textBox::update()
{

    boxInput = rectInput.getGlobalBounds();

    mousePos.x = sf::Mouse::getPosition().x;
    mousePos.y = sf::Mouse::getPosition().y;

}

bool textBox::changeTextBox()
{

    update();

    if(isTextBoxClicked() == 1)
    {

        rectInput.setFillColor(clrTextBack2);
        return 1;

    }
    else
    {

        rectInput.setFillColor(clrTextBack1);
        return 0;

    }
}
