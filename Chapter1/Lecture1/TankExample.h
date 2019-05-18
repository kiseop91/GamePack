#pragma once

#include "Game2D.h"
#include <vector>
#include <fstream>
#include "Actor.h"
namespace jm
{
	class MyTank : public Actor
	{
	public:
		vec2 center = vec2(0.0f, 0.0f);
		//vec2 direction = vec2(1.0f, 0.0f, 0.0f);

		void moveUp(float dt) override
		{
			center.y += 0.5f*dt;
		}

		void moveDown(float dt) override
		{
			center.y -= 0.5f*dt;
		}

		void moveLeft(float dt) override
		{
			center.x += 0.5f*dt;
		}

		void moveRight(float dt) override
		{
			center.x -= 0.5f*dt;
		}

		void draw()
		{
			beginTransformation();
			{
				translate(center);
				drawFilledBox(Colors::green, 0.25f, 0.1f); // body
				translate(-0.02f, 0.1f);
				drawFilledBox(Colors::blue, 0.15f, 0.09f); // turret
				translate(0.15f, 0.0f);
				drawFilledBox(Colors::red, 0.15f, 0.03f);  // barrel
			}
			endTransformation();
		}
	};

	class MyBullet
	{
	public:
		vec2 center = vec2(0.0f, 0.0f);
		vec2 velocity = vec2(0.0f, 0.0f);


		void draw()
		{
			beginTransformation();
			translate(center);
			drawFilledRegularConvexPolygon(Colors::yellow, 0.02f, 8);
			drawWiredRegularConvexPolygon(Colors::gray, 0.02f, 8);
			endTransformation();
		}

		void update(const float& dt)
		{
			static const vec2 gravity = vec2(0.0f, -9.8f);
			velocity += gravity * dt;
			center += velocity * dt;
		}
	};

	class TankExample : public Game2D
	{
	public:
		MyTank tank;
		MyBullet *bullet = nullptr;

		std::vector<MyBullet*> bv;
		InputHandler input_handler;

		//TODO: allow multiple bullets
		//TODO: delete bullets when they go out of the screen

	public:
		TankExample()
			: Game2D("This is my digital canvas!", 1024, 768, false, 2)
		{}

		~TankExample()
		{
			//if (bullet != nullptr) delete bullet;
		}

		void update() override
		{

			
			// move tank
		//	if (isKeyPressed(GLFW_KEY_LEFT))	tank.center.x -= 0.5f * getTimeStep();
		//	if (isKeyPressed(GLFW_KEY_RIGHT))	tank.center.x += 0.5f * getTimeStep();
		//	if (isKeyPressed(GLFW_KEY_UP))		tank.moveUp(getTimeStep());
		//	if (isKeyPressed(GLFW_KEY_DOWN))	tank.center.y -= 0.5f * getTimeStep();

			input_handler.handlInput(*this, tank, getTimeStep());


			// shoot a cannon ball
			if (isKeyPressed(GLFW_KEY_SPACE))
			{
				bullet = new MyBullet;
				bullet->center = tank.center;
				bullet->center.x += 0.2f;
				bullet->center.y += 0.1f;
				bullet->velocity = vec2(4.0f, 0.0f);
				bv.push_back(bullet);
			}

			for (int i = 0; i < bv.size(); i++)
			{
				if (bv[i] != nullptr) bv[i]->update(getTimeStep());
			}

			// rendering
			tank.draw();


			for (int i = 0; i < bv.size(); i++)
			{
				if (bv[i] != nullptr) bv[i]->draw();
			}

			for (auto it = bv.begin(); it != bv.end(); it++) {
				MyBullet* temp = *it;
				if (temp->center.x > 0.5f)
				{
					if (temp != nullptr)
						delete temp;
					temp = nullptr;
					bv.erase(it);
					if (bv.size() == 0)
						break;
				}
			}



		}
	};
}