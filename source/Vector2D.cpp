#include "Vector2D.h"

namespace helpers
{

	Vector2D::Vector2D() : m_x{ 0 }, m_y{ 0 }
	{
	}

	Vector2D::Vector2D(const float& x, const float& y) : m_x{ x }, m_y{ y }
	{

	}


	Vector2D::~Vector2D()
	{
	}


	const float& Vector2D::getX()const
	{
		return m_x;
	}


	const float& Vector2D::getY()const
	{
		return m_y;
	}


	void Vector2D::setX(const float& x)
	{
		m_x = x;
	}


	void Vector2D::setY(const float& y)
	{
		m_y = y;
	}

	
	const bool Vector2D::operator==(const Vector2D& rightVector)const
	{
		return{ this->m_x == rightVector.m_x && this->m_y == rightVector.m_y };
	}
	

	const Vector2D& Vector2D::operator+(const Vector2D& rightVector)const
	{
		return Vector2D{ this->m_x + rightVector.m_x, this->m_y + rightVector.m_y };
	}


	
}//namespace helpers