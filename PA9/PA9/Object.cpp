#include "Object.hpp"

//function for default constructor
Object::Object(float xVal, float yVal, float width, float height, Color color) :mVel(0, 0)
{
	mShape.setPosition(Vector2f(xVal, yVal));
	mShape.setSize(Vector2f(width, height));
	mShape.setFillColor(color);

}

//function for copy constructor
Object::Object(const Object& newObject) : mShape(newObject.mShape), mVel(newObject.mVel) //setting the default to the newObjects velocity and shape values
{
}

//function for destructor
Object::~Object()
{
}

//function for drawing the object
void Object::draw(RenderWindow& window) const
{
	//recursively calling draw shapew when window is drawn
	window.draw(mShape);
}

//function for getting the boredrs of game object
sf::FloatRect Object::getBorder() const
{
	return mShape.getGlobalBounds();
}

//function for detecting collision
std::optional<sf::FloatRect> Object::collisionDet(const Object& newObject) const
{
	return getBorder().findIntersection(newObject.getBorder());
}

//function for setting the X value of Object
void Object::setXValue(float newXVal)
{
	mShape.setPosition(Vector2f(newXVal, getYValue()));//sets the new x value and then gets the current y value 
}

//function for setting the Y value of Object
void Object::setYValue(float newYVal)
{
	mShape.setPosition(Vector2f(getXValue(), newYVal));//sets the new y value then gets the current x value
}

//function for setting the width
void Object::setWidth(float newWidth)
{
	mWidth = newWidth;
}

//function for setting the height
void Object::setHeight(float newHeight)
{
	mHeight = newHeight;
}

//function for setting position of object
void Object::setPosition(float newXVal, float newYVal)
{
	mShape.setPosition(Vector2f(newXVal, newYVal));
}

//function for setting the size of the Object
void Object::setSize(float newWidth, float newHeight)
{
	mShape.setSize(Vector2f(newWidth, newHeight));
}

//function for getting the x value of the object
float Object::getXValue() const
{
	return mShape.getPosition().x;
}

//function for getting the Y value of the object
float Object::getYValue() const
{
	return mShape.getPosition().y;
}

//function for getting the width of object
float Object::getWidth() const
{
	return mWidth;
}

//function for getting the height of object
float Object::getHeight() const
{
	return mHeight;
}

//function for getting the position of object
Vector2f Object::getPosition()
{
	return mShape.getPosition();
}

//function for geting the size of the object
Vector2f Object::getSize() const
{
	return mShape.getSize();
}





