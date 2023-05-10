#include"engine.h"
#include"list.h"
#include"MyCar.h"
#include<SFML/Audio.hpp>
Engine::Engine()
{
	Vector2f resolution;
	resolution.x = 1280;
	resolution.y = 720;
	m_Window.create(VideoMode(resolution.x, resolution.y),
		"Drive",
		Style::Default);
	m_BackgroundTexture.loadFromFile("1.png");
	textur.loadFromFile("Enemy2.png");
	m_BackgroundSprite.setTexture(m_BackgroundTexture);
	menuTexture1.loadFromFile("start.png");
	menuTexture1_1.loadFromFile("start2.png");
	menu1.setTexture(menuTexture1);
	menu1.setScale(0.25f, 0.25f);
	m_GohstCart.loadFromFile("3.png");
	m_GohstCars.setTexture(m_GohstCart);
	m_GohstCars.setScale(0.5f, 0.5f);
	m_GohstCars.setPosition(400, 200);
	menuTexture2.loadFromFile("exit.png");
	menuTexture2_1.loadFromFile("exit2.png");
	menu2.setTexture(menuTexture2);
	menu1.setPosition(500, 300);
	menu2.setScale(0.4f, 0.4f);
	menu2.setPosition(487.5, 390);
	Logo_Texture.loadFromFile("logo.png");
	Logo_Sprite.setTexture(Logo_Texture);
	Logo_Sprite.setScale(0.2f, 0.2f);
	Logo_Sprite.setPosition(400, 50);
	hand.loadFromSystem(sf::Cursor::Hand);
	m_chellt.loadFromFile("chell.png");
	m_chells.setTexture(m_chellt);
	m_chells.setScale(0.2f, 0.2f);
	m_strelkat.loadFromFile("strelka.png");
	m_strelkas.setTexture(m_strelkat);
	m_strelkas.setScale(0.2f, 0.2f);
	m_strelkas.setRotation(90);
	if (cursor1.loadFromSystem(sf::Cursor::Arrow))
	{
		m_Window.setMouseCursor(cursor1);
	}
	gosht.openFromFile("gosht.ogg");
	gg = 0;
}
void Engine::start()
{ 
	int menuNum = 0;
	gosht.play();
	while (m_Window.isOpen()) {
		sf::Event event1;
		while (m_Window.pollEvent(event1))
		{
			if (event1.type == sf::Event::Closed)
			{
				m_Window.close();
			}
		}
		Time dtt=clock2.getElapsedTime();
		gohst1 = dtt.asMilliseconds()+18000*gg;
		if (gohst1 <= 5700)
		{
			m_chells.setPosition((gohst1 / 10)-300, 300);
			m_strelkas.setPosition((gohst1 / 10) - 240, 175);
			m_Window.draw(m_chells);
			m_Window.draw(m_GohstCars);
		}
		if (gohst1>=5700 && gohst1<=7000)
		{	
			m_Window.draw(m_strelkas);
			m_Window.draw(m_chells);
			m_Window.draw(m_GohstCars);
		}
		if (gohst1 >= 7000 && gohst1 <= 9000)
		{
			m_chells.setPosition(((gohst1 - 1300) / 10) - 300, 300);
			m_Window.draw(m_chells);
			m_Window.draw(m_GohstCars);
		}
		if (gohst1 >= 9000&& gohst1 <= 13000)
		{
			m_Window.draw(m_chells);
			m_Window.draw(m_GohstCars);
		}
		if (gohst1 >= 13000 && gohst1 <= 15000)
		{
			m_Window.draw(m_GohstCars);
		}
		if (gohst1 >= 15000&& gohst1<=16000)
		{
			m_GohstCars.setPosition(400, 200-(gohst1-15000));
			m_Window.draw(m_GohstCars);
		}
		if (gohst1 >= 16000)
		{
			m_GohstCars.setScale(0.2f, 0.2f);
			m_GohstCars.setPosition(550, 720 - (gohst1 - 16000));
			m_Window.draw(m_BackgroundSprite);
			m_Window.draw(m_GohstCars);
		}
		if (gohst1 >= 18000 || Keyboard::isKeyPressed(Keyboard::Enter)) {
			gosht.stop();
			gg = 1;
			if (IntRect(505, 300, 160, 75).contains(Mouse::getPosition((m_Window)))) {
				menu1.setTexture(menuTexture1_1); menuNum = 1; m_Window.setMouseCursor(hand);
			}
			else
			{
				if (!IntRect(512.5, 400, 150, 58).contains(Mouse::getPosition((m_Window))))
				{
					m_Window.setMouseCursor(cursor1);
					menu1.setTexture(menuTexture1);
					menuNum = 0;
				}
			}
			if (IntRect(512.5, 400, 150, 58).contains(Mouse::getPosition((m_Window)))) {
				menu2.setTexture(menuTexture2_1); menuNum = 2; m_Window.setMouseCursor(hand);
			}
			else
			{
				if (!IntRect(505, 300, 160, 75).contains(Mouse::getPosition((m_Window)))) {
					m_Window.setMouseCursor(cursor1);
					menu2.setTexture(menuTexture2);
					menuNum = 0;
				}
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				switch (menuNum)
				{
				case 1:
				{
					Score = 0;
					shet = 1;
					Score_shet = 1;
					m_Window.setMouseCursor(cursor1);
					bool ant = true, ant2 = true, ant3 = true;
					polnoegavno();
					pause = false;
					Font font;
					font.loadFromFile("ArialRegular.ttf");
					music.openFromFile("icq.wav");
					globallist.addNode();
					int doroga = 100;
					for (int i = 0; i < 7; i++)
					{
						g.push_back(false);
					}
					stolk = false;
					bool gavn = true;
					while (globallist.Begin->x != 550)
					{
						if (gavn)
						{
							if (globallist.Begin->next != NULL)
							{
								globallist.Begin = globallist.Begin->next;
							}
							else
							{
								gavn = false;
							}
						}
						else
						{
							if (globallist.Begin->prev != NULL)
							{
								globallist.Begin = globallist.Begin->prev;
							}
							else
							{
								gavn = true;
							}
						}
					}
					int hp = 3, gavno = 0;
					spawn[0] = 0;
					spawn[1] = 0;
					spawn[2] = 0;
					spawn[3] = 0;
					float immortal = 0, dtMilliSeconds = 0, gavno2 = 0;
					Text text("Pause", font);
					text.setCharacterSize(30);
					text.setStyle(sf::Text::Bold);
					text.setFillColor(sf::Color::White);
					text.setPosition(500, 500);
					pause2();
					life = true;
					sf::Event event;
					Clock clock, clock1;
					int dtAsSeconds = 0;
					while (life)
					{
						Time dt2 = clock1.restart();
						dtAsSeconds_1 = dt2.asSeconds();
						Time dt = clock.getElapsedTime();
						dtt = clock2.getElapsedTime();
						gohst1 = dtt.asMilliseconds();
						dtAsSeconds = dt.asSeconds() + gavno;
						dtMilliSeconds = dt.asMilliseconds() + gavno2;
						if (pause == true)
						{
							if (IntRect(550, 470, 150, 58).contains(Mouse::getPosition((m_Window)))) {
								menu2.setTexture(menuTexture2_1); menuNum = 1; m_Window.setMouseCursor(hand);
							}
							else {
								m_Window.setMouseCursor(cursor1);
								menu2.setTexture(menuTexture2);
								menuNum = 0;
							}
							if (Mouse::isButtonPressed(Mouse::Left))
							{
								if (menuNum == 1) {
									life = false;
									m_Enemy.clear();
									m_MyCar.m_Texture.loadFromFile("3.png");
									m_MyCar.m_Sprite.setTexture(m_MyCar.m_Texture);
									m_explose.clear();
									m_Coin.clear();
									m_Bullet.clear();
									immortal = 0;
									m_MyCar.m_Position.x = 550;
									m_MyCar.m_Position.y = 500;
									menu2.setPosition(487.5, 390);
								}
							}
							draw(doroga, stolk, pause, dtAsSeconds, hp, immortal);
							m_Window.draw(menu2);
							m_Window.draw(m_Sprite2);
							m_Window.display();
							clock.restart();
						}
						while (m_Window.pollEvent(event))
						{
							if (event.type == sf::Event::Closed)
							{
								m_Window.close();
								life = false;
							}
						}
						if (Keyboard::isKeyPressed(sf::Keyboard::Escape) && ant3)
						{
							if (pause == false) {
								gavno = dtAsSeconds;
								gavno2 = dtMilliSeconds;
								pause = true;
								sound_pause.play();
								menu2.setPosition(525, 460);
							}
							else {
								pause = false;
							}
							ant3 = false;
						}
						else
						{
							if (!Keyboard::isKeyPressed(sf::Keyboard::Escape))
								ant3 = true;
						}
						if (pause == false) {
							input(doroga, ant);
							update(dtAsSeconds, dtMilliSeconds, immortal, hp, ant2);
							if (life)
							{
								draw(doroga, stolk, pause, dtAsSeconds, hp, immortal);
								m_Window.display();
							}
						}
					}
				}
				break;
				case 2:
					m_Window.close();
					break;
				}
			}
			m_Window.draw(m_BackgroundSprite);
			m_Window.draw(menu1);
			m_Window.draw(menu2);
			m_MyCar.m_Sprite.setPosition(550,500);
			m_Window.draw(m_MyCar.m_Sprite);
			m_Window.draw(Logo_Sprite);
		}
		m_Window.display();
		m_Window.clear();
	}
}
