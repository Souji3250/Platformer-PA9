#include "Player.hpp"
//function for the starting stats of the player
Player::Player(float x, float y)
    : Object(x, y, 30.f, 30.f, sf::Color::Cyan), Jumping(false),
    moveSpeed(223.f), jumpPower(-500.f), gravity(900.f),
    score(0), highestPlatform(static_cast<int>(y))
{
    mShape.setOutlineThickness(2.f);
    mShape.setOutlineColor(sf::Color::Yellow);
}
//gets the player to jump
void Player::jump()
{
    if (!Jumping) 
    {
        mVel.y = jumpPower;
        Jumping = true;

        mShape.setFillColor(sf::Color(100, 100, 255)); 
    }
}
//adds scores that the player earns based on points
void Player::addScore(int points)
{
    score += points;
}
//changes the highest platform that the plater has reached
void Player::updateHighestPlatform(int platformY)
{
    if (platformY < highestPlatform)
    {
        int heightDifference = highestPlatform - platformY;
        highestPlatform = platformY;

        addScore(100 + heightDifference / 100);

        jumpPower = -500.f - (abs(highestPlatform) / 900.f * 50.f);
        if (jumpPower < -700.f)
        {
            jumpPower = -700.f;
        }
    }
}
//updates the game 
void Player::update(float deltaTime)
{
    mVel.y += gravity * deltaTime;

    
    mPosition += mVel * deltaTime;
    mShape.setPosition(mPosition);

   
    if (mPosition.x < 0) {
        mPosition.x = mShape.getSize().x - getSize().x;
    }
    else if (mPosition.x + getSize().x > mShape.getSize().x) {
        mPosition.x = 0;
    }
    mShape.setPosition(mPosition);
}
//gets inputs from the player to make them move
void Player::handleInput()
{
    mVel.x = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        mVel.x = -moveSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        mVel.x = moveSpeed;
    }
}
//getting the score
int Player::getScore() const
{
    return score;
}
//getting the highest platfrom from the player
int Player::getHighestPlatform() const
{
    return highestPlatform;
}
//getting the jump from the player
bool Player::getJump() const
{
    return Jumping;
}
