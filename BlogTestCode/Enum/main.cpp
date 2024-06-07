#include <iostream>

enum class Color
{
	RED,
	GREEN,
	BLUE
};

enum class TrafficLight
{
	RED,
	YELLOW,
	GREEN
};

int main()
{
	Color color = Color::RED;

	switch (color)
	{
		case Color::RED:
			std::cout << "Red\n";
		break;
		case Color::GREEN:
			std::cout << "Green\n";
		break;
		case Color::BLUE:
			std::cout << "Blue\n";
		break;
	}
}