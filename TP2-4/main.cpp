#include <iostream>
#include <math.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "CircleOpenCV.h"
#include "CircleConsole.h"
#include "RectangleOpenCV.h"
#include "RectangleConsole.h"
#include "TriangleConsole.h"
#include "TriangleOpenCV.h"


using namespace cv;
using namespace std;

void FunctionCircle(Mat Matrix, int choice2)
{
	double Radius;

	std::cout << "Rentrer un rayon :" << std::endl;
	std::cin >> Radius;

	Point center(500, 500);
	double thickness = 2;
	Scalar line_Color(0, 0, 255);

	if (choice2 == 1)
	{
		CircleOpenCV c1(Matrix, center, Radius, line_Color, thickness);
		c1.draw();
	}
	else
	{
		CircleConsole C1(Radius, thickness);
		C1.draw();
	}
}

void FunctionRectangle(Mat Matrix, int choice2)
{
	int largeur, longueur;

	std::cout << "Rentrer une largeur : " << std::endl;
	std::cin >> largeur;
	std::cout << "Rentrer une longueur : " << std::endl;
	std::cin >> longueur;

	Scalar line_Color(0, 255, 0); //Color of the rectangle
	Point Starting(500, 500); //Declaring the starting coordinate
	Point Ending(500 + longueur, 500 + largeur); //Declaring the ending coordinate
	double thickness = 2; //Thickness of the line

	if (choice2 == 1)
	{
		RectangleOpenCV r1(longueur, largeur, Matrix, line_Color, thickness);
		r1.draw();
	}
	else
	{
		RectangleConsole R1(longueur, largeur);
		R1.draw();
	}
}

void FunctionTriangle(Mat Matrix, int choice2)
{
	int side;
	int base;
	int hauteur;
	
	
	if (choice2 == 1)
	{
		std::cout << "Construction avec la base et la hauteur" << endl << "Veuillez saisir la base" << endl;
		std::cin >> base;
		std::cout << "Veuillez saisir la hauteur" << endl;
		std::cin >> hauteur;

		Scalar line_Color(0, 255, 0);
		Point pt1(500, 500);
		Point pt2(500 + base, 500);
		Point pt3(500 + (base/2), 500 - hauteur);
		double thickness = 2;

		TriangleOpenCV tr1(0, base, hauteur, Matrix, pt1, pt2, pt3, line_Color, thickness);
		tr1.draw();
	}
	else
	{
		std::cout << "Construction avec la longueur d'un côté" << endl << "Veuillez saisir la longueur :" << endl;
		std::cin >> side;

		TriangleConsole TR1(side, 0, 0, 0);
		TR1.draw();
	}
}


int main()
{
	int choice1 = 0;
	int choice2 = 1;

	Mat BlackMatrix(1000, 1000, CV_8UC3, Scalar(0, 0, 0)); //Declring the Black matrix
	Point center(500, 500); //Starting Point of the line
	namedWindow("OpenCV Image"); //Declaring a window to show the line

	std::cout << "OpenCV   : 1" << std::endl << "Console  : 2" << std::endl;
	std::cin >> choice1;

	while (choice2 != 0)
	{
		std::cout << "rectangle : 1 " << std::endl << "cercle    : 2 " << std::endl  << "triangle : 3" << std::endl << "sortir    : 0 " << std::endl;
		std::cin >> choice2;

		if (choice2 == 2)
		{
			FunctionCircle(BlackMatrix, choice1);
		}

		else if (choice2 == 1)
		{
			FunctionRectangle(BlackMatrix, choice1);
		}

		else if(choice2 == 3)
		{
			FunctionTriangle(BlackMatrix, choice1);
		}

		else if (choice2 == 0)
		{
			return 0;
		}
	}
}