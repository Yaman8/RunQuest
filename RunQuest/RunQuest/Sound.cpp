#include "Sound.h"

void Sound::Soundi(bool play) {
	//INTRO SOUND 
	bufferi.loadFromFile("intro.wav");
	soundi.setBuffer(bufferi);
	soundi.play();
	soundi.setLoop(true);
}

void Sound::Soundj(bool play) {
	//JUMP SOUND 
	bufferj.loadFromFile("jump.wav");
	soundj.setBuffer(bufferj);
	soundj.play();
}
 
Sound::~Sound() {
	

}