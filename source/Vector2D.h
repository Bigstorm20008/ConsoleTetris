#ifndef VECTOR_2D_H
#define VECTOR_2D_H

#include <iostream>



namespace helpers
{


	class Vector2D
	{
	public:
		Vector2D();
		explicit Vector2D(const float& x, const float& y);
		~Vector2D();

		const float& getX()const;
		const float& getY()const;
		void setX(const float& x);
		void setY(const float& y);

		const bool operator==(const Vector2D& rightVector)const;
		const Vector2D& operator+(const Vector2D& rightVector)const;
	private:
		float m_x;
		float m_y;
	};

	
	
}//namespace helpers

#endif // !VECTOR_2D_H



