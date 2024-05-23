#pragma once
class Player
{
public:
	Player();
	~Player();

private:
	class Character* character;
	class Controller* controller;
	class Status* status;

private:
	int playerID;
};

