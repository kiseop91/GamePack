#include "Game2D.h"
#include "PrimitivesGallery.h"
#include "TankExample.h"
#include "FaceExample.h"
#include "WalkingPerson.h"
#include "SolarSystem.h"
#include "kiseop.h"
#include "Triangle.h"
#include "Circle.h"
#include "Box.h"
namespace jm
{
	class Example : public Game2D
	{
	public:
		Triangle my_tri;
		Circle my_cir;
		Box my_box;
		float time;

		Example()
			:Game2D()
		{
			my_tri.init(Colors::gold, vec2{ -0.5f, 0.2f }, 0.25f);
			my_cir.init(Colors::red, vec2{ 0.1f, 0.1f }, 0.2f);
			my_box.init(Colors::black, vec2{ 0.1f, 0.5f }, 0.3f, 0.3f);
		}
		void update() override
		{
			my_tri.draw();
			my_cir.draw();
			my_box.draw();	
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
	//jm::TankExample().run();
	jm::Example().run();
	//jm::kiseop().run();

	return 0;
}
