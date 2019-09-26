#ifndef MEDIUM_MODE_H
#define MEDIUM_MODE_H
#include "stdafx.h"
using namespace std;

void medium_mode(sf::RenderWindow& okno, int x, int y)
{

	sf::Event zdarzenie;

	Box words;
	words.fill_box("words");
	Box letters;
	letters.fill_box("letters");
	Box intro_sounds;
	intro_sounds.fill_box("intro");


	sf::Font arial;
	if (!arial.loadFromFile("arial.ttf"))
	{
		std::cout << "Nie udalo sie zaladowac czcionki!\n";
	};


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


	string random = "";
	string typed = "";
	char key = 0;
	int lives = 3;

	sf::Text tekst_random(random, arial);
	tekst_random.setCharacterSize(70);
	tekst_random.setColor(sf::Color::Yellow);
	tekst_random.setStyle(sf::Text::Bold);
	tekst_random.setPosition(x / 3, y / 20 * 6);

	sf::Text tekst_typed(typed, arial);
	tekst_typed.setCharacterSize(70);
	tekst_typed.setColor(sf::Color::Yellow);
	tekst_typed.setStyle(sf::Text::Bold);
	tekst_typed.setPosition(x / 3, y / 20 * 10);

	sf::Text tekst_lives("", arial);
	tekst_lives.setCharacterSize(50);
	tekst_lives.setColor(sf::Color::Yellow);
	tekst_lives.setStyle(sf::Text::Bold);
	tekst_lives.setPosition(x / 3 * 3, y / 20);

	timer time;
	while (okno.isOpen())//petla glowna
	{
		random = words.random();
		words.play(random);
		tekst_random.setString(random);
		typed = "";
		tekst_typed.setString(typed);
		lives = 3;

		for (int i = 0; i < random.length(); i++)//iteracja na kazda litere
		{
			while (okno.isOpen())//czeka na wpisanie pojedynczej litery
			{
				if (okno.pollEvent(zdarzenie))
				{
					if (zdarzenie.type == sf::Event::Closed)
						okno.close();

					if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
						return; // powrot o menu

					if (zdarzenie.type == sf::Event::KeyPressed)
					{
						key = zdarzenie.key.code;
						key = key + 97;//konwersja do kodu ascii

						if (key == random[i])
						{
							intro_sounds.play("true");
							typed += key;
							break;
						}
						else {
							intro_sounds.play("false");
							lives--;
							if (lives == 0) break;
						}
						
					}

				}
				if (lives == 3) tekst_lives.setString("");
				else if (lives == 2) tekst_lives.setString("X");
				else if (lives == 1) tekst_lives.setString("XX");
				else if (lives == 0) tekst_lives.setString("XXX");

				tekst_typed.setString(typed);

				okno.clear();
				okno.draw(tekst_random);
				okno.draw(tekst_typed);
				okno.draw(tekst_lives);
				okno.display();//wyswietalnie tekstu

				if (i == random.length()-1 ) //dzwiek gdy etap zostanie ukonczony opcjonalnie zeby nie opozniac programu daj krotszy dzwiek
				{
					intro_sounds.play("stagecompleted");
				
				}
			}
			if (lives == 0) break;
		}
	}

	return;
}

#endif /*EASY_MODE_H*/

