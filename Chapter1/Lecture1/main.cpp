#include "Game2D.h"
#include "PrimitivesGallery.h"
#include "TankExample.h"
#include "FaceExample.h"
#include "WalkingPerson.h"
#include "SolarSystem.h"
#include "kiseop.h"
#include <memory>

//#include "Triangle.h"
//#include "Circle.h"
//#include "Box.h"
#include  "Example.h"

#include "imgui/imgui.h"
#include "imgui/imconfig.h"
#include "imgui/imgui_internal.h"
#include "imgui/imstb_truetype.h"
#include "imgui/imstb_rectpack.h"
#include "imgui/imstb_textedit.h"

namespace jm
{
	class RigidCircle
	{
	public:
		vec2 pos;
		vec2 vel;
		float radius = 0.1f;
		float mass = 1.0f;

		void draw()
		{
			beginTransformation();
			{
				translate(pos);
				drawFilledCircle(Colors::gold, radius - 1e-3);
				setLineWidth(2.0f);
				drawWiredCircle(Colors::black, radius);
			}
			endTransformation();
		}
		void update(const float & dt)
		{
			static const vec2 gravity = vec2(0.0f, -9.8f);
			static const float coef_res = 0.7f;
			static const float coef_friction = 0.98f;


			vel += gravity * dt;
			pos += vel * dt;

			if (1.0f - pos.x <= radius)  // right wall
			{
				pos.x = 1.0f - radius;

				if (vel.x >= 0.0f)
					vel.x *= -1.0f * coef_res;
			}

			if (pos.y <= -1.0f + radius)  // bottom wall
			{
				pos.y = -1.0f + radius;

				if (vel.y <= 0.0f)
					vel.y *= -1.0f * coef_res;

				vel.x *= coef_friction;
			}

			if (pos.x <= -1.0f + radius)  // left wall
			{
				pos.x= - 1.0f + radius;

				if (vel.x <= 0.0f)
					vel.x *= -1.0f *coef_res;


			}

		}
	};

	class Example2D : public Game2D
	{
	public:
		RigidCircle rigid_body;
		RigidCircle rigid_body2;

		Example2D()
			:Game2D()
		{
			reset();
		}
		void reset()
		{
			rigid_body.pos = vec2(-0.8f, 0.3f);
			rigid_body.vel = vec2(10.0f, 0.0f);
			rigid_body.radius = 0.1f;
			rigid_body.mass = 1.0f;
			

			rigid_body2.pos = vec2(0.8f, 0.3f);
			rigid_body2.vel = vec2(-10.0f, 0.0f);
			rigid_body2.radius = 0.15f;
			rigid_body2.mass = rigid_body.mass * std::pow(rigid_body2.radius / rigid_body.radius, 2.0f);
		}

		void drawWall()
		{
			setLineWidth(5.0f);
			drawLine(Colors::black, { -1.0f, -1.0f }, Colors::black, { 1.0f, -1.0f });
			drawLine(Colors::black, { 1.0f, -1.0f }, Colors::black, { 1.0f, 1.0f });
			drawLine(Colors::black, { -1.0f, -1.0f }, Colors::black, { -1.0f, 1.0f });
		}

		void update() override
		{
			const float epsilon = 0.4;
			const float dt = getTimeStep() * 0.5f;
			rigid_body.update(dt);
			rigid_body2.update(dt);

			const float distance = (rigid_body.pos - rigid_body2.pos).getMagnitude();

			if (distance <= rigid_body.radius + rigid_body2.radius)
			{
				// compute impulse
				const auto vel_rel = rigid_body.vel - rigid_body2.vel;
				const auto normal = -(rigid_body2.pos - rigid_body.pos) /
					(rigid_body2.pos - rigid_body.pos).getMagnitude();

				if (vel_rel.getDotProduct(normal) < 0.0f)
				{
					const auto impulse = normal * -(1.0f + epsilon) * vel_rel.getDotProduct(normal) /
						((1.0f / rigid_body.mass) + (1.0f / rigid_body2.mass));

					rigid_body.vel += impulse / rigid_body.mass;
					rigid_body2.vel -= impulse / rigid_body2.mass;
				}

				//update velocities of two bodies
			}

			drawWall();
			rigid_body.draw();
			rigid_body2.draw();

			if (isKeyPressedAndReleased(GLFW_KEY_R)) reset();
		}

	};
}



int main(void)
{
	//jm::SolarSystem().run();
	//jm::MouseExample().init("This is my digital canvas!", 1000, 1000, false).run();
	//jm::Game2D().init("This is my digital canvas!", 1280, 960, false).run();
	//jm::RotatingStarExample().init("Roatating Star Example", 1000, 1000, false).run();
	//jm::PrimitivesGallery().init("Primitive Gallery", 1280, 960, false).run();
	//jm::FaceExample().run();
	//jm::WalkingPerson().run();
	jm::TankExample().run();
	//jm::Example().run();
	//jm::kiseop().run();

	//jm::Example2D().run();

	return 0;
}
