#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
class Character
{

private:
	sf::RenderWindow& m_window;
	bool run = true;
	bool jump = false;
	
	float gravity = 3.0f;
	bool soundplay=true;
	float Et=0;
	float Lt = 0;
	float Jumpdelay=0;


public:
	bool display = true;
	bool pumdis = true;
	sf::RectangleShape playrun;
	sf::RectangleShape playghost;
	sf::RectangleShape playpumpkin;
	float speed=700;
	bool fall= false;

	sf::RectangleShape iden;
public:
	Character(sf::RenderWindow& window) : m_window(window) {};
	~Character();
	std::string numToString(int a);
	int pumkin = 0;
	void load(float dt,int count, sf::Vector2f* start,sf::Vector2f* gstart, sf::Vector2f* pstart);
	void movement(float dt,int count, sf::Vector2f* start, sf::Vector2f* gstart, sf::Vector2f* pstart);
	
private:

};