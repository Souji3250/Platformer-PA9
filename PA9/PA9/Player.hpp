#pragma once
#include "Object.hpp"

class Player : public Object
{
public:
	//constructor for player position
	Player(float x, float y);
	//keeps track of the score 
	int getScore() const;
	//tracks what the highest platform is
	int getHighestPlatform() const;
	bool getJump() const;
	//updates the tiime in game
	void update(float deltaTime) override;
	//inputs to control player
	void handleInput();
	//jump function for the player
	void jump();
	//adds up the scores as game goes on
	void addScore(int points);
	//when new high platform reached higest platform is upaded
	void updateHighestPlatform(int platformY);


private:
	//players speed
	const float moveSpeed;
	//player score
	int score;
	//players height platform reached
	int highestPlatform;
	//says rather the player is jumping or not
	bool Jumping;
	//gives the power of the jumps
	float jumpPower;
	//how much gravity is effecting the player and their jumps
	const float gravity;


};

