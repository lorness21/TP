#include "CircleOpenCV.h"

CircleOpenCV::CircleOpenCV(Mat _Matrix, Point _center, double _radius, Scalar _line_Color, double _thickness)
	: Matrix(_Matrix), center(_center),	Circle(_radius), line_Color(_line_Color), thickness(_thickness)
{

}

void CircleOpenCV::draw() const
{
	circle(Matrix, center, radius, line_Color, thickness); // using line() function to draw the line
	imshow("OpenCV Image", Matrix); //Showing the line of the circle
	waitKey(0); //Waiting for Keystroke
}