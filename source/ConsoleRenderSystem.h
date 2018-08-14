#ifndef CONSOLE_RENDER_SYSTEM_H
#define CONSOLE_RENDER_SYSTEM_H

#include "BaseApp.h"
#include "ConsoleRenderTarget.h"

class ConsoleRenderSystem
{
public:
	ConsoleRenderSystem(BaseApp& baseApp,
		                const unsigned int& consoleWindowWidth,
		                const unsigned int& consoleWindowHeight);

	~ConsoleRenderSystem();

	ConsoleRenderTarget& getRenderTarget();

	void render();


private:
	BaseApp* const m_baseApp;
	ConsoleRenderTarget m_ConsoleRenderTarget;

};

#endif // !CONSOLE_RENDER_SYSTEM_H




