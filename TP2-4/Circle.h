#pragma once

class Circle
{
public :

	virtual void draw() const;

protected : 
	double radius;

	Circle(int _radius);
};

