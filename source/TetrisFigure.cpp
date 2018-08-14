#include "TetrisFigure.h"

namespace figures
{

	TetrisFigure::TetrisFigure(const helpers::Vector2D& pivotRotationPoint)
		: m_pivotRotationPoint{ pivotRotationPoint },
		  m_isOnGround{ false }
	{
	}


	TetrisFigure::~TetrisFigure()
	{
	}

	void TetrisFigure::addFigureBlock(const FigureBlock& figureBlock)
	{
		m_figureBlocks.push_back(figureBlock);
	}


	void TetrisFigure::update(const World& world)
	{
		for (const auto& block : m_figureBlocks)
		{
			const helpers::Vector2D blockPosition = block.getPosition();
			helpers::Vector2D nextPosition = blockPosition;
			float y = nextPosition.getY();
			++y;
			nextPosition.setY(y);

			if (world.isInWorld(nextPosition) == true){
				if (world.isFreePosition(nextPosition) == false){
					m_isOnGround = true;
				}
			}
			else{
				m_isOnGround = true;
			}
		}

		if (m_isOnGround == false){
			for (auto& block : m_figureBlocks){
				block.moveDown();
			}
			m_pivotRotationPoint.setY(m_pivotRotationPoint.getY() + 1);
		}
	}


	void TetrisFigure::draw(ConsoleRenderTarget& ñonsoleRenderTarget)
	{
		for (const auto& block : m_figureBlocks)
		{
			const wchar_t blockPresent = block.getGraficPresent();
			const helpers::Vector2D blockPosition = block.getPosition();
			ñonsoleRenderTarget.drawSymbol(blockPosition.getX(),
				                           blockPosition.getY(),
										   blockPresent);
		}
	}


	void TetrisFigure::moveRight(const World& world)
	{
		bool isCollide = false;

		for (const auto& block : m_figureBlocks)
		{
			const helpers::Vector2D blockPosition = block.getPosition();
			helpers::Vector2D nextPosition = blockPosition;
			float x = nextPosition.getX();
			++x;
			nextPosition.setX(x);

			if (world.isInWorld(nextPosition) == true){
				if (world.isFreePosition(nextPosition) == false){
					isCollide = true;
				}
			}
			else{
				isCollide = true;
			}
		}
		
		if (isCollide == false){
			for (auto& block : m_figureBlocks){
				block.moveRight();
			}
			m_pivotRotationPoint.setX(m_pivotRotationPoint.getX() + 1);
		}
	}


	void TetrisFigure::moveLeft(const World& world)
	{
		bool isCollide = false;

		for (const auto& block : m_figureBlocks)
		{
			const helpers::Vector2D blockPosition = block.getPosition();
			helpers::Vector2D nextPosition = blockPosition;
			float x = nextPosition.getX();
			--x;
			nextPosition.setX(x);

			if (world.isInWorld(nextPosition) == true){
				if (world.isFreePosition(nextPosition) == false){
					isCollide = true;
				}
			}
			else{
				isCollide = true;
			}
		}

		if (isCollide == false){
			for (auto& block : m_figureBlocks){
				block.moveLeft();
			}
			m_pivotRotationPoint.setX(m_pivotRotationPoint.getX() - 1);
		}
	}


	const bool TetrisFigure::isOnGround()const
	{
		return m_isOnGround;
	}


	const std::vector<FigureBlock>& TetrisFigure::getBlocks()const
	{
		return m_figureBlocks;
	}


	void TetrisFigure::rotate(const World& world)
	{
		helpers::RotationMatrix2D rotationMatrix{ 90, m_pivotRotationPoint };

		bool isCollide = false;

		for (auto block : m_figureBlocks){
			block.setRotationTransfom(rotationMatrix);
			auto& blockPosition = block.getPosition();
			if (world.isInWorld(blockPosition) == true){
				if (world.isFreePosition(blockPosition) == false){
					isCollide = true;
				}
			}
			else{
				isCollide = true;
			}
		}

		if (isCollide == false){
			for (auto& block : m_figureBlocks){
				block.setRotationTransfom(rotationMatrix);
			}
		}
	}


}//namespace figures
