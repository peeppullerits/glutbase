#include <cmath>
#include "vec2.hpp"

Vec2::Vec2() : x(0), y(0)
{
	
}

Vec2::Vec2(float x, float y) : x(x), y(y)
{
	
}

float degToRad(float angleDeg)
{
	float angleRad = angleDeg * M_PI / 180.0;
	return angleRad;
}

float radToDeg(float angleRad)
{
	return angleRad / M_PI * 180.0;
}

void Vec2::rotate(float angleDeg)
{
	float angleRad = degToRad(angleDeg);
	float cosAng = cos(angleRad);
	float sinAng = sin(angleRad);
	float newX = (x * cosAng) - (y * sinAng);
	float newY = (x * sinAng) + (y * cosAng);
	x = newX;
	y = newY;
}

void Vec2::getDir(float dirDeg)
{
	float dirRad = degToRad(dirDeg);
	x = cos(dirRad);
	y = sin(dirRad);
}

float Vec2::getAngle()
{
	float angleRad = atan2(y, x);
	return radToDeg(angleRad);
}
