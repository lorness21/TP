#pragma once
#include "Rectangle.h"

class RectangleConsole : public Rectangle
{
public:

	RectangleConsole(int _longueur, int _largeur);

	void draw() const;
};

