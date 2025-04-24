#include "Game.h"
#include <sstream>
#include<SFML/Window.hpp>

PlatformGame::PlatformGame() :mWindow(sf::VideoMode({ 400, 600 }), "PlatformGame", sf::Style::Close), mPlayer(400 / 2, 600 / 2), platHeight(600)
{
	mView = mWindow.getDefaultView();
	mFont = sf::Font{};//setting font to SFML default Font

	mTextScore.setFont(mFont);
	mTextScore.setString("Score: 0");
	mTextScore.setCharacterSize(20);
	mTextScore.setFillColor(Color::Yellow);

	mPlat.emplace_back(0, 600 - 20, 400, 20, Color::Green);//placing the initial ground block

	for (int i = 0; i < 10; i++)
	{
		mPlat.emplace_back(rand() % (400 - 70), rand() % 600);
	}
}

void PlatformGame::gameApp()
{
	sf::Clock clock;
	while (mWindow.isOpen())
	{
		float time = clock.restart().asSeconds();
		while (const std::optional event = mWindow.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
					mWindow.close();
			}
			mPlayer.handleInput();
		}
		update(time);
		mWindow.clear(Color::Black);
		for (const auto& platform : mPlat) platform.draw(mWindow);
		mPlayer.draw(mWindow);
		mWindow.draw(mTextScore);
		mWindow.display();
			
	}
}

//void PlatformGame::update(float time)
//{
//	mPlayer
//}
