#pragma once

#ifndef TIMER
#define TIMER

#include "stdafx.h"
#include <fstream>

class timer
{
private:
	sf::Clock timer;
	sf::Time time;
public:
	void refresh()
	{
		time = timer.getElapsedTime();
	}
	float passed_time()
	{
		return time.asSeconds();
	}
	void reset()
	{
		timer.restart();
	}




};

#endif /*TIMER*/
