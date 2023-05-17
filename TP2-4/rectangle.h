#pragma once

#include <string>

class rectangle
{
private:
	double largeur, longueur;
public:
	rectangle(int _largeur, int _longueur);
	//rectangle(std::string id, int x, int y, double l, double w, int edge_width, int edge_color, int fill_color);

	void dessiner();
};

