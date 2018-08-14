#include "ConsoleRenderTarget.h"


ConsoleRenderTarget::ConsoleRenderTarget()
{
	
}


ConsoleRenderTarget::~ConsoleRenderTarget()
{
}


void ConsoleRenderTarget::intialize(const unsigned int& width,
	                                const unsigned int& height)
{
	m_width = width;
	m_height = height;

	m_graficsBuffer.reserve(m_height + 1);

	while (m_graficsBuffer.size() < m_graficsBuffer.capacity())
	{
		std::vector<wchar_t> row(width + 1, { ' ' });
		m_graficsBuffer.push_back(row);
	}
}


void ConsoleRenderTarget::drawSymbol(const unsigned int& x,
	                                 const unsigned int& y,
	                                 const wchar_t& symbol)
{
	bool isValidPoint = ((x <= m_width) &&
		                 (x >= 0) &&
						 (y >= 0) &&
						 (y <= m_height));

	if (isValidPoint == true)
	{
		m_graficsBuffer[y][x] = symbol;
	}
}


void ConsoleRenderTarget::drawRect(const helpers::Rect& rect)
{
	for (int x = rect.left; x < rect.right; ++x){
		drawSymbol(x, rect.top, L'*');
		drawSymbol(x, rect.bottom, L'*');
	}

	for (int y = rect.top; y < rect.bottom; ++y){
		drawSymbol(rect.left, y, L'*');
		drawSymbol(rect.right, y, L'*');
	}
}


const unsigned int& ConsoleRenderTarget::getWidth()const
{
	return m_width;
}


const unsigned int& ConsoleRenderTarget::getHeight()const
{
	return m_height;
}


void ConsoleRenderTarget::clear()
{
	for (auto& row : m_graficsBuffer)
	{
		for (auto& symbol : row)
		{
			symbol = { ' ' };
		}
	}
}


void ConsoleRenderTarget::render(BaseApp& baseApp)const
{
	for (int y = 0; y < m_graficsBuffer.size(); ++y){
		for (int x = 0; x < m_graficsBuffer[y].size(); ++x){
			baseApp.SetChar(x, y, m_graficsBuffer[y][x]);
		}
	}
}


void ConsoleRenderTarget::drawText(const helpers::Vector2D& startPosition,
	                               const std::wstring& text)
{
	const unsigned int textLenght = text.length();
	unsigned int textIndex = 0;
	helpers::Vector2D positonInBuffer = startPosition;
	while (textIndex < textLenght)
	{
		unsigned int x = positonInBuffer.getX();
		drawSymbol(x, positonInBuffer.getY(), text[textIndex]);
		++x;
		positonInBuffer.setX(x);
		++textIndex;
	}
}
