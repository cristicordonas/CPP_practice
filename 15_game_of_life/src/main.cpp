#include <iostream>
#include <Windows.h>

#include "GameOfLife.h"

using namespace std;

int main()
{
	int ticks = 0;
	int size = 0;
	cout << "Enter the size of grid (minimum 20): ";
	cin >> size;
	if (size < 20)
	{
		cout << "This size is too small, the default size is 20.\n";
		CreateGrid(grid, gridSize);
	}
	else
	{
		CreateGrid(grid, size);
	}
	cout << "Enter the number of thicks: ";
	cin >> ticks;
	//DrawShape(BLOCK, 0, 0);
	//DrawShape(BOAT, 0, 0);
	//DrawShape(BLINKER, 0, 0);
	//DrawShape(BEACON, 0, 0);
	//DrawShape(GLIDER, 0, 0);
	DrawShape(PENTADECATHLON, 0, 0);
	//DrawShape(PULSAR_1, 0, 0);
	//DrawShape(PULSAR_2, 0, 0);
	cout << "This is the inital grid:\n";
	PrintGrid();
	cout << "Do you want to start? (y/n)\n";
	cin.get();
	if (cin.get() == 'y')
	{
		for (int i = 1; i <= ticks; i++)
		{
			system("cls");
			ChangeState();
			PrintGrid();
			Sleep(1000);
		}
	}
	cout << "THE END!";
	DeleteGrid(grid);
	return 0;
}
