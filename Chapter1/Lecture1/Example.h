#pragma once
#pragma once
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
