#include "TetrisLevelInfo.h"


TetrisLevelInfo::TetrisLevelInfo(const helpers::Rect& levelInfoRect)
	: m_levelInfoRect{ levelInfoRect }
{
}


TetrisLevelInfo::~TetrisLevelInfo()
{
}


void TetrisLevelInfo::drawNextFigure(const figures::TetrisFigure& tetrisFigure,
	                                 ConsoleRenderTarget& consoleRenderTarget)
{
	const auto& blocks = tetrisFigure.getBlocks();

	for (const auto& block : blocks){
		const auto& blockGraficPresent = block.getGraficPresent();
		const auto& blockPosition = block.getPosition();
		consoleRenderTarget.drawSymbol(m_levelInfoRect.left + blockPosition.getX(),
			                           m_levelInfoRect.top + blockPosition.getY(),
			                           blockGraficPresent);
	}
}


const helpers::Rect& TetrisLevelInfo::getRect() const
{
	return m_levelInfoRect;
}
