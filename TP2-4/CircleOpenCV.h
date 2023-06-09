#pragma once
#include "Circle.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

class CircleOpenCV : public Circle
{
private :

	Mat Matrix;
	Point center;
	Scalar line_Color;
	double thickness;

public :

	CircleOpenCV(Mat _Matrix, Point _center, double _radius, Scalar _line_Color, double _thickness);

	void draw() const;
};

