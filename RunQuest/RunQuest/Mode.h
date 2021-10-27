#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
class Mode
{
private:
	sf::RenderWindow& m_window;
	bool warning = false;
	public:
	sf::Font font,font1;
	sf::Texture modeimg;
	sf::SoundBuffer buffer;
	sf::Sound sound;

public:
	Mode(sf::RenderWindow& window) :m_window(window) {};
	~Mode();
	void loadonce();
	void ModeOptions();
	bool soundplay=true;

	bool display = true;
};

