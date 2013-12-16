#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <GL/glut.h>

#include "engine.hpp"
#include "gamestate.hpp"
#include "controls.hpp"
#include "renderer.hpp"

extern GameState state;
extern Controls controls;
extern Renderer renderer;

void Engine::init(int w, int h)
{
	state.w = w;
	state.h = h;
	state.leftMouse = state.rightMouse = false;

	memset(state.keysState, 0, 256);
}

void doActions()
{

}

void doMovements(float speedRatio)
{
}

void Engine::doGameLoop()
{	
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	int timeInterval = currentTime - state.previousTime;
	int frameDiff = currentTime - state.previousFrame;
	state.spf = frameDiff / 1000.0;

	// % of a full cycle 
	float speedRatio = frameDiff / 50.0;
	doActions();
	doMovements(speedRatio);
	controls.doKeys(speedRatio);
	renderer.display();
	
	state.frameCount++;
	state.previousFrame = currentTime;
	
	if(timeInterval > 1000)
    {
    	state.fps = state.frameCount / (timeInterval / 1000.0f);
        state.previousTime = currentTime;
        state.frameCount = 0;
    }
}

