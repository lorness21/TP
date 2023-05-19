#pragma once
#include "Circle.h"

class CircleConsole : public Circle
{
private :

	double thickness;

public :

	CircleConsole(double _radius, double _thickness);

	void draw() const;
};

