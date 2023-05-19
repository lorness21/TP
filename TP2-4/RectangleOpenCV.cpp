#include "RectangleOpenCV.h"

RectangleOpenCV::RectangleOpenCV(int _longueur, int _largeur, Mat _Matrix, Scalar _line_Color, double _thickness)
	: Rectangle(_longueur, _largeur), Matrix(_Matrix), line_Color(_line_Color), thickness(_thickness)
{

}

void RectangleOpenCV::draw() const
{
	Point Starting(500, 500); //Declaring the starting coordinate
	Point Ending(500 + longueur, 500 + largeur); //Declaring the ending coordinate
	rectangle(Matrix, Starting, Ending, line_Color, thickness); //Drawing the rectangle
	imshow("OpenCV Image", Matrix); //Showing the rectangle
	waitKey(0); //Waiting for Keystroke
}
