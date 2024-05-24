#include <iostream>
#include <exception>

#include "LiskovSubstitutionPrinciple.h"

using namespace std;

int main()
{
	Bird* birds[2] = { new Eagle(), new Penguin() };
	for (size_t i = 0; i < 2; i++)
	{
		birds[i]->SetAltitude(100);
	}

	delete[] birds;
}