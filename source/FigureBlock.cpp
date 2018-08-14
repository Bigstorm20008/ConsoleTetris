#include "FigureBlock.h"


namespace figures
{

	FigureBlock::FigureBlock(const wchar_t& graficsPresent,
		                     const helpers::Vector2D& position) :
							 m_graficPresent{ graficsPresent },
							 m_position{ position }
	{
	}


	FigureBlock::~FigureBlock()
	{
	}


	const wchar_t& FigureBlock::getGraficPresent() const
	{
		return m_graficPresent;
	}


	const helpers::Vector2D& FigureBlock::getPosition()const
	{
		return m_position;
	}

	void FigureBlock::moveDown()
	{
		float y = m_position.getY();
		++y;
		m_position.setY(y);
	}


	void FigureBlock::moveRight()
	{
		float x = m_position.getX();
		++x;
		m_position.setX(x);
	}


	void FigureBlock::moveLeft()
	{
		float x = m_position.getX();
		--x;
		m_position.setX(x);
	}


	void FigureBlock::setRotationTransfom(const helpers::RotationMatrix2D& rotationMatrix)
	{
		m_position = m_position * rotationMatrix;
	}

}//namespace figures