#pragma once
#include "GeometricObject.h"

namespace jm
{
	class Circle : public GeometricObject
	{
	public:
		float size;

		Circle(const RGB & _color, const vec2 & _pos, const float& _dgree, const float & _size)
		{
			init(_color, _pos, _dgree, _size);
		}

		void init(const RGB & _color, const vec2 & _pos, const float& _dgree, const float & _size)
		{
			GeometricObject::init(_color, _pos, _dgree);
			size = _size;
		}
		void drawGeometry () const override
		{
			drawFilledCircle(color, size);
		}
	};

}