#include "Mode.h"
#include<iostream>
#include <SFML/Graphics.hpp>
#include"Sound.h"



Mode::~Mode() {}

void Mode::loadonce()
{
    font.loadFromFile("Original Quality DEMO.otf");
    font.loadFromFile("Bolularegular.otf");
    modeimg.loadFromFile("main.jpg");
}

//ModeOptions
void Mode::ModeOptions()
{
    Sound* isound = new Sound();
    if (display == true) {
        isound->Soundi(soundplay);
    }
    isound->Soundi(soundplay);
    //FIRST SCREEN
    
    sf::Vector2i mousePos = sf::Mouse::getPosition();

    
    sf::RectangleShape ModeMenu(sf::Vector2f(1366, 768));
    ModeMenu.setTexture(&modeimg);

    sf::Texture Play;
    sf::RectangleShape Start(sf::Vector2f(640, 128));
    Start.setPosition(sf::Vector2f(300, 200)); 
    Start.setFillColor(sf::Color(255, 255, 255, 128));
    Start.setTexture(&Play);

    sf::Texture Quit;
    sf::RectangleShape End(sf::Vector2f(640, 128));
    End.setPosition(sf::Vector2f(300, 400));
    End.setFillColor(sf::Color(255, 255, 255, 128));
    End.setTexture(&Quit);

    sf::Text text1("PLAY", font, 72);
    text1.setPosition(350, 250);
    text1.setFillColor(sf::Color(0, 255, 0));

    sf::Text text2("EXIT", font, 72);
    text2.setPosition(350, 450);
    text2.setFillColor(sf::Color(0, 255, 0));
    
    

    
    m_window.draw(ModeMenu);
    m_window.draw(Start);
    m_window.draw(End);
    m_window.draw(text1);
    m_window.draw(text2);

    //CLICK EFFECT
        if ((300 < mousePos.x)&&(mousePos.x < 940) && (200 < mousePos.y)&&(mousePos.y < 328))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                display = false;

            }
                
        }
        else if ((300 < mousePos.x) && (mousePos.x < 940) && (400 < mousePos.y) && (mousePos.y < 528))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                m_window.close();
                exit;
            }
           
        }
        
   
    
}