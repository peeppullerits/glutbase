#include <iostream>
#include <cstdlib>
#include <GL/glut.h>

#include "controls.hpp"
#include "gamestate.hpp"

extern GameState state;

using namespace std;

void Controls::doKeys(float speedRatio)
{	
	//if (state.keysState['s'])
}

void Controls::keyboardUp(unsigned char key, int x, int y)
{
	state.keysState[key] = 0;
}

void Controls::keyboard(unsigned char key, int x, int y)
{
	if (key == 27) // escape
		exit(0);

	state.keysState[key] = 1;
}
	

void Controls::mouseUp(int button, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		state.leftMouse = false;
	}
	else if (button == GLUT_RIGHT_BUTTON)
		state.rightMouse = false;
}

void Controls::mouseDown(int button, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		state.leftMouse = true;
	}
	else if (button == GLUT_RIGHT_BUTTON)
		state.rightMouse = true;
}

void Controls::mouseMotion(int x, int y)
{
	int halfW = state.w / 2.0;
	int halfH = state.h / 2.0;
	
	int relX = x - halfW;
	float ratioX = relX / halfW;
	int relY = halfH - y;
	float ratioY = relY / halfH;
}
