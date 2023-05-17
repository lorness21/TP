#include <iostream>
#include <math.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "Circle.h"
#include "rectangle.h"

using namespace cv;
using namespace std;

int main()
{
	int choix = 1;

	Mat BlackMatrix(1000, 1000, CV_8UC3, Scalar(0, 0, 0)); //Declring the Black matrix
	Point center(500, 500); //Starting Point of the line
	double thickness = 2; //Thickness of the line
	namedWindow("OpenCV Image"); //Declaring a window to show the line

	while (choix != 0)
	{
		std::cout << "rectangle : 1 " << std::endl << "cercle    : 2 " << std::endl << "sortir    : 0 " << std::endl;
		std::cin >> choix;

		if (choix == 2)
		{
			int diameter;

			std::cout << "Rentrer un diametre :" << std::endl;
			std::cin >> diameter;

			Scalar line_Color(0, 0, 255);
			double radius = diameter / 2.0;
			circle(BlackMatrix, center, radius, line_Color, thickness); // using line() function to draw the line
			imshow("OpenCV Image", BlackMatrix); //Showing the line of the circle
			waitKey(0); //Waiting for Keystroke

			double rIn = ((diameter - 1) / 2) - thickness;
			double rOut = ((diameter - 1) / 2) + thickness;

			for (int y = 0; y < diameter; y++)
			{
				for (int x = 0; x < diameter; x++)
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

		else if (choix == 1)
		{
			int largeur, longueur;

			std::cout << "Rentrer une largeur : " << std::endl;
			std::cin >> largeur;
			std::cout << "Rentrer une longueur : " << std::endl;
			std::cin >> longueur;

			Scalar line_Color(0, 255, 0); //Color of the rectangle
			Point Starting(500, 500); //Declaring the starting coordinate
			Point Ending(500 + longueur,500 + largeur); //Declaring the ending coordinate
			rectangle(BlackMatrix, Starting, Ending, line_Color, thickness); //Drawing the rectangle
			imshow("OpenCV Image", BlackMatrix); //Showing the rectangle
			waitKey(0); //Waiting for Keystroke

			for (int i_l = 0; i_l < largeur; i_l++)
			{
				for (int i_L = 0; i_L < longueur; i_L++)
				{
					if (i_l == 0 || i_l == largeur - 1)
					{
						std::cout << "#";
					}

					else if (i_L == 0 || i_L == longueur - 1)
					{
						std::cout << "#";
					}

					else
					{
						std::cout << " ";
					}
				}
				std::cout << std::endl;
			}
		}
	}
	return 0;
}