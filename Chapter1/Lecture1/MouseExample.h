#pragma once
#include "Game2D.h"
namespace jm
{

	class MouseExample : public Game2D
	{
	public:
		void update() override
		{
			const vec2 mouse_pos = getCursorPos(true);

			if (this->isMouseButtonPressed(GLFW_MOUSE_BUTTON_1) == true)
			{
				translate(mouse_pos);
				drawFilledCircle(Colors::gold, 0.1f);
			}

			if (this->isMouseButtonPressed(GLFW_MOUSE_BUTTON_2) == true)
			{
				translate(mouse_pos);
				drawFilledCircle(Colors::red, 0.1f);
			}

		}
	};
}