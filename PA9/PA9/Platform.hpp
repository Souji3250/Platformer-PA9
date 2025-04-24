#pragma once
#include "Object.hpp"

class Platform : public Object
{
public:
	//platform class inheriting from Object class
	//constructor
	Platform(float x, float y);

	//member function
	void update(float deltaTime) override;


};
