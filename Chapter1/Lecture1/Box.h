#pragma once
#include "GeometricObject.h"

namespace jm
{
	class Box : public GeometricObject
	{
	public:
		float width, height;

		Box(const RGB & _color, const vec2 & _pos, const float & _width, const float & _dgree, const float & _height)
		{
			init(_color, _pos, _width, _dgree, _height);
		}
		void init(const RGB & _color, const vec2 & _pos, const float & _width, const float & _dgree,const float & _height)
		{
			GeometricObject::init(_color, _pos, _dgree);
			height = _height;
			width = _width;
		}
		void drawGeometry() const override
		{
			drawFilledBox(color, this->width, this->height);
		}
	};

}