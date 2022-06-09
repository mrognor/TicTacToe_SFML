#pragma once
#include <SFML/Graphics.hpp>

class Game
{
public:
	// 0 - empty, 1 - tic, 2 - tac
	int Cells[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	bool IsFirstPlayerStep = true;

	void Run();
};
