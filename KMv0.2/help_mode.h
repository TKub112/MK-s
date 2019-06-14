
void helpmode(sf::RenderWindow& okno, int x, int y)
{

	sf::Event zdarzenie;
	Box intro_sounds;
	intro_sounds.fill_box("intro");
	intro_sounds.play("menuspeech");

	sf::Font arial;

	if (!arial.loadFromFile("arial.ttf"))
	{
		std::cout << "Nie udalo sie zaladowac czcionki!\n";
	}; // wczytywanie czcionki


	sf::Text tekst1("TUTORIAL", arial);
	tekst1.setCharacterSize(100);
	tekst1.setColor(sf::Color::Yellow);
	tekst1.setStyle(sf::Text::Bold);
	tekst1.setPosition(x / 3 -100, y / 20 * 3 +50 );

	
	
	while (okno.isOpen())
	{

		if (okno.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
			{
				intro_sounds.clear_sound();
				okno.close();
			}
			else if (zdarzenie.type == sf::Event::KeyPressed)
			{
				intro_sounds.clear_sound();
				return;
			}
			

		}

		okno.clear();
		okno.draw(tekst1);
		okno.display();


	}//koniec while

	
	return;
}




