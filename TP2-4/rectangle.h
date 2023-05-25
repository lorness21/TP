#pragma once
#include <string>
#include "form.h"

class Rectangle : public Form
{
protected :

	double largeur;
	double longueur;

	Rectangle(int _largeur, int _longueur);
};