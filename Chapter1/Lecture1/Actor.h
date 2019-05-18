#include <GLFW/glfw3.h>
#include "Game2D.h"
#include <fstream>
#include <string>
class  Actor
{
public:
	virtual void moveUp(float dt) = 0;
	virtual void moveLeft(float dt) = 0;
	virtual void moveDown(float dt) = 0;
	virtual void moveRight(float dt) = 0;
};

class Command
{
public:
	virtual ~Command() {}
	virtual void execute(Actor& actor, float dt) = 0;
};
////
class UpCommand : public Command
{
public:
	virtual void execute(Actor& actor, float dt)  override
	{
		actor.moveUp(dt);
	}
};

class DownCommand : public Command
{
public:
	virtual void execute(Actor& actor, float dt)  override
	{
		actor.moveDown(dt);
	}
};

class LeftCommand : public Command
{
public:
	virtual void execute(Actor& actor, float dt)  override
	{
		actor.moveLeft(dt);
	}
};

class RightCommand : public Command
{
public:
	virtual void execute(Actor& actor, float dt)  override
	{
		actor.moveRight(dt);
	}
};
////
class InputHandler
{
public:
	Command * move_up = nullptr;
	Command * move_down = nullptr;
	Command * move_left = nullptr;
	Command * move_right = nullptr;
	//std::map<int , Command*> key_command_map;
	int keymap[4];

	InputHandler()
	{
		move_up = new UpCommand;
		move_down = new DownCommand;
		move_left = new RightCommand;
		move_right = new LeftCommand;

		std::ifstream ofs;
		ofs.open("keyfile.txt");

		std::string key;
		char read[100];
		int i = 0;
		while (!ofs.eof()) {
			ofs.getline(read, 100);
			key = read;
			keymap[i] = std::stoi(key);
			i++;
		}
	}

	void handlInput(jm::Game2D & game, Actor & actor, float dt)
	{
		
		if (game.isKeyPressed(keymap[0])) move_up->execute(actor, dt);
		if (game.isKeyPressed(keymap[1])) move_down->execute(actor, dt);
		if (game.isKeyPressed(keymap[2])) move_left->execute(actor, dt);
		if (game.isKeyPressed(keymap[3])) move_right->execute(actor, dt);

		/*if (game.isKeyPressed(GLFW_KEY_UP)) move_up->execute(actor, dt);
		if (game.isKeyPressed(GLFW_KEY_DOWN)) move_down->execute(actor, dt);
		if (game.isKeyPressed(GLFW_KEY_LEFT)) move_left->execute(actor, dt);
		if (game.isKeyPressed(GLFW_KEY_RIGHT)) move_right->execute(actor, dt);*/
	}
	
};