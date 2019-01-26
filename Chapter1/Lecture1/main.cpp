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
#include "GeometricObject.h"
namespace jm
{
	class Example : public Game2D
	{
	public:

		float time = 0.0f;
			std::vector<GeometricObject*> my_objs;
	    // 	std::vector<std::shared_ptr<GeometricObject>> my_objs;
		Example()
			:Game2D()
		{
			my_objs.push_back(GeometricObject::makeTriangle(Colors::gold, vec2{ -0.5f, 0.2f }, 10.0f, 0.25f));
			my_objs.push_back(GeometricObject::makeCircle(Colors::red, vec2{ 0.1f, 0.1f }, 5.0f, 0.2f));
			my_objs.push_back(GeometricObject::makeBox(Colors::black, vec2{ 0.1f, 0.5f }, 0.3f, 60.0f, 0.3f));
			//my_objs.push_back(std::make_shared<Triangle>(Colors::gold, vec2{ -0.5f, 0.2f }, 10.0f, 0.25f));
			//my_objs.push_back(std::make_shared<Circle>(Colors::red, vec2{ 0.1f, 0.1f }, 5.0f, 0.2f));
			//my_objs.push_back(std::make_shared<Box>(Colors::black, vec2{ 0.1f, 0.5f }, 0.3f, 60.0f, 0.3f));
		}

		~Example()
		{
		}
		void update() override
		{
			for (const auto& obj : my_objs)
				obj->draw(time * 90.0f);

			time += this->getTimeStep();
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
