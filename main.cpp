#include <iostream>
#include <GL/glut.h>

#include "engine.hpp"
#include "gamestate.hpp"
#include "renderer.hpp"
#include "controls.hpp"

Engine engine;
GameState state;
Renderer renderer;
Controls controls;

void keyboardUp(unsigned char key, int x, int y)
{
	controls.keyboardUp(key, x, y);
}
	
void keyboard(unsigned char key, int x, int y)
{
	controls.keyboard(key, x, y);
} 

void mouseMotion(int x, int y)
{
	controls.mouseMotion(x, y);
	
}

void display()
{
	renderer.display();
}

void doGameLoop()
{
	engine.doGameLoop();
}

void initGlState()
{
	//glEnable( GL_TEXTURE_2D );
	//glEnable(GL_DEPTH_TEST);
	//glEnable(GL_ALPHA_TEST);
	//glAlphaFunc(GL_GREATER,0.9f);
			
	//glShadeModel(GL_FLAT);
	//glEnable (GL_BLEND);
    //glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glEnable(GL_ALPHA_TEST);
    
    //glDisable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);

	/*
	glTexParameteri( GL_TEXTURE_2D, 
                 GL_TEXTURE_WRAP_S, 
		 GL_REPEAT ); 
	glTexParameteri( GL_TEXTURE_2D, 
                 GL_TEXTURE_WRAP_T, 
                 GL_REPEAT );
	*/
}

void mouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
		controls.mouseDown(button, x, y);
	else if (state == GLUT_UP)
		controls.mouseUp(button, x, y);
}

void init(void)
{	
	initGlState();
	 	
	glutDisplayFunc(display);
	glutIdleFunc(doGameLoop); 
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutPassiveMotionFunc(mouseMotion);
  
	glutSetCursor(GLUT_CURSOR_NONE);
    std::cout << " init done" << std::endl;
    
    printf("OpenGL version: %s\n",
    glGetString(GL_VERSION));
}

int main(int argc, char **argv)
{
	int w = 1280;
	int h = 800;
	
	std::cout << "Starting.." << std::endl;
  	glutInit(&argc,argv);
  	
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA);
    glutInitWindowSize(w, h);
    glutInitWindowPosition(0, 0);
  	glutCreateWindow("GLUT base");
  	glutFullScreen();
	
  	std::cout << "Doing init" << std::endl;
  	engine.init(w, h);	
  	init();
  	std::cout << "Doing main loop" << std::endl;
  	glutMainLoop();
}
