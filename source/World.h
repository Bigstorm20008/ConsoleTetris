#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory>
#include <algorithm>
#include "Rect.h"
#include "ConsoleRenderTarget.h"
#include "Keys.h"
#include "FigureBlock.h"



class World 
{
public:
	World(const helpers::Rect& worldRect);
	~World();

	const bool addBlock(figures::FigureBlock& figureBlock);
	
	
	const bool World::isFreePosition(const helpers::Vector2D& position) const;

	void update();
	void draw(ConsoleRenderTarget& consoleRenderTarget);

	const bool isInWorld(const helpers::Vector2D& position)const;

	void processInput(const Key& key);

	const helpers::Rect& getRect()const;
private:
	helpers::Rect m_worldRect;
	
	std::vector<figures::FigureBlock> m_blocksInWorld;
	
	const bool isWorldLineFull(const unsigned int& numberOfLine)const;
	std::vector<int> findLinesToDelete() const;
	void deleteLines(const std::vector<int>& linesToDelete);
	void correctWorldUpperDeletedLine(const unsigned int& numberOfDeletedLine);
};

#endif // !WORLD_H



