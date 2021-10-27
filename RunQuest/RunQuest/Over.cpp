#include "Over.h"
#include<iostream>
#include <SFML/Graphics.hpp>
#include"Character.h"



Over::~Over() {}


void Over::OverOptions()
{
    //GAME OVER SCREEN
    font.loadFromFile("Original Quality DEMO.otf");
    font.loadFromFile("Bolularegular.otf");
    overimg.loadFromFile("5.png");
    sf::Vector2i mousePos = sf::Mouse::getPosition();

    sf::RectangleShape OverMenu(sf::Vector2f(1366, 768));
    OverMenu.setTexture(&overimg);

    sf::Texture Quit;
    sf::RectangleShape End(sf::Vector2f(640, 128));
    End.setPosition(sf::Vector2f(300, 400));
    End.setFillColor(sf::Color(255, 255, 255, 128));
    End.setTexture(&Quit);

    sf::Text mtext("GAME OVER!!", font, 80);
    mtext.setPosition(500, 100);
    mtext.setFillColor(sf::Color(0, 255, 0));

    sf::Text text1("WELL PLAYED!!!", font, 72);
    text1.setPosition(500, 250);
    text1.setFillColor(sf::Color(0, 255, 0));

    sf::Text text2("EXIT NOW", font, 72);
    text2.setPosition(350, 450);
    text2.setFillColor(sf::Color(0, 255, 0));



    m_window.draw(OverMenu);
    m_window.draw(End);
    m_window.draw(text1);
    m_window.draw(text2);
    m_window.draw(mtext);


    if ((300 < mousePos.x) && (mousePos.x < 940) && (400 < mousePos.y) && (mousePos.y < 528))
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_window.close();
            exit;
        }

    }



}