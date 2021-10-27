#include "Start.h"
#include<iostream>
#include <SFML/Graphics.hpp>



Start::~Start() {}

void Start::loadonce()
{
    start.loadFromFile("4.png");
    start1.loadFromFile("8.png");
    start2.loadFromFile("10.png");
}



void Start::StartOptions(float dt)
{
    
    //GAME BACKGROUND
    sf::RectangleShape ModeStart(sf::Vector2f(1366, 768));
    ModeStart.setTexture(&start);
    sf::RectangleShape ModeStart1(sf::Vector2f(1366, 768));
    ModeStart1.setTexture(&start1);
    sf::RectangleShape ModeStart2(sf::Vector2f(1366, 768));
    ModeStart2.setTexture(&start2);

        time = time + dt;
        if (time < 20.0f) {
            m_window.draw(ModeStart);
        }
        else if (time >20.0f && time<40.0f) {
            m_window.draw(ModeStart1);

        }
        else if (time > 40.0f && time < 60.0f) {
            m_window.draw(ModeStart2);

        }
        else
            time = 0.0f;

    

    
    
}