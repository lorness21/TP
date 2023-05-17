#pragma once
#include "Circle.h"

class CircleOpenCV : public Circle
{
public :
	double diameter;

private :
	CircleOpenCV(int _diameter);

	void display() const;
};

