#include "GeometricObject.h"
#include <memory>

#include "Triangle.h"
#include "Circle.h"
#include "Box.h"

namespace jm
{
//
//	std::shared_ptr<GeometricObject> test(const RGB & _color, const vec2 & _pos, const float & _dgree, const float & _size)
//	{
//		//	return Triangle();
//		return std::shared_ptr<GeometricObject>(_color, _pos, _dgree, _size);
//	}

	GeometricObject * GeometricObject::makeTriangle(const RGB & _color, const vec2 & _pos, const float & _dgree, const float & _size)
	{
		return new Triangle(_color, _pos, _dgree, _size);
	}

	GeometricObject * GeometricObject::makeCircle(const RGB & _color, const vec2 & _pos, const float& _dgree, const float & _size)
	{
		return new Circle(_color, _pos, _dgree, _size);
	}

	GeometricObject * GeometricObject::makeBox(const RGB & _color, const vec2 & _pos, const float & _width, const float & _dgree, const float & _height)
	{
		return new Box(_color, _pos, _width, _dgree, _height);
	}

}