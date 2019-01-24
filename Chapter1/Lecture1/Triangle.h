#include "GeometricObject.h"

namespace jm
{
	class Triangle : public GeometricObject
	{
	public:
		void drawGeometry()
		{
			drawFilledTriangle(color, size);
		}
	};

}