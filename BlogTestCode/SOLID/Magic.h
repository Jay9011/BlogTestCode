#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Spell 인터페이스
class Spell
{
public:
	// 추상화 메서드
	virtual void Cast() = 0;
};

class Fireball : public Spell
{
public:
	void Cast() override
	{
		std::cout << "Casting Fireball!" << std::endl;
	}
};
class Frostbolt : public Spell
{
public:
	void Cast() override
	{
		std::cout << "Casting Frostbolt!" << std::endl;
	}
};

// Magic 클래스
class Magic
{
public:
	void AddMagic(string magicName, Spell* spell)
	{
		magicList.insert(make_pair(magicName, spell));
	}

	void CastSpell(string magicName)
	{
		auto magic = magicList.find(magicName);
		if (magic != magicList.end())
		{
			magic->second->Cast();
		}
		else
		{
			std::cout << "Unknown spell!" << std::endl;
		}
	}

private:
	unordered_map<string, Spell*> magicList;
};
