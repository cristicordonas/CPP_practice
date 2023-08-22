#include <iostream>

#include "GameOfLife.h"

using namespace std;

int gridSize = 20;
bool** grid;

void CreateGrid(bool**& matrix, int size)
{
	gridSize = size;
	matrix = new bool* [gridSize];
	for (int i = 0; i < gridSize; i++)
	{
		matrix[i] = new bool[gridSize];
	}
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void DeleteGrid(bool**& matrix)
{
	for (int i = 0; i < gridSize; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void PrintGrid()
{
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			if (grid[i][j])
			{
				cout << '0' << ' ';
			}
			else
			{
				cout << '.' << ' ';
			}
			//cout << grid[i][j] << ' ';
		}
		cout << '\n';
	}
}

int CountLiveNeighbours(int x, int y)
{
	int counter = 0;
	for (int i = y - 1; i <= y + 1; i++)
	{
		for (int j = x - 1; j <= x + 1; j++)
		{
			if ((i == y && j == x) || i < 0 || j < 0 || i >= gridSize || j >= gridSize)
			{
				continue;
			}
			else if (grid[i][j])
			{
				counter++;
			}
		}
	}
	return counter;
}

void ChangeState()
{
	int alive;
	bool** newGrid;
	CreateGrid(newGrid, gridSize);
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			alive = CountLiveNeighbours(j, i);
			if (grid[i][j] && (alive < 2 || alive > 3))
			{
				newGrid[i][j] = false;
			}
			else if (!grid[i][j] && alive == 3)
			{
				newGrid[i][j] = true;
			}
			else
			{
				newGrid[i][j] = grid[i][j];
			}
		}
	}
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			grid[i][j] = newGrid[i][j];
		}
	}
	DeleteGrid(newGrid);
}

void DrawShape(shapes shape, int x, int y)
{
	bool block[4][4] = { {0, 0, 0, 0},
						 {0, 1, 1, 0},
						 {0, 1, 1, 0},
						 {0, 0, 0, 0} };
	bool boat[5][5] = { {0, 0, 0, 0, 0},
						{0, 1, 1, 0, 0},
						{0, 1, 0, 1, 0},
						{0, 0, 1, 0, 0},
						{0, 0, 0, 0, 0} };
	bool blinker[5][5] = { {0, 0, 0, 0, 0},
						   {0, 0, 0, 0, 0},
						   {0, 1, 1, 1, 0},
						   {0, 0, 0, 0, 0},
						   {0, 0, 0, 0, 0} };
	bool beacon[6][6] = { {0, 0, 0, 0, 0, 0},
						  {0, 1, 1, 0, 0, 0},
						  {0, 1, 0, 0, 0, 0},
						  {0, 0, 0, 0, 1, 0},
						  {0, 0, 0, 1, 1, 0},
						  {0, 0, 0, 0, 0, 0} };
	bool pulsar_1[17][17] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							  {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
							  {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
							  {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
							  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							  {0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0},
							  {0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0},
							  {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
							  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							  {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
							  {0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0},
							  {0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0},
							  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							  {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
							  {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
							  {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
							  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };
	bool pulsar_2[17][17] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							  {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
							  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							  {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0},
							  {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0},
							  {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0},
							  {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
							  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							  {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
							  {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0},
							  {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0},
							  {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0},
							  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							  {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
							  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };
	bool pentadecathlon[11][18] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0},
									{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0} };
	bool glider[5][5] = { {0, 0, 0, 0, 0},
						  {0, 0, 1, 0, 0},
						  {0, 0, 0, 1, 0},
						  {0, 1, 1, 1, 0},
						  {0, 0, 0, 0, 0} };
	switch (shape)
	{
	case BLOCK:
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (i + y >= 0 && i + y < gridSize && j + x >= 0 && j + x < gridSize)
				{
					grid[i + y][j + x] = block[i][j];
				}
			}
		}
		break;
	case BOAT:
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i + y >= 0 && i + y < gridSize && j + x >= 0 && j + x < gridSize)
				{
					grid[i + y][j + x] = boat[i][j];
				}
			}
		}
		break;
	case BLINKER:
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i + y >= 0 && i + y < gridSize && j + x >= 0 && j + x < gridSize)
				{
					grid[i + y][j + x] = blinker[i][j];
				}
			}
		}
		break;
	case BEACON:
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (i + y >= 0 && i + y < gridSize && j + x >= 0 && j + x < gridSize)
				{
					grid[i + y][j + x] = beacon[i][j];
				}
			}
		}
		break;
	case PULSAR_1:
		for (int i = 0; i < 17; i++)
		{
			for (int j = 0; j < 17; j++)
			{
				if (i + y >= 0 && i + y < gridSize && j + x >= 0 && j + x < gridSize)
				{
					grid[i + y][j + x] = pulsar_1[i][j];
				}
			}
		}
		break;
	case PULSAR_2:
		for (int i = 0; i < 17; i++)
		{
			for (int j = 0; j < 17; j++)
			{
				if (i + y >= 0 && i + y < gridSize && j + x >= 0 && j + x < gridSize)
				{
					grid[i + y][j + x] = pulsar_2[i][j];
				}
			}
		}
		break;
	case PENTADECATHLON:
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 18; j++)
			{
				if (i + y >= 0 && i + y < gridSize && j + x >= 0 && j + x < gridSize)
				{
					grid[i + y][j + x] = pentadecathlon[i][j];
				}
			}
		}
		break;
	case GLIDER:
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i + y >= 0 && i + y < gridSize && j + x >= 0 && j + x < gridSize)
				{
					grid[i + y][j + x] = glider[i][j];
				}
			}
		}
		break;
	default:
		cout << "The shape is not correct!\n";
	}
}