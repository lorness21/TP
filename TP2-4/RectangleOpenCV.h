
#pragma once
#include "Rectangle.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

class RectangleOpenCV : public Rectangle
{
private :

	Mat Matrix;
	Point Starting;
	Point Ending;
	Scalar line_Color;
	double thickness;

public :

	RectangleOpenCV(int _longueur, int _largeur, Mat _Matrix, Scalar _line_Color, double _thickness);

	void draw() const;
};

