#ifndef EASY_MODE_H
#define EASY_MODE_H
/*
Funkcja easy_mode losuje pojedyncza litere i sprawdza czy zostal wcisniety poprawny klawisz
*/

#include "stdafx.h"
using namespace std;

void delay()
{

	for (int i = 0; i < 5000000; i++)
	{
		for (int i = 0; i < 80; i++)
		{

		}
	}
}


void easy_mode(sf::RenderWindow& okno, int x, int y)
{
	okno.clear();
	okno.display();
	Box sound;
	sound.fill_box("letters");
	Box intro_sounds;
	intro_sounds.fill_box("intro");
	

	sf::Event zdarzenie;
	srand(time(NULL));
	int active_key, random;
	char key;
	string key1;

	sf::Font arial;
	if (!arial.loadFromFile("arial.ttf"))
	{
		std::cout << "Nie udalo sie zaladowac czcionki!\n";
	}; // wczytywanie czcionki

	sf::Text tekst1(key1, arial);
	tekst1.setCharacterSize(300);
	tekst1.setColor(sf::Color::Yellow);
	tekst1.setStyle(sf::Text::Bold);
	tekst1.setPosition(x / 3 + 50, y / 20 * 3 + 20);
	sf::Text tutorialtekst("PRESS ANY KEY TO SKIP", arial);
	tutorialtekst.setCharacterSize(50);
	tutorialtekst.setColor(sf::Color::Yellow);
	tutorialtekst.setStyle(sf::Text::Bold);
	tutorialtekst.setPosition(70, y / 2);
	while (okno.isOpen())
	{
		intro_sounds.play("menuspeech");
		while (1)
		{
			if (okno.pollEvent(zdarzenie))
			{
				if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)return;
				else if (zdarzenie.type == sf::Event::KeyPressed)
				{
					intro_sounds.clear_sound();
					break;
				}
				okno.clear();
				okno.draw(tutorialtekst);
				okno.display();
			}
		}break;
	}
	//TUTORIAL 




	timer time;//czasomierz

	while (okno.isOpen())
	{
		delay();//opoznienie
		random = rand() % 25 + 65; // losuje litere :ascii code a=65...z=90
		key1 = string(1, (char)random);//konwersja int na string

		sound.play(key1);
		active_key = random - 65;  //oznacznia event.key.code  A=0,B=1...Z=24

		time.reset();
		okno.clear();

		tekst1.setString(key1);

		okno.draw(tekst1);
		okno.display();//wyswietalnie tekstu


		while (1)
		{
			if (okno.pollEvent(zdarzenie))
			{

				if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
				{
					return;
				}
				else if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == active_key)
				{
					time.reset();
					
					intro_sounds.play("true");
					break;
				}
				else if (zdarzenie.type == sf::Event::KeyPressed)
				{
					
					intro_sounds.play("false");
					while (1)
					{
						okno.pollEvent(zdarzenie);
						if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
						{
							return;
						}
						else if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == active_key)
						{
							time.reset();
							intro_sounds.play("true");
							break;
						}
						else if (zdarzenie.type == sf::Event::KeyPressed)
						{
							intro_sounds.play("false");
						}
						if (time.passed_time() > 5.00)
						{
							time.reset();
							intro_sounds.clear_sound();
							sound.play(key1);
						}
						time.refresh();//PODPOWIEDZ LITERY CO 5 SEKUND

					}
					break;
				}

				
			}

			if (time.passed_time() > 5.00)
			{
				time.reset();
				intro_sounds.clear_sound();
				sound.play(key1);
			}
			time.refresh();//PODPOWIEDZ LITERY CO 5 SEKUND
		}
	}

	return;
}

#endif /*EASY_MODE_H*/
