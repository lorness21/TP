#include "TriangleConsole.h"
#include <iostream>

TriangleConsole::TriangleConsole(int _side, double _base, double _hauteur, double _thickness)
	: Triangle(_side, _base, _hauteur), thickness(_thickness)
{

}

void TriangleConsole::draw() const
{
	for (int y = 0; y <= side / 2; ++y)
	{
		for (int x = 0; x < side; ++x)
		{
			if (x == side / 2 - y || x == side / 2 + y || y == side / 2)
				std::cout << '#';
			else
				std::cout << ' ';
		}

		std::cout << std::endl;
	}
}