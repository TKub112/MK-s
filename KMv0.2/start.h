#include "stdafx.h"

#ifndef START_H
#define START_H
/*
Funkcja menu_start zwraca liczbe odpowiadajaca trybowi jaki ma zostac
aktywowany w glownej petli.
Legenda:
0 - zamykamy program
1 - learning(), tryb uczenia
2 - easy_mode(), litery
3 - medium_mode(), slowa
4 - hard_mode(), zdania
*/

int menu_start(sf::RenderWindow& okno, int x, int y)
{
	sf::Event zdarzenie;
	sf::Font arial;
	const int font_size = 50;

	/*
	Pozycje napisow:
	{wspolrzedna x, wspolrzedna y}
	*/

	const int positions[7][2] = { { x / 3, y / 20 * 1 },
	{ x / 3, y / 20 * 4 },
	{ x / 3, y / 20 * 7 },
	{ x / 3, y / 20 * 10 },
	{ x / 3, y / 20 * 13 },
	{ x / 3, y / 20 * 16 },
	{ x / 5, y / 20 * 3 } 
	};

	//int pointer_position_min = positions[0][1]; // skrajna pozycja na gorze
	//int pointer_position_max = positions[5][1]; // skrajna pozycja na dole

	//int pointer_position = positions[0][1]; // aktualna pozycja

	/*
	i to zmienna ktora posluzy do przesuwania znacznika po poszczegolnych
	opcjach w menu
	*/

	int i = 0;


	if (!arial.loadFromFile("arial.ttf"))
	{
		
	};

	/*
	Po kolei definiujemy jak beda wygladac poszczegolne obiekty sf::Text.
	Roznia sie od siebie tylko "tekstem" jaki bada przechowywac i pozycja.
	Poza tym wszystkie sa takie same :)
	*/

	sf::Text tekst1("LEARNING", arial);
	tekst1.setCharacterSize(font_size);
	tekst1.setColor(sf::Color::Yellow);
	tekst1.setStyle(sf::Text::Bold);
	tekst1.setPosition(positions[0][0], positions[0][1]);  // < -- do zmiany

	sf::Text tekst2("LETTERS", arial);
	tekst2.setCharacterSize(font_size);
	tekst2.setColor(sf::Color::Yellow);
	tekst2.setStyle(sf::Text::Bold);
	tekst2.setPosition(positions[1][0], positions[1][1]);// < -- do zmiany

	sf::Text tekst3("WORDS", arial);
	tekst3.setCharacterSize(font_size);
	tekst3.setColor(sf::Color::Yellow);
	tekst3.setStyle(sf::Text::Bold);
	tekst3.setPosition(positions[2][0], positions[2][1]);// < -- do zmiany

	sf::Text tekst4("SENTENCES", arial);
	tekst4.setCharacterSize(font_size);
	tekst4.setColor(sf::Color::Yellow);
	tekst4.setStyle(sf::Text::Bold);
	tekst4.setPosition(positions[3][0], positions[3][1]);// < -- do zmiany

	sf::Text tekst5("HELP", arial);
	tekst5.setCharacterSize(font_size);
	tekst5.setColor(sf::Color::Yellow);
	tekst5.setStyle(sf::Text::Bold);
	tekst5.setPosition(positions[4][0], positions[4][1]);// < -- do zmiany


	sf::Text tekst6("EXIT", arial);
	tekst6.setCharacterSize(font_size);
	tekst6.setColor(sf::Color::Yellow);
	tekst6.setStyle(sf::Text::Bold);
	tekst6.setPosition(positions[5][0], positions[5][1]);// < -- do zmiany

	


	/*
	Specjalny tekst stosowany do wskazywania opcji w menu.
	*/

	sf::Text wskaznik(">", arial);
	wskaznik.setCharacterSize(font_size);
	wskaznik.setColor(sf::Color::Yellow);
	wskaznik.setStyle(sf::Text::Bold);
	wskaznik.setPosition(positions[6][0], positions[i][1]);// < -- do zmiany

	/*
	Lokalna petla odpowiedzialna za wyswietlanie poczatkowego menu.
	*/
	Box intro_sounds;
	intro_sounds.fill_box("intro");
	intro_sounds.play("learningmode");
	timer time;//czasomierz
	
	while (okno.isOpen()) 
	{
		
		if (okno.pollEvent(zdarzenie))
		{
			
			if (zdarzenie.type == sf::Event::Closed)
				okno.close();

			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
				okno.close(); //wyjscie z programu

			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Enter)
			{
				intro_sounds.clear_sound();
				if (i == 0)// tryb uczenia
				{
					okno.clear();
					okno.display();
					return 1;
				}
				else if (i == 1) return 2; // litery
				else if (i == 2) return 3; // slowa
				else if (i == 3) return 4; // zdania
				else if (i == 4) return 5; // pomoc
				else if (i == 5) return 6; // wyjscie z programu
			}

			//Obsluga przesuwania znacznika w gore i w dol
			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Up)
			{
				time.reset();
				if (i > 0) i--;

				intro_sounds.clear_sound();
				if (i == 0) { intro_sounds.play("learningmode"); } //nauka
				else if (i == 1) intro_sounds.play("lettersmode"); // litery
				else if (i == 2) intro_sounds.play("wordsmode"); // slowa
				else if (i == 3) intro_sounds.play("sentencesmode"); // zdania
				else if (i == 4) intro_sounds.play("help"); // pomoc
				else if (i == 5) intro_sounds.play("exit"); // wyjscie z programu
				

			}

			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Down)
			{
				time.reset();
				if (i < 5) i++;

				intro_sounds.clear_sound();
				if (i == 0) { intro_sounds.play("learningmode"); } //nauka
				else if (i == 1) intro_sounds.play("lettersmode"); // litery
				else if (i == 2) intro_sounds.play("wordsmode"); // slowa
				else if (i == 3) intro_sounds.play("sentencesmode"); // zdania
				else if (i == 4) intro_sounds.play("help"); // pomoc
				else if (i == 5) intro_sounds.play("exit"); // wyjscie z programu
			}

		}

		
		if (time.passed_time() > 5.00)
		{
			time.reset();
			intro_sounds.clear_sound();
			if (i == 0) { intro_sounds.play("learningmode"); } //nauka
			else if (i == 1) intro_sounds.play("lettersmode"); // litery
			else if (i == 2) intro_sounds.play("wordsmode"); // slowa
			else if (i == 3) intro_sounds.play("sentencesmode"); // zdania
			else if (i == 4) intro_sounds.play("help"); // pomoc
			else if (i == 5) intro_sounds.play("exit"); // wyjscie z programu
		}
		//cykliczna podpowiedz co 5 sekund

		time.refresh();
		okno.clear();

		okno.draw(tekst1);
		okno.draw(tekst2);
		okno.draw(tekst3);
		okno.draw(tekst4);
		okno.draw(tekst5);
		okno.draw(tekst6);
		wskaznik.setPosition(positions[6][0], positions[i][1]);
		okno.draw(wskaznik);

		okno.display();

	}//koniec while

	return 0;
}//koniec funkcji menu_start, wracamy do glownej petli

#endif /*START_H*/
