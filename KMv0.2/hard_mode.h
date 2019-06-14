void hard_mode(sf::RenderWindow& okno, int x, int y)
{
	sf::Event zdarzenie;

	Box letters;
	letters.fill_box("letters");
	Box sentences;
	sentences.fill_box("sentences");
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
	tekst_random.setCharacterSize(60);
	tekst_random.setColor(sf::Color::Yellow);
	tekst_random.setStyle(sf::Text::Bold);
	tekst_random.setPosition(x / 3-80, y / 20 * 6);

	sf::Text tekst_typed(typed, arial);
	tekst_typed.setCharacterSize(60);
	tekst_typed.setColor(sf::Color::Yellow);
	tekst_typed.setStyle(sf::Text::Bold);
	tekst_typed.setPosition(x / 3 - 80, y / 20 * 10);

	sf::Text tekst_lives("", arial);
	tekst_lives.setCharacterSize(50);
	tekst_lives.setColor(sf::Color::Yellow);
	tekst_lives.setStyle(sf::Text::Bold);
	tekst_lives.setPosition(x / 4 * 3, y / 20);

	while (okno.isOpen())//petla glowna
	{
		random = sentences.random();
		sentences.play(random);
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
						return; //powrot o menu

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
						else if (zdarzenie.key.code == sf::Keyboard::Space && random[i] == 32)
						{
							intro_sounds.play("true");
							typed += " ";
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
			}
			if (lives == 0) break;
		}
	}

}