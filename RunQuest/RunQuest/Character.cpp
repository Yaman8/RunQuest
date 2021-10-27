#include "Character.h"
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Start.h"
#include"Sound.h"
#include"Collision.hpp"
#include<sstream>
Character::~Character()
{
}
void Character::load(float dt,int count, sf::Vector2f* start, sf::Vector2f* gstart, sf::Vector2f* pstart)
{
    Et += dt;
    Jumpdelay += dt;
    Lt = Et;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        jump = true;
    run = true;
    movement(dt,count,start,gstart,pstart);
}

std::string Character::numToString(int a)
{
    //CONVERTING NUMBER TO STRING 
    std::stringstream ss;
    ss << a;
    return ss.str();
}


void Character::movement(float dt,int count, sf::Vector2f* start, sf::Vector2f* gstart, sf::Vector2f* pstart)
{
    if (run == true) 
    {
        Sound* jsound = new Sound();
        //FOR MAIN CHARACTER
        float gravityspeed = 2.0f;
        float groundheight = 450;
        sf::Texture player;
        std::string runner = "Running/" + std::to_string((count) % 12) + ".png";

        player.loadFromFile(runner);
        playrun.setOrigin(0, 0);
        playrun.setPosition(200, 200);
        playrun.setFillColor(sf::Color(255, 255, 255, 255));
        speed = 4.0f;
        playrun.setSize(sf::Vector2f(200.0f, 200.0f));
        playrun.setOrigin(100, 160);
        playrun.setTexture(&player);
        playrun.setPosition(*start);

        //FOR JUMPING
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            jump = true;
            //jsound->Soundj(soundplay);
        }
        if (jump == true)
        {
            *start += sf::Vector2f(0.0f, -700 * dt);
        }
        if (start->y <= 25)
        {
            fall = true;
            jump = false;
            
        }
        if (fall == true)
        {
            *start += sf::Vector2f(0.0f, 700 * dt);
         }
        if (start->y >= 685)
        {
            fall = false;
            *start = sf::Vector2f(350, 685);
        }
            
        if (playrun.getPosition().y < groundheight && jump == false) {
            *start += sf::Vector2f(0.0f, 50.0f * gravityspeed);
        }
        m_window.draw(playrun);

        //FOR GHOST

        float gspeed;
        sf::Texture ghost;
        std::string grunner = "ghost.png";
        ghost.loadFromFile(grunner);
        playghost.setOrigin(0, 0);
        playghost.setPosition(200, 200);
        playghost.setFillColor(sf::Color(255, 255, 255, 255));
        gspeed = 18;
        playghost.setSize(sf::Vector2f(100.0f, 100.0f));


        playghost.setTexture(&ghost);
        playghost.setPosition(*gstart);
        *gstart += sf::Vector2f(-4.0f * gspeed, 0.0f);
        m_window.draw(playghost);

        //FOR PUMPKIN

        float pspeed;
        sf::Texture pumpkin;
        std::string prunner = "Pumpkin.png";

        pumpkin.loadFromFile(prunner);
        playpumpkin.setOrigin(0, 150);
        playpumpkin.setPosition(200, 200);
        playpumpkin.setFillColor(sf::Color(255, 255, 255, 255));
        pspeed = 12;
        playpumpkin.setSize(sf::Vector2f(200.0f, 200.0f));

        playpumpkin.setTexture(&pumpkin);
        playpumpkin.setPosition(*pstart);
        *pstart += sf::Vector2f(-4.0f * pspeed, 0.0f);
        m_window.draw(playpumpkin);

        //OBSTACLE LOOP
        if (gstart->x <= -300)
            gstart->x = 1500;
        if (pstart->x <= -600)
            pstart->x = 2000;

        //SCORE
        int score = 0;
        sf::Font font;
        sf::Text text1;
        sf::Text text2;
        font.loadFromFile("Bolularegular.otf");
        text1.setFont(font);
        text1.setPosition(sf::Vector2f(1000.0f, 50.0f));
        text1.setCharacterSize(128);
        text2.setFont(font);
        text2.setPosition(sf::Vector2f(1000.0f, 100.0f));
        text2.setCharacterSize(128);
        score += int(Et*2) + pumkin * 5;
        text1.setString(("Score: " + Character::numToString(score)).c_str());
        text2.setString(("Time: " + Character::numToString(Et)).c_str());

        //SCORE INCREASES
        if (score > 100) {
            gspeed = 30;
            pspeed = 20;

        }
        if (score > 200) {
            gspeed = 40;
            pspeed = 30;
        }
        

        //COLLISION
        if (playrun.getGlobalBounds().intersects(playghost.getGlobalBounds())) {
            display=false;
        }

        if (playrun.getGlobalBounds().intersects(playpumpkin.getGlobalBounds())) {
            pumkin=pumkin+1;

            pstart->x = 2000;

        }
 
        
        //DRAW
        m_window.draw(text1);
        m_window.draw(text2);
        
        
        
    }
}