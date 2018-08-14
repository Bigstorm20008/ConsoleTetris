#ifndef CONSOLE_RENDER_TARGET_H
#define CONSOLE_RENDER_TARGET_H

#include <vector>

#include "BaseApp.h"
#include "Rect.h"
#include "Vector2D.h"

class ConsoleRenderTarget
{
public:
	friend class ConsoleRenderSystem;

	ConsoleRenderTarget();
	~ConsoleRenderTarget();

	void intialize(const unsigned int& width,
		           const unsigned int& height);

	void drawSymbol(const unsigned int& x,
		            const unsigned int& y,
		            const wchar_t& symbol);

	void drawText(const helpers::Vector2D& startPosition, const std::wstring& text);

	void drawRect(const helpers::Rect& rect);

	const unsigned int& getWidth()const;

	const unsigned int& getHeight()const;

	void clear();

private:
	unsigned int m_width;
	unsigned int m_height;

	std::vector<std::vector<wchar_t>> m_graficsBuffer;

	void render(BaseApp& baseApp)const;
};

#endif // !CONSOLE_RENDER_TARGET_H




