#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include "renderer.hpp"
#include "vec2.hpp"

extern GameState state;


void Renderer::doCamera()
{
	double srcX, srcY, srcZ, dstX, dstY, dstZ;
	double vecX, vecY;

	srcX = 0.0;
	srcY = 0.0;
	srcZ = 25.0;
	dstX = 0.0;
	dstY = 0.0;
	dstZ = 1.0;
	gluLookAt(srcX, srcY, srcZ, dstX, dstY, dstZ, 0.0, 1.0, 0.0);

	//GameObj &camera = *state.camera;
	//camera.moveTo(srcX, srcY, srcZ);
}


void colorRgb(int r, int g, int b)
{
	float rf, gf, bf;
	rf = r / 255.0;
	gf = g / 255.0;
	bf = b / 255.0;
	glColor3f(rf, gf, bf);
}


void Renderer::renderWorld()
{

}

void showText(int x, int y, void *font, char *buf)
{
	std::string s(buf);
	glRasterPos2i(x, y);
	
	for (std::string::iterator i = s.begin(); i != s.end(); ++i)
	{
	    char c = *i;
	    glutBitmapCharacter(font, c);
	}	
}

void renderUi()
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, 100.0, 0.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	
	//glDisable(GL_BLEND);
	//glDisable(GL_ALPHA_TEST);
	glColor3f(1.0, 1.0, 1.0);
	
	void * font = GLUT_BITMAP_9_BY_15;
	char *buf = new char[256];

	
	snprintf(buf, 256, "fps %.2f spf %.2f", state.fps, state.spf);
	showText(1, 1, font, buf);
	
	//glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	
	//glEnable(GL_BLEND);
	//glEnable(GL_ALPHA_TEST);
}

void Renderer::display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
	glClearColor(0.0, 0.1, 0.0, 1.0);
  
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 

  	float fov = 75.0;
  	gluPerspective(fov, (double)state.w / (double)state.h, 1.0, 5000.0);
  	
  	glMatrixMode(GL_MODELVIEW);
  	glLoadIdentity();             
  	
  	doCamera();
  
  	glColor4f( 1.0, 1.0, 1.0, 1.0 );
	renderWorld();
	
	renderUi();
	glutSwapBuffers();
  	glFlush();
}


