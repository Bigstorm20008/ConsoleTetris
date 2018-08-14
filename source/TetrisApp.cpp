#include "TetrisApp.h"


TetrisApp::TetrisApp(const unsigned int& windowWidth,
	                 const unsigned int& windowHeight) : 

					 BaseApp{ static_cast<int>(windowWidth),
	                          static_cast<int>(windowHeight) },

			         m_isInitialized{ false },
			         m_isActiveGameState{ false },
			         m_level{},
			         m_consoleRenderSystem{}
{
}


TetrisApp::~TetrisApp()
{
	if (m_level != nullptr){
		delete m_level;
		m_level = nullptr;
	}

	if (m_consoleRenderSystem != nullptr){
		delete m_consoleRenderSystem;
		m_consoleRenderSystem = nullptr;
	}

}


void TetrisApp::initialize()
{
	prepeareConsoleWindow();
	
	m_consoleRenderSystem = new ConsoleRenderSystem( *this , BaseApp::X_SIZE, BaseApp::Y_SIZE );

	m_level = new Level;
	m_level->initialize( m_consoleRenderSystem->getRenderTarget() );

	m_isInitialized = true;
	m_isActiveGameState = true;
}


void TetrisApp::prepeareConsoleWindow()
{
	HWND consoleHwnd = GetConsoleWindow();
	long Style = GetWindowLong( consoleHwnd, GWL_STYLE );
	Style &= ~WS_SIZEBOX;
	Style &= ~WS_MINIMIZEBOX;
	Style &= ~WS_MAXIMIZEBOX;
	//Style &= ~WS_VSCROLL;
	SetWindowLong( consoleHwnd, GWL_STYLE, Style );
}


void TetrisApp::KeyPressed( int btnCode )
{
	const Key key = static_cast<Key>(btnCode);


	if (key == Key::q){
		m_isActiveGameState = false;
	}
	else{
		m_level->processInput(key);
	}
}


void TetrisApp::UpdateF(float deltaTime)
{
	m_level->update( m_consoleRenderSystem->getRenderTarget() );
	m_consoleRenderSystem->render();
}


void TetrisApp::run()
{
	if (m_isInitialized == true){
		std::thread t1(&TetrisApp::Run, this);
		t1.detach();
	}

	while (true){
		if (m_isActiveGameState == true){
			std::this_thread::sleep_for(std::chrono::milliseconds{ 20 });
		}
		else{
			break;
		}
	}

}


void TetrisApp::exit()
{
	m_isActiveGameState = false;
}

