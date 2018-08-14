#include "World.h"


World::World(const helpers::Rect& worldRect)
	: m_worldRect{ worldRect }
{

	const unsigned int worldWidth = m_worldRect.right - m_worldRect.left;
	const unsigned int worldHeight = m_worldRect.bottom - m_worldRect.top;
	const unsigned int maxBlocksInWorld = worldWidth * worldHeight;

	m_blocksInWorld.reserve(maxBlocksInWorld);
}


World::~World()
{
	m_blocksInWorld.clear();
}



const bool World::addBlock(figures::FigureBlock& figureBlock)
{
	m_blocksInWorld.push_back(figureBlock);
	return true;
}




const bool World::isFreePosition(const helpers::Vector2D& position) const
{
	bool isFreePosition = true;

	auto founded = std::find_if(m_blocksInWorld.cbegin(),
			                    m_blocksInWorld.cend(),
			                    [&](const figures::FigureBlock figureBlock){
			                    return figureBlock.getPosition() == position; });

	if (founded != m_blocksInWorld.cend()){
		isFreePosition = false;
	}
		
	return isFreePosition;
}

void World::update()
{
 	std::vector<int> linesToDelete = findLinesToDelete();

	if (linesToDelete.empty() == false){
		deleteLines(linesToDelete);
	}
}


void World::draw(ConsoleRenderTarget& consoleRenderTarget)
{
	for (const auto& block : m_blocksInWorld)
	{
		const auto& blockPresent = block.getGraficPresent();
		const auto& blockPosition = block.getPosition();
		consoleRenderTarget.drawSymbol(blockPosition.getX(), blockPosition.getY(), blockPresent);
	}
}


const bool World::isInWorld(const helpers::Vector2D& position)const
{
	const bool isInWorld = position.getX() >= m_worldRect.left &&
		                   position.getX() <= m_worldRect.right &&
		                   position.getY() >= m_worldRect.top &&
		                   position.getY() <= m_worldRect.bottom;

	return isInWorld;
}


void World::processInput(const Key& key)
{
	
}


const bool World::isWorldLineFull(const unsigned int& numberOfLine)const
{
	bool isFull = true;

	helpers::Vector2D currentPosition;
	currentPosition.setY(numberOfLine);

	for (int positionInLine = 0; positionInLine < m_worldRect.right + 1; ++positionInLine){		
		currentPosition.setX(positionInLine);
		if (isFreePosition(currentPosition) == true){
			isFull = false;
			break;
		}
	}

	return isFull;
}


std::vector<int> World::findLinesToDelete() const
{
	std::vector<int> linesToDelete{};

	const unsigned int linesInWorld = (m_worldRect.bottom - m_worldRect.top) + 1;
	linesToDelete.reserve(linesInWorld);

	for (int line = 0; line < linesInWorld; ++line){
		if (isWorldLineFull(line) == true){
			linesToDelete.push_back(line);
		}
	}

	return linesToDelete;
}


void World::deleteLines(const std::vector<int>& linesToDelete)
{
	for (auto line : linesToDelete){

		helpers::Vector2D position;
		position.setY(line);

		for (int posInLine = 0; posInLine < m_worldRect.right + 1; ++posInLine){

			position.setX(posInLine);

			auto& founded = std::find_if(m_blocksInWorld.begin(),
				                        m_blocksInWorld.end(),
				                         [&](figures::FigureBlock figureBlock){
				                        return figureBlock.getPosition() == position; });
			if (founded != m_blocksInWorld.cend()){
				m_blocksInWorld.erase(founded);
			}
		}
		correctWorldUpperDeletedLine(line);
	}
}


void World::correctWorldUpperDeletedLine(const unsigned int& numberOfDeletedLine)
{
	unsigned int lineToCorrect = (numberOfDeletedLine - 1);

	for (lineToCorrect; lineToCorrect > m_worldRect.top; --lineToCorrect){

		helpers::Vector2D position;
		position.setY(lineToCorrect);

		for (int posInLine = 0; posInLine <= m_worldRect.right+1; ++posInLine){

			position.setX(posInLine);

			auto& founded = std::find_if(m_blocksInWorld.begin(),
				                         m_blocksInWorld.end(),
				                         [&](figures::FigureBlock figureBlock){
				                         return figureBlock.getPosition() == position; });

			if (founded != m_blocksInWorld.cend()){
				founded->moveDown();
			}

		}
	}
}


const helpers::Rect& World::getRect()const
{
	return m_worldRect;
}