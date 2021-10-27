#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
class Sound
{
public:
	sf::SoundBuffer bufferi;
	sf::Sound soundi;

	sf::SoundBuffer bufferj;
	sf::Sound soundj;
	void Soundi(bool play);
	void Soundj(bool play);
	~Sound();
};

