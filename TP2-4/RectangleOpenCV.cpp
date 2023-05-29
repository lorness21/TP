#include "RectangleOpenCV.h"

RectangleOpenCV::RectangleOpenCV(int _longueur, int _largeur, Mat _Matrix, Scalar _line_Color, double _thickness, Point _Starting, Point _Ending)
	: Rectangle(_longueur, _largeur), Matrix(_Matrix), line_Color(_line_Color), thickness(_thickness), Starting(_Starting), Ending(_Ending)
{

}

void RectangleOpenCV::draw() const
{
	rectangle(Matrix, Starting, Ending, line_Color, thickness); //Drawing the rectangle
	imshow("OpenCV Image", Matrix); //Showing the rectangle
	waitKey(0); //Waiting for Keystroke
}
