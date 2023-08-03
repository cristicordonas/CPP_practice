#include <iostream>
#include <string>
#include <vector>

/**
	Define a simple matrix.
*/
class Matrix
{
private:
	size_t column_count;
	size_t line_count;
	std::vector<std::string> matrix;

public:
	Matrix(size_t numColumnsX, size_t numLinesY)
	{
		column_count = numColumnsX;
		line_count = numLinesY;
	}

	// Set an entire line
	void setLine(size_t line_number, const std::string& data)
	{
		if (line_number < 0 || line_number > line_count)
		{
			std::cout << "The line number is invalid" << std::endl;
			return;
		}
		if (data.size() > column_count)
		{
			std::cout << "The data size is greater than column number" << std::endl;
			return;
		}
		matrix.emplace(matrix.begin() + line_number, data);
	}

	char getCellXY(size_t x, size_t y)
	{
		if (x < 0 || x > column_count || y < 0 || y > line_count)
		{
			return 0;
		}
		return matrix[y][x];
	}

	/**
		Sets the cell content for a specific cell identified by its coordinates (X and Y)
		@param x The horizontal coordinate of the cell to set. Index starts at zer0.
		@param y The vertical coordinate of the cell to set. Index starts at zer0.
		@param cell_content A cell char to set.

		E.g.
		 X axis: 0 -------- ... -------> Width
		 Y axis
		 0       0,0  1,0                W-1, 0
		 |       0,1  1,1                     
		 |       0,2                      
		 .                             
		 .                             
		 .                             
		 |       0, H-1     ...          W-1, H-1           
		 V

		 Height
	*/
	void setCellXY(size_t x, size_t y, char cell_content)
	{
		if (x < 0 || x > column_count)
		{
			std::cout << "The x coordinate is invalid" << std::endl;
			return;
		}
		if (y < 0 || y > line_count)
		{
			std::cout << "The y coordinate is invalid" << std::endl;
			return;
		}
		matrix[y][x] = cell_content;
	}

	void print()
	{
		// print all lines and columns
		for (int i = 0; i < line_count; i++)
		{
			std::cout << matrix.at(i) << std::endl;
		}
	}
};

int main()
{
	// Create a matrix with the width of 20 and height of 10.
	Matrix matrix(20, 10);

	matrix.setLine(0, "X-----X----X-----XX-");
	matrix.setLine(1, "--X-----------------");
	matrix.setLine(2, "-----X--------------");
	matrix.setLine(3, "--------X-----------");
	matrix.setLine(4, "-----------X--------");
	matrix.setLine(5, "--------------X-----");
	matrix.setLine(6, "-----------------X--");
	matrix.setLine(7, "-------------------X");
	matrix.setLine(8, "------------------X-");
	matrix.setLine(9, "-----------------X--");

	std::cout << matrix.getCellXY(8, 3) << std::endl;

	matrix.print();
	// Would print
/*
X-----X----X-----XX-
--X-----------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
-------------------X
------------------X-
-----------------X--
*/

	matrix.setCellXY(2, 1, '-');
	matrix.print();
	// Would print
/*
X-----X----X-----XX-
--------------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
-------------------X
------------------X-
-----------------X--
*/

	matrix.setCellXY(3, 7, 'O');
	matrix.print();
	/*
X-----X----X-----XX-
--------------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
---O---------------X
------------------X-
-----------------X--
*/

	// This should silently fail (not trigger an error): cell Y=11 invalid due to limited height.
	matrix.setCellXY(3, 11, 'O');
	return 0;
}
