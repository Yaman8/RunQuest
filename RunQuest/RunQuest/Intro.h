#pragma once
#include<SFML/Graphics.hpp>
class Intro
{
private:
	sf::RenderWindow& m_window;

public:
	Intro(sf::RenderWindow& window) :m_window(window) {};
	~Intro();
	sf::Texture intro;
	void loadonce();
	void loadintro();
	bool opendisp = true;
};

