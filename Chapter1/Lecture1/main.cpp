#include "Game2D.h"
#include "PrimitivesGallery.h"
#include "TankExample.h"
#include "FaceExample.h"
#include "WalkingPerson.h"
#include "SolarSystem.h"
#include "kiseop.h"

namespace jm
{
	class RotatingStarExample : public Game2D
	{
		float time = 0.0f;
	public:

		void update() override
		{
			setLineWidth(3.0f);

			rotate(time *90.0f);
			translate(.5f, .0f);
			rotate(time *90.0f);
			scale(2.0f, .25f);
			drawWiredBox(Colors::gold, .5f, .5f);

			time += this->getTimeStep();
		}
	};
}

int main(void)
{
	//jm::SolarSystem().run();
	jm::MouseExample().init("This is my digital canvas!", 1000, 1000, false).run();
	//jm::Game2D().init("This is my digital canvas!", 1280, 960, false).run();
	//jm::RotatingStarExample().init("Roatating Star Example", 1000, 1000, false).run();
	//jm::PrimitivesGallery().init("Primitive Gallery", 1280, 960, false).run();
	//jm::FaceExample().run();
	//jm::WalkingPerson().run();
	//jm::TankExample().run();
	
	//jm::kiseop().run();

	return 0;
}
