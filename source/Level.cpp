#include "Level.h"


Level::Level() : m_levelState{ LevelState::UNKNOWN },
                 m_world{},
				 m_worldUpdateSpeed{ 85 },
				 m_currentTimePoint{ std::chrono::high_resolution_clock::now() },
				 m_previousWorldUpdate{ std::chrono::high_resolution_clock::now() },
				 m_currentFigure{},
				 m_nextFigure{},
				 m_tetrisLevelInfo{}
	             
{
}


Level::~Level()
{
	if (m_world != nullptr){
		delete m_world;
		m_world = nullptr;
	}
	if (m_tetrisLevelInfo != nullptr){
		delete m_tetrisLevelInfo;
		m_tetrisLevelInfo = nullptr;
	}
}


void Level::initialize(ConsoleRenderTarget& ñonsoleRenderTarget)
{
	ñonsoleRenderTarget.clear();

	helpers::Rect worldRect;
	worldRect.bottom = ñonsoleRenderTarget.getHeight();
	worldRect.top = 0;
	worldRect.left = 0;
	worldRect.right = 14;

	m_world = new World(worldRect);

	helpers::Rect levelInfoRect;
	levelInfoRect.bottom = ñonsoleRenderTarget.getHeight()-1;
	levelInfoRect.top = 1;
	levelInfoRect.left = worldRect.right + 2;
	levelInfoRect.right = ñonsoleRenderTarget.getWidth() -1;

	m_tetrisLevelInfo = new TetrisLevelInfo{ levelInfoRect };

	m_currentFigure = std::move(m_tetrisFigureFactory.createRandomFigure(helpers::Vector2D{ 7, 0 }));
	m_nextFigure = std::move(m_tetrisFigureFactory.createRandomFigure(helpers::Vector2D{ 7, 0 }));

	m_levelState = LevelState::RUNNING;
	
}


void Level::processInput(const Key& key)
{
	switch (key)
	{
		case Key::ARROW_LEFT :
			if (m_currentFigure->isOnGround() == false)
			    m_currentFigure->moveLeft(*m_world);
			break;

		case Key::ARROW_RIGHT :
			if (m_currentFigure->isOnGround() == false)
				m_currentFigure->moveRight(*m_world);
			break;

		case Key::ARROW_DOWN :
			m_previousWorldUpdate -= m_worldUpdateSpeed;
			break;

		case Key::SPACE :
			if (m_currentFigure->isOnGround() == false)
				m_currentFigure->rotate(*m_world);
			break;

		default :
			break;
	}
}

void Level::update(ConsoleRenderTarget& ñonsoleRenderTarget)
{

	ñonsoleRenderTarget.clear();

	switch (m_levelState)
	{
		case Level::LevelState::RUNNING:
		{
			doLevelLogic(ñonsoleRenderTarget);
			break;
		}

		case Level::LevelState::PLAYER_LOSE:
		{
			std::wstring loseText{ L"You lose!!! May be next time." };

			helpers::Vector2D textPosition;
			textPosition.setX(0);
			textPosition.setY(0);

			ñonsoleRenderTarget.drawText(textPosition, loseText);

			std::wstring infoText{ L"For exit press Q" };
			textPosition.setY(1);
			ñonsoleRenderTarget.drawText(textPosition, infoText);
			break;
		}

		case Level::LevelState::UNKNOWN:
			break;

		default:
			break;
	}

}


void Level::draw(ConsoleRenderTarget& ñonsoleRenderTarget)
{
	const helpers::Rect& worldRect = m_world->getRect();

	helpers::Rect boundaryRect = worldRect;
	++boundaryRect.bottom;
	--boundaryRect.left;
	++boundaryRect.right;
	--boundaryRect.top;

	ñonsoleRenderTarget.drawRect(boundaryRect);

	const helpers::Rect& levelInfoRect = m_tetrisLevelInfo->getRect();

	boundaryRect = levelInfoRect;
	++boundaryRect.bottom;
	--boundaryRect.left;
	++boundaryRect.right;
	--boundaryRect.top;

	ñonsoleRenderTarget.drawRect(boundaryRect);

	m_currentFigure->draw(ñonsoleRenderTarget);
	m_world->draw(ñonsoleRenderTarget);
	m_tetrisLevelInfo->drawNextFigure(*m_nextFigure.get(), ñonsoleRenderTarget);
}

const bool Level::isCollide(const figures::TetrisFigure& tetrisFigure)const
{
	bool isCollide = false;

	const auto& blocks = tetrisFigure.getBlocks();

	for (const auto& block : blocks){
		if (m_world->isFreePosition(block.getPosition()) == false){
			isCollide = true;
			break;
		}
	}

	return isCollide;
}

void Level::doLevelLogic(ConsoleRenderTarget& ñonsoleRenderTarget)
{
	m_currentTimePoint = std::chrono::high_resolution_clock::now();
	bool isReadyToUpdate = std::chrono::duration_cast<std::chrono::milliseconds>(m_currentTimePoint -
		                                                                         m_previousWorldUpdate) >= m_worldUpdateSpeed;

	if (isReadyToUpdate == true){
		if (m_currentFigure->isOnGround() == false){
			m_currentFigure->update(*m_world);
		}
		else{
			auto blocksInFigure = m_currentFigure->getBlocks();
			for (auto& block : blocksInFigure){
				m_world->addBlock(block);
			}

			m_currentFigure.reset();
			m_currentFigure = std::move(m_nextFigure);

			if (isCollide(*m_currentFigure.get()) == true){
				m_levelState = LevelState::PLAYER_LOSE;
			}

			m_nextFigure = std::move(m_tetrisFigureFactory.createRandomFigure(helpers::Vector2D{ 7, 0 }));
		}

		m_world->update();
		m_previousWorldUpdate = m_currentTimePoint;
	}

	this->draw(ñonsoleRenderTarget);
}

