#include <memory>

#include "TetrisApp.h"

std::unique_ptr<TetrisApp> tetrisApp{};

BOOL CtrlHandler(DWORD fdwCtrlType)
{

	switch (fdwCtrlType)
	{
		case CTRL_CLOSE_EVENT:
		case CTRL_BREAK_EVENT:
		case CTRL_SHUTDOWN_EVENT:
			if (tetrisApp.get() != nullptr)
			{
				tetrisApp->exit();
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(20000));
			return TRUE;

		default:
			return FALSE;
	}
}

int main()
{

	if (SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE) == TRUE)
	{
		tetrisApp.reset(new TetrisApp(80, 40));
		tetrisApp->initialize();
		tetrisApp->run();
	}

	tetrisApp.reset();

	return 0;
}

