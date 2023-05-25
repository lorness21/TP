#pragma once
#include "Triangle.h"

class TriangleConsole : public Triangle
{
private:

	double thickness;

public:

	TriangleConsole(int _side, double _base, double _hauteur, double _thickness);

	void draw() const;

};

