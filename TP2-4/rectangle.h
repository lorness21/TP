#pragma once
#include <string>

class Rectangle
{
public:

	virtual void draw() const;

protected :

	double largeur;
	double longueur;

	Rectangle(int _largeur, int _longueur);
};