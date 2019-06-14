#ifndef SOUND_FILE
#define SOUND_FILE

#include "stdafx.h"

class Sound_file
{
private:

	std::string txt;// nazwa pliku dzwiekowego
	sf::SoundBuffer buffer;
	sf::Sound sound;
	
public:

	void load(std::string txt)
	{
		buffer.loadFromFile("sounds/" + txt + ".wav");
		sound.setBuffer(buffer);
		this->txt = txt;
	}

	void play()
	{
		sound.play();
	}
	void stop()
	{
		sound.stop();
	}

	std::string return_text()
	{
		return txt;
	}

};

#endif /*SOUND_FILE*/