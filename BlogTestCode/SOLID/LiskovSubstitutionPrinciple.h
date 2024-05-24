#pragma once
#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void Eat() {};

	virtual Animal* GetInstance()
	{
		cout << "Animal instance created" << endl;
		return new Animal();
	}
};

class Bird : public Animal
{
public:
	virtual void Fly() = 0;
	virtual void SetAltitude(int altitude)
	{
		if (altitude <= 0)
		{
			throw "Altitude must be greater than 0";
		}
	}
};

class Eagle : public Bird
{
public:
	void Fly() override
	{
		cout << "Eagle is flying" << endl;
	}
	void SetAltitude(int altitude) override
	{
		if (altitude <= 0)
		{
			throw "Altitude must be greater than 0";
		}

		cout << "Eagle is flying at " << altitude << " meters" << endl;
	}
	void Eat() override
	{
		cout << "Eagle is eating" << endl;
	}

	Eagle* GetInstance() override
	{
		cout << "Eagle instance created" << endl;
		return new Eagle();
	}
};

class Penguin : public Bird
{
public:
	void Fly() override
	{
		throw "Penguins can't fly";
	};
	void SetAltitude(int altitude) override
	{
		if (altitude != 0)
		{
			throw "Penguins can't fly";
		}

		cout << "Penguin is swimming" << endl;
	};
	void Eat() override
	{
		cout << "Penguin is eating" << endl;
	}
};

class BirdController
{
public:
	virtual void Input(Bird* bird, int x, int y)
	{
		bird->Fly();
		bird->SetAltitude(y);
	}
};

class AnimalCalculator
{
public:
	virtual int GetAltitude(int input)
	{
		if (input < 0)
		{
			return 0;
		}

		return input;
	}
};

class BirdCalculator : public AnimalCalculator
{
public:
	int GetAltitude(int input) override
	{
		return input;
	}
};

class Character
{
public:
	virtual void Hit(int damage)
	{
		hp -= damage;

		if (hp <= 0)
		{
			hp = 0;
		}
	}
protected:
	int hp;
};

class Undead : public Character
{
public:
	void Hit(int damage) override
	{
		hp -= damage;
	}
};