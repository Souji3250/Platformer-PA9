#pragma once
#include <SFML/Graphics.hpp>

using sf::RectangleShape;
using sf::Vector2f;
using sf::Color;
using sf::RenderWindow;
class Object
{
public:
	//constructor
	Object(float xVal, float yVal, float width, float height, Color color);

	//copy constructor
	Object(const Object& newObject);

	//destructor
	virtual ~Object();

	//member functions
	virtual void update(float time) = 0;

	void draw(RenderWindow& window) const;
	sf::FloatRect getBorder()const;
	virtual std::optional<sf::FloatRect> collisionDet(const Object& newObject) const;

	//setters
	void setXValue(float newXVal);
	void setYValue(float newYVal);
	void setWidth(float newWidth);
	void setHeight(float newHeight);
	void setPosition(float newXVal, float newYVal);
	void setSize(float newWidth, float newHeight);
	void setVel(float newXVal, float newYVal);

	//getters
	float getXValue() const;
	float getYValue() const;
	float getWidth() const;
	float getHeight() const;
	Vector2f getPosition();
	Vector2f getSize() const;
	Vector2f getVel() const;



	//setters

protected:
	//protected member functions so that classes that inherit from this class will ahve access
	RectangleShape mShape;
	Vector2f mPosition;
	Vector2f mVel;
	float mWidth;
	float mHeight;

};