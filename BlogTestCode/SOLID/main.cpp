#include <iostream>
#include "Shape.h"

using namespace std;

int main()
{
	Rectangle rectangle;
	rectangle.width = 3.0f;
	rectangle.height = 4.0f;

	Circle circle;
	circle.radius = 5.0f;

	cout << "Rectangle Area: " << rectangle.GetArea() << endl;
	cout << "Circle Area: " << circle.GetArea() << endl;
}