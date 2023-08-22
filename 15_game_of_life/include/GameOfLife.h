#pragma once

extern int gridSize;
extern bool** grid;

enum shapes
{
	BLOCK,
	BOAT,
	BLINKER,
	BEACON,
	PULSAR_1,
	PULSAR_2,
	PENTADECATHLON,
	GLIDER
};

void CreateGrid(bool**& matrix, int size);
void DeleteGrid(bool**& matrix);
void PrintGrid();
int CountLiveNeighbours(int x, int y);
void ChangeState();
void DrawShape(shapes shape, int x, int y);
