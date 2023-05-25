#pragma once
#include "Triangle.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


using namespace cv;
using namespace std;



class TriangleOpenCV : public Triangle
{
private:

	Mat Matrix;
	Point pt1;
	Point pt2;
	Point pt3;
	Scalar line_Color;
	double thickness;

public:

	TriangleOpenCV(int _side, double _base, double _hauteur, Mat _Matrix, Point _pt1, Point _pt2, Point _pt3,Scalar _line_Color, double _thickness);

	void draw() const;

};

