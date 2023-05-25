#pragma once
#include <string>
class Triangle
{
public:
	virtual void draw() const;

protected:

	int side;
	double base;
	double hauteur;
	Triangle(int _side, double _base, double _hauteur);
};

