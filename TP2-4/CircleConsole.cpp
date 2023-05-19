#include "CircleConsole.h"
#include <iostream>

CircleConsole::CircleConsole(double _radius, double _thickness)
	: Circle(_radius), thickness(_thickness)
{

}

void CircleConsole::draw() const
{
	double rIn = (radius / 2) - thickness;
	double rOut = (radius / 2) + thickness;

	for (int y = 0; y < (radius * 2); y++)
	{
		for (int x = 0; x < (radius * 2); x++)
		{
			double value = (x - radius) * (x - radius) + (y - radius) * (y - radius);
			if (value >= rIn * rIn && value <= rOut * rOut)
			{
				std::cout << '#';
			}
			else
			{
				std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}
}
