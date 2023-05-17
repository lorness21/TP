#pragma once

class Circle
{
private :
	double diameter;

private :
	virtual void display() const;

protected : 
	Circle(int _diameter);
};

