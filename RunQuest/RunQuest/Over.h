#pragma once
#include<SFML/Graphics.hpp>
class Over
{
private:
	sf::RenderWindow& m_window;
	bool warning = false;
public:
	sf::Font font, font1;
	sf::Texture overimg;

public:
	Over(sf::RenderWindow& window) :m_window(window) {};
	~Over();
	void OverOptions();

	bool display = true;
	bool cdisplay = false;
};

