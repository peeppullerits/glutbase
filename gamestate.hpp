#ifndef _GAME_STATE_HPP
#define _GAME_STATE_HPP

#include <vector>
#include "vec2.hpp"

using namespace std;

class GameState
{
public:
	char keysState[256];
	bool leftMouse, rightMouse;
		
	int w, h;
	
	int frameCount, previousTime, previousFrame;
	// frames per second, seconds per frame
	float fps, spf;
};

#endif
