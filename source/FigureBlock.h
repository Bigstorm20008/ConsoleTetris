#ifndef FIGURE_BLOCK_H
#define FIGURE_BLOCK_H

#include "Vector2D.h"
#include "RotationMatrix2D.h"

namespace figures
{

	class FigureBlock
	{
	public:
		friend class TetrisFigure;

		FigureBlock(const wchar_t& graficsPresent, const helpers::Vector2D& position);
		~FigureBlock();

		const wchar_t& getGraficPresent() const;
		const helpers::Vector2D& getPosition()const;

		void moveDown();
		void moveRight();
		void moveLeft();

		
	private:
		wchar_t m_graficPresent;
		helpers::Vector2D m_position;

		void setRotationTransfom(const helpers::RotationMatrix2D& rotationMatrix);

	};

}//namespace figures

#endif // !FIGURE_BLOCK_H



