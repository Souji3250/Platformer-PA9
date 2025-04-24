#pragma once
#include "Object.hpp"

class Platform : public Object
{
public:
	//platform class inheriting from Object class
	//constructor
	Platform(float x, float y);

	//member function for update
	void update(float deltaTime) override;//using override to make sure that when this upddate is called it is used in the context for platform.


};
