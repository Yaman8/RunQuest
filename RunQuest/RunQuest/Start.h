#pragma once
#include<SFML/Graphics.hpp>
class Start
{
private:
	sf::RenderWindow& m_window;
	bool startdis = false;
	float time = 0.0f;
	sf::Texture start;
	sf::Texture start1;
	sf::Texture start2;
public:
	Start(sf::RenderWindow& window) :m_window(window) {};
	~Start();

	void loadonce();
	void StartOptions(float dt);

	bool display = true;
};
