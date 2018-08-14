#ifndef ROTATION_MATRIX_2D_H
#define ROTATION_MATRIX_2D_H


#include <cmath>
#include "Vector2D.h"


namespace helpers
{
	class RotationMatrix2D
	{
	public:
		RotationMatrix2D(const int& angleInDegrees,
			             const Vector2D& centerOfRotation);

		~RotationMatrix2D();
		
		friend const Vector2D& operator*(Vector2D& vector, const RotationMatrix2D& rotationMatrix);
	private:
		float m_M11;
		float m_M12;
		float m_M21;
		float m_M22;
		const Vector2D m_centerOfRotation;
	};



	const Vector2D& operator*(Vector2D& vector, const RotationMatrix2D& rotationMatrix);
	const float computeCos(const int& angleInDegrees);
	const float computeSin(const int& angleInDegrees);
	

}//namespace helpers

#endif // !ROTATION_MATRIX_2D_H



