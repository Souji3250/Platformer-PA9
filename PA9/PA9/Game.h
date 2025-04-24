#pragma once
#include "Player.hpp"
#include "Platform.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class PlatformGame
{
public:
	//constructor
	PlatformGame();

	//member function 
	void gameApp();

private:
	//private members
	Player mPlayer;
	RenderWindow mWindow;
	sf::View mView;
	sf::Font mFont;
	sf::Text mTextScore{ mFont, "", 20 };
	std::vector<Platform> mPlat;
	float platHeight;

	//private member functions
	void update(float time);
	void collisionDet();

};