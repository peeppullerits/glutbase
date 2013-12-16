#ifndef _CONTROLS_HPP
#define _CONTROLS_HPP

class Controls
{
public:
	void doKeys(float speedRatio);
	void keyboardUp(unsigned char key, int x, int y);
	void keyboard(unsigned char key, int x, int y);
	
	void mouseUp(int button, int x, int y);
	void mouseDown(int button, int x, int y);
	void mouseMotion(int x, int y);
};

#endif
