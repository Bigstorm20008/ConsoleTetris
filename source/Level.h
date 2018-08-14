#ifndef LEVEL_H
#define LEVEL_H

#include <chrono>

#include "ConsoleRenderTarget.h"
#include "Keys.h"
#include "World.h"
#include "TetrisFigureFactory.h"
#include "TetrisLevelInfo.h"

class Level 
{
public:
	Level();
	virtual ~Level();

	void initialize(ConsoleRenderTarget& ñonsoleRenderTarget);
	void processInput(const Key& key);
	void pause();
	void resume();

	void update(ConsoleRenderTarget& ñonsoleRenderTarget);

protected:

	enum class LevelState{
		RUNNING,
		PLAYER_LOSE,
		UNKNOWN
	};

	LevelState m_levelState;
	World* m_world;

	std::chrono::milliseconds m_worldUpdateSpeed;
	std::chrono::high_resolution_clock::time_point m_currentTimePoint;
	std::chrono::high_resolution_clock::time_point m_previousWorldUpdate;

	std::unique_ptr<figures::TetrisFigure> m_currentFigure;
	std::unique_ptr<figures::TetrisFigure> m_nextFigure;

	TetrisFigureFactory m_tetrisFigureFactory;
	TetrisLevelInfo* m_tetrisLevelInfo;

	void doLevelLogic(ConsoleRenderTarget& ñonsoleRenderTarget);
	void draw(ConsoleRenderTarget& ñonsoleRenderTarget);
	
	const bool isCollide(const figures::TetrisFigure& tetrisFigure)const;
};


#endif // !LEVEL_H


