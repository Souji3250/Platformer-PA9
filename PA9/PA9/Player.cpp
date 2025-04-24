#include "Player.hpp"
//function for the starting stats of the player
Player::Player(float x, float y)
    : Object(x, y, 30.f, 30.f, sf::Color::Cyan), mJumping(false),
    mMoveSpeed(223.f), mJumpPower(-500.f), mGravity(900.f),
    mScore(0), mHighestPlatform(static_cast<int>(y))//sets the default vlaues for the player, using static_cast to convert highest platform from float to integer for updating highest platform and scoring purposes
    
{
    mShape.setOutlineThickness(2.f);
    mShape.setOutlineColor(sf::Color::Yellow);
}
//gets the player to jump
void Player::jump()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !mJumping)
    {
        setVel(getVel().x, mJumpPower);
        mJumping = true;
    }
}
//adds scores that the player earns based on points
void Player::addScore(int points)
{
    mScore += points;
}
//changes the highest platform that the plater has reached
void Player::updateHighestPlatform(int platform)
{
    if (platform < mHighestPlatform)
    {
        int heightDifference = mHighestPlatform - platform;
        mHighestPlatform = platform;

        addScore(100 + heightDifference / 100);

        mJumpPower = -500.f - (abs(mHighestPlatform) / 900.f * 50.f);
        if (mJumpPower < -700.f)
        {
            mJumpPower = -700.f;
        }
    }
}
//updates the game 
void Player::update(float time)
{
    mVel.y += mGravity * time;

    
 
    mPosition += mVel * time;
    mShape.setPosition(mPosition);

   
    if (mPosition.x < 0) //updates the players horizontal movement
    {
        mPosition.x = mShape.getSize().x - getSize().x;
    }
    else if (mPosition.x + getSize().x > mShape.getSize().x) 
    {
        mPosition.x = 0;
    }
    mShape.setPosition(mPosition);
}
//gets inputs from the player to make them move
void Player::handleInput()
{
    mVel.x = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))//if A is pressed then the player will move in a negative velocity which is to the left
    {
        mVel.x = -mMoveSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))//id D is pressed the player will move in a positive velocity which is to the right 
    {
        mVel.x = mMoveSpeed;
    }
}
//getting the mScore
int Player::getScore() const
{
    return mScore;
}
//getting the highest platfrom from the player
int Player::getHighestPlatform() const
{
    return mHighestPlatform;
}
//getting the jump from the player
bool Player::getJump() const
{
    return mJumping;
}
