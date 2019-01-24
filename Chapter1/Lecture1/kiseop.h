#pragma once
#include "Game2D.h"

namespace jm
{
	class kiseop : public Game2D
	{
		float time = 0.0f;

	public:
		void update() override
		{
			beginTransformation();
			{
				drawFilledCircle(Colors::red, 0.5f);
				translate( -0.3f, 0.3f);
				drawFilledCircle(Colors::black, 0.05f);

				translate(0.3f, -0.3f);
				drawFilledCircle(Colors::black, 0.05f);
				
			}
			endTransformation();
			translate(0.3f, 0.3f);
			drawFilledCircle(Colors::black, 0.05f);

			time += this->getTimeStep();

		}
	};
}