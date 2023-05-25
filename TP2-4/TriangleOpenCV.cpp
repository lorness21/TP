#include "TriangleOpenCV.h"

TriangleOpenCV::TriangleOpenCV(int _side, double _base, double _hauteur, Mat _Matrix, Point _pt1, Point _pt2, Point _pt3 ,Scalar _line_Color, double _thickness)
	: Triangle(_side, _base, _hauteur), Matrix(_Matrix), pt1(_pt1), pt2(_pt2), pt3(_pt3), line_Color(_line_Color), thickness(_thickness)
{

}

void TriangleOpenCV::draw() const
{
	line(Matrix, pt1, pt2, line_Color, thickness);
	line(Matrix, pt2, pt3, line_Color, thickness);
	line(Matrix, pt3, pt1, line_Color, thickness);
	imshow("OpenCV Image", Matrix); //Shawing the triangle
	waitKey(0); //Wainting for Keystroke

}