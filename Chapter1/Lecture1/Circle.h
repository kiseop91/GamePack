#pragma once
#include "GeometricObject.h"

namespace jm
{
	class Circle : public GeometricObject
	{
	public:

		void drawGeometry ()
		{
			drawFilledCircle(color, size);
		}
	};

}