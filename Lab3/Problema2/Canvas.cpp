#include "Canvas.h"

Canvas::Canvas(int width, int height)
{
	board = new char* [width];
	for (int i = 0; i < width; i++) {
		board[i] = new char[height];
	}
	this->width = width;
	this->height = height;
	Clear();
}
Canvas::~Canvas() {
	for (int i = 0; i < width; ++i) {
		delete[] board[i];
	}
	delete[] board;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	int xr = ray;
	int yr = 0;
	int abs = 0;

	while (xr >= yr)
	{
		SetPoint(x + xr, y + yr, ch);
		SetPoint(x + yr, y + xr, ch);
		SetPoint(x - yr, y + xr, ch);
		SetPoint(x - xr, y + yr, ch);
		SetPoint(x - xr, y - yr, ch);
		SetPoint(x - yr, y - xr, ch);
		SetPoint(x + yr, y - xr, ch);
		SetPoint(x + xr, y - yr, ch);

		if (abs <= 0)
		{
			yr += 1;
			abs += 2 * yr + 1;
		}

		if (abs > 0)
		{
			xr -= 1;
			abs -= 2 * xr + 1;
		}
	}
}

void Canvas::FillCircle(int x, int y, int r, char ch)
{

}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{

	for (int i = 0; i < top; i++) {
		SetPoint(0, i, ch);
	}
	for (int i = 0; i < bottom; i++) {
		SetPoint(left - 1, i, ch);
	}
	for (int i = 0; i < left; i++) {
		SetPoint(i, 0, ch);
	}
	for (int i = 0; i < right; i++) {
		SetPoint(i, bottom - 1, ch);
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	DrawRect(left, top, right, bottom, ch);
	for (int i = 1; i < right - 1; ++i) {
		for (int j = 1; j < bottom - 1; ++j) {
			SetPoint(i, j, ch);
		}
	}

}

void Canvas::SetPoint(int x, int y, char ch)
{
	board[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx, dy, D, y, x;
	dx = x2 - x1;
	dy = y2 - y1;
	D = 2 * dy - dx;
	y = y1;
	for (x = x1; x < x2; ++x) {
		SetPoint(x, y, ch);
		if (D > 0) {
			y = y + 1;
			D = D - 2 * dx;
		}
		D = D + 2 * dy;
	}
}


void Canvas::Print() 
{
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			std::cout << board[i][j];
		}
		std::cout << '\n';
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			board[i][j] = ' ';
		}
	}
}
