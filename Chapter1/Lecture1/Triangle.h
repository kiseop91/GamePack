#include "GeometricObject.h"

namespace jm
{
	class Triangle : public GeometricObject
	{
	public:
		float size;

		Triangle(const RGB & _color, const vec2 & _pos, const float & _dgree, const float & _size)
		{
			init(_color , _pos, _dgree , _size );
		}

		~Triangle()
		{
			std::cout << "Triangle destructor"<<std::endl;
		}

		void init(const RGB & _color, const vec2 & _pos,const float & _dgree,const float & _size)
		{
			GeometricObject::init(_color, _pos, _dgree);
			size = _size;
		}

		void drawGeometry() const override
		{
			drawFilledTriangle(color, size);
		}
	};

}