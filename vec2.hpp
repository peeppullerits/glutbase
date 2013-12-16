#ifndef _VEC2_HPP
#define _VEC2_HPP

class Vec2
{
public:
	float x, y;
	
	Vec2();
	Vec2(float x, float y);
	void rotate(float dir);
	void getDir(float dir);
	float getAngle();
};

#endif
