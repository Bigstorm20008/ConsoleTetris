#include "RotationMatrix2D.h"

namespace helpers
{

	RotationMatrix2D::RotationMatrix2D(const int& angleInDegrees,
		                               const Vector2D& centerOfRotation) :
									   m_centerOfRotation{ centerOfRotation }
	{
		const float cosOfAngle = helpers::computeCos(angleInDegrees);
		const float sinOfAngle = helpers::computeSin(angleInDegrees);

		m_M11 = cosOfAngle;
		m_M12 = sinOfAngle;
		m_M21 = -sinOfAngle;
		m_M22 = cosOfAngle;
		
	}


	RotationMatrix2D::~RotationMatrix2D()
	{
	}

	


	const Vector2D& operator*(Vector2D& vector, const RotationMatrix2D& rotationMatrix)
	{

		Vector2D tempVector;
		tempVector.setX(vector.getX() - rotationMatrix.m_centerOfRotation.getX());
		tempVector.setY(vector.getY() - rotationMatrix.m_centerOfRotation.getY());
		

		float x = rotationMatrix.m_M11 * tempVector.getX() +
			      rotationMatrix.m_M12 * tempVector.getY();

		float y = rotationMatrix.m_M21 * tempVector.getX() +
			      rotationMatrix.m_M22 * tempVector.getY();

		vector.setX(x + rotationMatrix.m_centerOfRotation.getX());
		vector.setY(y + rotationMatrix.m_centerOfRotation.getY());

		return vector;
	}

	const float computeCos(const int& angleInDegrees)
	{
		float cosOfAngle;

		switch ( abs(angleInDegrees) )
		{
		case 0:
		case 360:
			cosOfAngle = 1;
			break;

		case  90 :
			cosOfAngle = 0;
			break;

		case 180:
			cosOfAngle = -1;
			break;

		default:
			const float pi = 3.14159265f;
			float angleInRadian = angleInDegrees * pi / 180;
			cosOfAngle = cos(angleInRadian);
			break;
		}

		return cosOfAngle;
	}


	const float computeSin(const int& angleInDegrees)
	{
		float sinOfAngle;

		switch (abs(angleInDegrees))
		{
		case 0:
		case 360:
			sinOfAngle = 0;
			break;

		case 90:
			sinOfAngle = 1;
			break;

		case 180:
			sinOfAngle = 0;
			break;

		default:
			const float pi = 3.14159265f;
			float angleInRadian = angleInDegrees * pi / 180;
			sinOfAngle = sin(angleInRadian);
			break;
		}
        
		if (angleInDegrees < 0){
			sinOfAngle *= -1;
		}

		return sinOfAngle;
	}
}//namespace helpers
