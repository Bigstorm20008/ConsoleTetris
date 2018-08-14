#ifndef TETRIS_LEVEL_INFO_H
#define TETRIS_LEVEL_INFO_H

#include "Rect.h"
#include "ConsoleRenderTarget.h"
#include "TetrisFigure.h"

class TetrisLevelInfo
{
public:
	TetrisLevelInfo(const helpers::Rect& levelInfoRect);
	~TetrisLevelInfo();

	void drawNextFigure(const figures::TetrisFigure& tetrisFigure,	               
		                ConsoleRenderTarget& consoleRenderTarget);

	const helpers::Rect& getRect() const;
private:
	helpers::Rect m_levelInfoRect;
};

#endif // !TETRIS_LEVEL_INFO_H



