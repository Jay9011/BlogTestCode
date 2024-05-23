#pragma once

class Shape
{
public:
	virtual void Draw() {};
};

class AreaCalculator
{
public:
	virtual float GetArea() = 0;
};

class Rectangle : public Shape, public AreaCalculator
{
public:
	float GetArea() override
	{
		return width * height;
	}

	float width;
	float height;
};

class Circle : public Shape, public AreaCalculator
{
public:
	float GetArea() override
	{
		return 3.14f * radius * radius;
	}

	float radius;
};