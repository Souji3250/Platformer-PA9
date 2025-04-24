#include "Platform.hpp"

//function for platform 
Platform::Platform(float x, float y, float width, float height, Color color) : Object(x,y,width,height,color)//initializing the pllatforms and adding color to them
{
}

//function for updating platforms
void Platform::update(float time)
{
	//nothing here since platforms are static they do not need to update
}

