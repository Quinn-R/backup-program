#include "../inc/common.h"

class window 
{
    
private:
    
    sf::Vector2f windowSize;
    sf::Vector2f mousePos;
    
    sf::RenderWindow window1;
    
    sf::Color clr1;
    sf::Color clr2;
    sf::Color clr3;
    
    sf::Font fnt1;
    
    sf::Text txt1;
    sf::Text txt2;
    sf::Text txt3;
    
    sf::RectangleShape rect1;
    sf::RectangleShape rect2;
    
    sf::FloatRect box1;
    sf::FloatRect box2;
    
public:
    
    window();
    
    void update();
    void windowLoop();
    
};

window::window()
{
    
    windowSize = sf::Vector2f(1024, 576);
    mousePos.x = sf::Mouse::getPosition().x;
    mousePos.y = sf::Mouse::getPosition().y;
    
    window1.create(sf::VideoMode(windowSize.x, windowSize.y), "backup your files", sf::Style::Titlebar | sf::Style::Close);
    
    clr1.r = 171;
    clr2.r = 230;
    clr3.r = 255;
    
    clr1.g = 177;
    clr2.g = 236;
    clr3.g = 255;
    
    clr1.b = 188;
    clr2.b = 247;
    clr3.b = 255;
    
    if(!(fnt1.loadFromFile("../fnt/Georgia.ttf")))
        std::cout << std::endl << "ERROR: Could not load 'Georgia.ttf' from folder fnt." << std::endl;
    
    txt1.setFont(fnt1);
    txt2.setFont(fnt1);
    txt3.setFont(fnt1);
    
    txt1.setCharacterSize(15);
    txt2.setCharacterSize(15);
    txt3.setCharacterSize(15);
    
    txt1.setString("Welcome to the backup program. To choose files to backup, write into the text file named 'backup locations' the following things: file/folder locaiton space new folder name. If you write the same folder name for a different backup, they will be put into the same folder. When making more than one file/folder backup, you must write them on seperate lines. The backups will be made to the location of the program.");
    txt2.setString("generate 'backup locations' file");
    txt3.setString("start backup");
    
    rect1.setSize(sf::Vector2f(150, 75));
    rect2.setSize(sf::Vector2f(150, 75));
    
    rect1.setPosition
    (
        ((window1.getSize().x / 2) - (rect1.getSize().x / 2) - (rect1.getSize().x / 2) - 5),
        (window1.getSize().y - 85)
    );
    rect2.setPosition
    (
        ((window1.getSize().x / 2) - (rect2.getSize().x / 2) + (rect1.getSize().x / 2) + 5),
        (window1.getSize().y - 85)
    );
    
    box1 = rect1.getGlobalBounds();
    box2 = rect2.getGlobalBounds();
    
}

void window::update()
{
    
    box1 = rect1.getGlobalBounds();
    box2 = rect2.getGlobalBounds();
    
    mousePos.x = sf::Mouse::getPosition(window1).x;
    mousePos.y = sf::Mouse::getPosition(window1).y;
    
}

void window::windowLoop()
{
    
    //window1.create(sf::VideoMode(500, 500), "title", sf::Style::Titlebar | sf::Style::Close);
    
    window1.setPosition
    (
        sf::Vector2i(((sf::VideoMode::getDesktopMode().width / 2) - (window1.getSize().x / 2)),
        ((sf::VideoMode::getDesktopMode().height / 2) - (window1.getSize().y / 2)))
    );

    while(window1.isOpen())
    {
        
        sf::Event event;
        
        while(window1.pollEvent(event))
        {
            
            update();
            
            if(event.type == sf::Event::Closed)
                window1.close();
            
            if(box1.contains(mousePos))
            {
                
                rect1.setFillColor(clr2);
                
            }
            else if(! (box1.contains(mousePos)))
            {
                
                rect1.setFillColor(clr1);
                
            }
            
            if(box2.contains(mousePos))
            {
                
                rect2.setFillColor(clr2);
                
            }
            else if(! (box2.contains(mousePos)))
            {
                
                rect2.setFillColor(clr1);
                
            }
            
            if(event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode == 8)
                {
                    
                }
                
            }
            
        }
        
        window1.clear(sf::Color::Black);
        window1.draw(rect1);
        window1.draw(rect2);
        window1.display();
        
    }
    
}

class readFile
{
    
private:
    
    std::vector <std::string> vectReadLocation;
    std::vector <std::string> vectReadFoldername;
    
    std::ifstream infile;
    
    std::string fileName;
    
public:
    
    
    
};

window mainw;

int main()
{
    //std::string input;
    
    //std::cout << "Hello world";
    
    mainw.windowLoop();
    
    //std::cin >> input;
    
    return 0;
}
