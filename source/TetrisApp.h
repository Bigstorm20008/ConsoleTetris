#ifndef TETRIS_APP_H
#define TETRIS_APP_H

#include <thread>


#include "BaseApp.h"
#include "Keys.h"
#include "Level.h"
#include "ConsoleRenderSystem.h"

class TetrisApp :
	public BaseApp
{
public:
	TetrisApp(const unsigned int& windowWidth, const unsigned int& windowHeight);
	virtual ~TetrisApp();

	void initialize();
	void run();
	void exit();
private:
	bool m_isInitialized;
	bool m_isActiveGameState;
	Level* m_level;
	ConsoleRenderSystem* m_consoleRenderSystem;

	void prepeareConsoleWindow();
	void KeyPressed(int btnCode) override;
	void UpdateF(float deltaTime)override;

};

#endif // !TETRIS_APP_H



