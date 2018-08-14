#include "ConsoleRenderSystem.h"


ConsoleRenderSystem::ConsoleRenderSystem(BaseApp& baseApp,
	                                     const unsigned int& consoleWindowWidth,
	                                     const unsigned int& consoleWindowHeight) :
	                                     m_baseApp{ &baseApp }
{
	m_ConsoleRenderTarget.intialize(consoleWindowWidth, consoleWindowHeight);
}


ConsoleRenderSystem::~ConsoleRenderSystem()
{
}

ConsoleRenderTarget& ConsoleRenderSystem::getRenderTarget()
{
	return m_ConsoleRenderTarget;
}

void ConsoleRenderSystem::render()
{
	m_ConsoleRenderTarget.render(*m_baseApp);
}
