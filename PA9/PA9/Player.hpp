#pragma once
#include "Object.hpp"

class Player : public Object
{
public:
	Player(float x, float y);

	int getScore() const;
	int getHighestPlatform() const;
	bool getIsJumping() const;

	void update(float deltaTime) override;
	void handleInput();
	void jump();
	void addScore(int points);
	void updateHighestPlatform(int platformY);


private:
	const float moveSpeed;
	int score;
	int highestPlatform;
	bool isJumping;
	float jumpForce;
	const float gravity;


};

