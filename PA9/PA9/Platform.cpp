#include "Platform.hpp"

//function for platform 
Platform::Platform(float newXVal, float newYVal): Object(newXVal,newYVal, 70.f, 20.f, Color::Green)//initializing the pllatforms and adding color to them
{

}

//function for updating platforms
void Platform::update(float time)
{
	//nothing here since platforms are static they do not need to update
}

