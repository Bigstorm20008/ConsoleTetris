#ifndef TETRIS_FIGURE_H
#define TETRIS_FIGURE_H

#include <vector>

#include "ConsoleRenderTarget.h"
#include "FigureBlock.h"
#include "World.h"
#include "RotationMatrix2D.h"

namespace figures
{
	class TetrisFigure
	{
	public:
		TetrisFigure(const helpers::Vector2D& pivotRotationPoint);
		virtual ~TetrisFigure();

		void addFigureBlock(const FigureBlock& figureBlock);

		void rotate(const World& world);
		void moveRight(const World& world);
		void moveLeft(const World& world);
		const bool isOnGround()const;

		void update(const World& world);
		void draw(ConsoleRenderTarget& ñonsoleRenderTarget);

		const std::vector<FigureBlock>& getBlocks()const;
	private:
		helpers::Vector2D m_pivotRotationPoint;
		bool m_isOnGround;
		std::vector<FigureBlock> m_figureBlocks;
		
	};

}//namespace figures

#endif // !TETRIS_FIGURE_H



