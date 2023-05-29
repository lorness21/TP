#include <iostream>
#include <fstream>
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

void ConsoleFunctionCircle()
{
	double Radius;
	double thickness = 2; //Thickness of the line
	std::cout << "Rentrer un rayon :" << std::endl;
	std::cin >> Radius;
	CircleConsole C1(Radius, thickness);
	C1.draw();
}

void ConsoleFunctionRectangle()
{
	int largeur, longueur;

	std::cout << "Rentrer une largeur : " << std::endl;
	std::cin >> largeur;
	std::cout << "Rentrer une longueur : " << std::endl;
	std::cin >> longueur;

	RectangleConsole R1(longueur, largeur);
	R1.draw();
}

void ConsoleFunctionTriangle()
{
	int side;

	std::cout << "Construction avec la longueur d'un côté" << endl << "Veuillez saisir la longueur :" << endl;
	std::cin >> side;

	TriangleConsole TR1(side, 0, 0, 0);
	TR1.draw();
}

void ConsoleFunction(int &nbrC, int &nbrR, int &nbrT)
{
	int choice2 = 1;

	while (choice2 != 0)
	{
		std::cout << "rectangle : 1 " << std::endl << "cercle    : 2 " << std::endl << "triangle  : 3" << std::endl << "sortir    : 0 " << std::endl;
		std::cin >> choice2;

		if (choice2 == 2)
		{
			ConsoleFunctionCircle();
			nbrC += 1;
		}

		else if (choice2 == 1)
		{
			ConsoleFunctionRectangle();
			nbrR += 1;
		}

		else if (choice2 == 3)
		{
			ConsoleFunctionTriangle();
			nbrT += 1;
		}

		else if (choice2 == 0)
		{
			choice2 = 0;
		}
	}
}

void saveString(int number, std::string type, std::ofstream& fileToWrite)
{
	fileToWrite << type << " : " << number << std::endl;
}

int main()
{
	int choice1 = 0;
	int nbrR = 0, nbrC = 0, nbrT = 0;

	std::cout << "OpenCV   : 1" << std::endl << "Console  : 2" << std::endl;
	std::cin >> choice1;
	std::cout << std::endl;

	if (choice1 == 2)
	{
		ConsoleFunction(nbrC, nbrR, nbrT);
	}

	if (choice1 == 1)
	{
		std::cout << "Touches a utiliser pour afficher les formes :" << std::endl << std::endl;
		std::cout << "q ou Q : Sortir" << std::endl;
		std::cout << "c ou C : Afficher un Cercle" << std::endl;
		std::cout << "r ou R : Afficher un Rectangle" << std::endl;
		std::cout << "t ou T : Afficher un Triangle" << std::endl << std::endl;

		Mat BlackMatrix(1000, 1000, CV_8UC3, Scalar(0, 0, 0)); //Declring the Black matrix
		namedWindow("OpenCV Image"); //Declaring a window to show the line
		imshow("OpenCV Image", BlackMatrix);

		while (true)
		{
			srand((unsigned) time(NULL));
			int key = waitKey(0);

			double thickness = rand() % 10 + 1;
			Scalar line_Color(rand() % 255 + 0, rand() % 255 + 0, rand() % 255 + 0);

			if (key == 'q' || key == 'Q')
			{
				break;
			}

			if (key == 'c' || key == 'C')
			{
				Point center(rand() % 1000 + 1, rand() % 1000 + 1);
				int radius = rand() % 500 + 1;
				CircleOpenCV c1(BlackMatrix, center, radius, line_Color, thickness);
				c1.draw();
				nbrC += 1;
			}

			if (key == 'r' || key == 'R')
			{
				int a = rand() % 1000 + 0;
				int b = rand() % 1000 + 0;
				int largeur = rand() % 500 + 10;
				int longueur = rand() % 500 + 10;
				Point Starting(a, b); //Declaring the starting coordinate
				Point Ending(a + longueur, b + largeur); //Declaring the ending coordinate
				RectangleOpenCV r1(longueur, largeur, BlackMatrix, line_Color, thickness, Starting, Ending);
				r1.draw();
				nbrR += 1;
			}

			if (key == 't' || key == 'T')
			{
				int base = rand() % 1000 + 10;
				int hauteur = rand() % 1000 + 10;
				int a = rand() % 1000 + 0;
				int b = rand() % 1000 + 0;
				Point pt1(a, b);
				Point pt2(a + base, b);
				Point pt3(a + (base / 2), b - hauteur);
				TriangleOpenCV tr1(0, base, hauteur, BlackMatrix, pt1, pt2, pt3, line_Color, thickness);
				tr1.draw();
				nbrT += 1;
			}
		}
		destroyAllWindows();
	}

	//std::remove("fichier.txt"); //function needed if we do not want to keep the history of what is put in the file, the function deletes the file if it already exists
	std::ofstream fileToWrite("fichier.txt", std::ios::app);

	if (fileToWrite.is_open())
	{
		fileToWrite << std::endl << "--- Nombre de formes creees ---" << std::endl << std::endl;
		saveString(nbrC, "Cercles", fileToWrite);
		saveString(nbrR, "Rectangles", fileToWrite);
		saveString(nbrT, "Triangles", fileToWrite);
	}

	fileToWrite.close();

	return 0;
}