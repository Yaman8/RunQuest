#include<iostream>
#include"Intro.h"
#include"Mode.h"
#include"Start.h"
#include"Character.h"
#include "Over.h"
#include"Sound.h"

#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>



int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 768), "RunQuest", sf::Style::Fullscreen | sf::Style::Default);
    sf::Clock clock;
    float delTatime;
    
    //OBJECT OF CLASSES
    Intro *intro= new Intro(window);
    intro->loadonce();
    Mode *mode= new Mode(window);
    mode->loadonce();
    Start *start= new Start(window);
    start->loadonce();
    Character* charObj = new Character(window);
    Over* over = new Over(window);
    
    int count = 0;
    int gcount = 0;
    sf::Vector2f spawn(50, 685);
    sf::Vector2f gspawn(1000, 600);
    sf::Vector2f pspawn(1000, 300);

    //GAME LOOP
    while (window.isOpen())
    {
        delTatime = clock.restart().asSeconds();
        count++;
        sf::Event event;
        window.setKeyRepeatEnabled(false);
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }

        }

        window.clear();

        //CALL OF OBJECTS
        if (intro->opendisp == true)
            intro->loadintro();
        else if (mode->display == true)
            mode->ModeOptions();
        else if (start->display == true&&charObj->display==true)
        {
            start->StartOptions(delTatime);
            charObj->load(delTatime ,count, &spawn,&gspawn,&pspawn);
            
        }
        else if (over->display == true && charObj->display == false) {
            over->OverOptions();
        }
        window.display();
    }
    return 0;
}