#pragma once
#include "Game2D.h"
namespace jm
{
	class GeometricObject
	{
	public:
		vec2 pos;
		RGB color;
		float dgree;

		void init(const RGB & _color, const vec2 & _pos , const float & _dgree)
		{
			color = _color;
			pos = _pos;
			dgree = _dgree;
		}

		virtual void drawGeometry() const = 0;

		void draw(float dgree)
		{
			beginTransformation();
			{
				translate(pos);
				rotate(dgree);
				drawGeometry();
			}
			endTransformation();
		}
		
		static GeometricObject * makeTriangle(const RGB & _color, const vec2 & _pos, const float & _dgree, const float & _size);

		static GeometricObject * makeCircle(const RGB & _color, const vec2 & _pos, const float & _dgree, const float & _size);

		static GeometricObject * makeBox(const RGB & _color, const vec2 & _pos, const float & _width, const float & _dgree, const float & _height);

		//	GeometricObject* makeTriangle(const RGB & _color, const vec2 & _pos, const float & _dgree, const float & _size);
	//	GeometricObject* makeCircle(const RGB & _color, const vec2 & _pos, const float& _dgree, const float & _size);
	//	GeometricObject* makeBox(const RGB & _color, const vec2 & _pos, const float & _width, const float & _dgree, const float & _height);
	};

}