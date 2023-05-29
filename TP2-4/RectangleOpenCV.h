
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
	Scalar line_Color;
	Point Starting;
	Point Ending;
	double thickness;

public :

	RectangleOpenCV(int _longueur, int _largeur, Mat _Matrix, Scalar _line_Color, double _thickness, Point _Starting, Point _Ending);

	void draw() const;
};

