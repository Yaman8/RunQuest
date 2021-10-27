#include "Intro.h"
#include<iostream>

#include <SFML/Graphics.hpp>


float intro_x, intro_y;
Intro::~Intro() {}
void Intro::loadonce()
{
    intro.loadFromFile("1.jpg");
    
}



void Intro::loadintro()
{
    //LOADING SCREEN
    sf::Vector2u openbgsize = intro.getSize();
    intro_x = openbgsize.x;
    intro_y = openbgsize.y;

    sf::RectangleShape OpeningIntro(sf::Vector2f(intro_x, intro_y));
    OpeningIntro.setPosition(sf::Vector2f(300, 200));

    OpeningIntro.setTexture(&intro);
    
    m_window.draw(OpeningIntro);
        opendisp = false;
   
       



     
    

    
}



