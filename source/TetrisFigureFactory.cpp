#include "TetrisFigureFactory.h"


TetrisFigureFactory::TetrisFigureFactory()
{
}


TetrisFigureFactory::~TetrisFigureFactory()
{
}


std::unique_ptr<figures::TetrisFigure> 
TetrisFigureFactory::createFigureById(const TetrisFigureId& tetrisFigureId,
                                      const helpers::Vector2D& topCenterOfWorld)
{
	std::unique_ptr<figures::TetrisFigure> figure{};
	switch (tetrisFigureId)
	{
		case TetrisFigureId::CROSS_FIGURE:
		{
			const helpers::Vector2D pivotRotationPoint{ topCenterOfWorld.getX(),
				                                        topCenterOfWorld.getY() + 1 };

			figure.reset(new figures::TetrisFigure{ pivotRotationPoint });
			figure->addFigureBlock(figures::FigureBlock{ { 'X' }, pivotRotationPoint });


			helpers::Vector2D direction{ 0, -1 }; //direction up, offset 1  
			figure->addFigureBlock(getNextBlock(pivotRotationPoint,direction));

			direction.setY(1); //change direction to down, offset 1
			figure->addFigureBlock(getNextBlock(pivotRotationPoint, direction));

			direction.setX(1); //change direction to right, offset 1
			direction.setY(0);
			figure->addFigureBlock(getNextBlock(pivotRotationPoint, direction));
			     
			direction.setX(-1); //change direction to right, offset 1
			figure->addFigureBlock(getNextBlock(pivotRotationPoint, direction));

			break;
		}

		case TetrisFigureId::LINE_FIGURE:
		{
			const helpers::Vector2D pivotRotationPoint{ topCenterOfWorld.getX(),
				                                        topCenterOfWorld.getY() + 2 };

			figure.reset(new figures::TetrisFigure{ pivotRotationPoint });
			figure->addFigureBlock(figures::FigureBlock{ { 'X' }, pivotRotationPoint });


			helpers::Vector2D direction{ 0, -1 }; //direction up, offset 1  
			figure->addFigureBlock(getNextBlock(pivotRotationPoint, direction));

			direction.setY(-2); //change offset 2
			figure->addFigureBlock(getNextBlock(pivotRotationPoint, direction));

			direction.setY(1); //change direction down, offset 1
			figure->addFigureBlock(getNextBlock(pivotRotationPoint, direction));
		       
			break;
		}

		case TetrisFigureId::L_FIGURE:
		{

			const helpers::Vector2D pivotRotationPoint{ topCenterOfWorld.getX(),
				                                        topCenterOfWorld.getY() };

			figure.reset(new figures::TetrisFigure{ pivotRotationPoint });
			figure->addFigureBlock(figures::FigureBlock{ { 'X' }, pivotRotationPoint });


			helpers::Vector2D direction{ 0, 1 }; //direction down, offset 1  
			figure->addFigureBlock(getNextBlock(pivotRotationPoint, direction));

			direction.setY(2); //direction down, offset 2 
			figure->addFigureBlock(getNextBlock(pivotRotationPoint, direction));

			direction.setY(2);
			direction.setX(1); //change direction to right, offset 1
			figure->addFigureBlock(getNextBlock(pivotRotationPoint, direction));

			break;
		}

		case TetrisFigureId::SQUARE_FIGURE:
		{

			const helpers::Vector2D pivotRotationPoint{ topCenterOfWorld.getX(),
				                                        topCenterOfWorld.getY() + 1 };

			figure.reset(new figures::TetrisFigure{ pivotRotationPoint });
			figure->addFigureBlock(figures::FigureBlock{ { 'X' }, pivotRotationPoint });


			helpers::Vector2D direction{ 0, -1 }; //direction up, offset 1  
			figure->addFigureBlock(getNextBlock(pivotRotationPoint, direction));

			direction.setY(0); //change direction to right, offset 1
			direction.setX(1);
			figure->addFigureBlock(getNextBlock(pivotRotationPoint, direction));

			direction.setX(1); //change direction to up, offset 1
			direction.setY(-1);
			figure->addFigureBlock(getNextBlock(pivotRotationPoint, direction));

			break;
		}

		case TetrisFigureId::S_FIGURE:
		{

			const helpers::Vector2D pivotRotationPoint{ topCenterOfWorld.getX(),
				                                        topCenterOfWorld.getY() + 1 };

			figure.reset(new figures::TetrisFigure{ pivotRotationPoint });
			figure->addFigureBlock(figures::FigureBlock{ { 'X' }, pivotRotationPoint });


			helpers::Vector2D direction{ 0, -1 }; //direction up, offset 1  
			figure->addFigureBlock(getNextBlock(pivotRotationPoint, direction));

			direction.setX(1); //change direction to right, offset 1
			direction.setY(0);
			figure->addFigureBlock(getNextBlock(pivotRotationPoint, direction));

			direction.setY(1);
			direction.setX(1); 
			figure->addFigureBlock(getNextBlock(pivotRotationPoint, direction));

			break;
		}

		case TetrisFigureId::T_FIGURE:
		{
			const helpers::Vector2D pivotRotationPoint{ topCenterOfWorld.getX(),
				                                        topCenterOfWorld.getY() + 1 };

			figure.reset(new figures::TetrisFigure{ pivotRotationPoint });
			figure->addFigureBlock(figures::FigureBlock{ { 'X' }, pivotRotationPoint });


			helpers::Vector2D direction{ 0, -1 }; //direction up, offset 1  
			figure->addFigureBlock(getNextBlock(pivotRotationPoint, direction));

			direction.setY(1); //change direction to down, offset 1
			figure->addFigureBlock(getNextBlock(pivotRotationPoint, direction));

			direction.setX(1); //change direction to right, offset 1
			direction.setY(0);
			figure->addFigureBlock(getNextBlock(pivotRotationPoint, direction));

			break;
		}

		default:
			break;
	}

	return figure;
}


std::unique_ptr<figures::TetrisFigure> TetrisFigureFactory::createRandomFigure(const helpers::Vector2D& topCenterOfWorld)
{
	std::unique_ptr<figures::TetrisFigure> figure{};

	const int tetrisFigureIdSize = static_cast<int>(TetrisFigureId::TETRIS_FIGURE_ID_SIZE) - 1;
 	auto randomId = helpers::RandomEngine::getInstance()->getRandomInteger(0, tetrisFigureIdSize);

	figure = this->createFigureById(static_cast<TetrisFigureId>(randomId), topCenterOfWorld);

	return figure;

}


figures::FigureBlock 
TetrisFigureFactory::getNextBlock(const helpers::Vector2D& pivotFigurePoint,
                                  const helpers::Vector2D& direction)
{
	helpers::Vector2D result = pivotFigurePoint + direction;
	return figures::FigureBlock{ { 'X' }, result };
}

