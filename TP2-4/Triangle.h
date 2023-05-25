#pragma once
#include <string>
#include "form.h"

class Triangle: public Form
{
protected:

	int side;
	double base;
	double hauteur;
	Triangle(int _side, double _base, double _hauteur);
};

