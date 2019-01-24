#pragma once
#include "Game2D.h"


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
