#pragma once
#include "Object.hpp"

class Platform : public Object
{
public:
	Platform(float x, float y);
	void update(float deltaTime) override;


};
