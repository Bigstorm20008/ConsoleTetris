#ifndef TETRIS_FIGURE_FACTORY_H
#define TETRIS_FIGURE_FACTORY_H

#include <memory>

#include "TetrisFigure.h"
#include "RandomEngine.h"


enum class TetrisFigureId;

class TetrisFigureFactory
{
public:
	TetrisFigureFactory();
	~TetrisFigureFactory();

	std::unique_ptr<figures::TetrisFigure> createFigureById(const TetrisFigureId& tetrisFigureId,
		                                                    const helpers::Vector2D& topCenterOfWorld);

	std::unique_ptr<figures::TetrisFigure> createRandomFigure(const helpers::Vector2D& topCenterOfWorld);

private:
	std::unique_ptr<figures::TetrisFigure> createCross();
	figures::FigureBlock getNextBlock(const helpers::Vector2D& pivotFigurePoint,
		                              const helpers::Vector2D& offsetDirection);
	
};


enum class TetrisFigureId{

	CROSS_FIGURE,
	LINE_FIGURE,
	SQUARE_FIGURE,
	L_FIGURE,
	T_FIGURE,
	S_FIGURE,

	TETRIS_FIGURE_ID_SIZE //count of elements in enum, not use for create

};

#endif // !TETRIS_FIGURE_FACTORY_H



