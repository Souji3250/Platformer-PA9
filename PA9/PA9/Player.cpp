#include "Player.hpp"

Player::Player(float x, float y)
    : Object(x, y, 30.f, 30.f, sf::Color::Blue), isJumping(false),
    moveSpeed(200.f), jumpForce(-600.f), gravity(1000.f),
    score(0), highestPlatform(static_cast<int>(y))
{
    mShape.setOutlineThickness(2.f);
    mShape.setOutlineColor(sf::Color::White);
}

int Player::getScore() const
{
    return score;
}

int Player::getHighestPlatform() const
{
    return highestPlatform;
}

bool Player::getIsJumping() const
{
    return isJumping;
}

void Player::jump()
{
    if (!isJumping) 
    {
        mVel.y = jumpForce;
        isJumping = true;

        mShape.setFillColor(sf::Color(100, 100, 255)); 
    }
}

void Player::addScore(int points)
{
    score += points;
}

void Player::updateHighestPlatform(int platformY)
{
    if (platformY < highestPlatform)
    {
        int heightDifference = highestPlatform - platformY;
        highestPlatform = platformY;

        addScore(10 + heightDifference / 10);

        jumpForce = -600.f - (abs(highestPlatform) / 1000.f * 50.f);
        if (jumpForce < -800.f)
        {
            jumpForce = -800.f;
        }
    }
}


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

void Player::handleInput()
{
    mVel.x = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        mVel.x = -moveSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        mVel.x = moveSpeed;
    }
}
