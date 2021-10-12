#include "twod.h"

int getSize(int* sizes) {
	int* walker = sizes;
			//Iterative pointer pointing to the beginning of
			//the "sizes" array.
	while (*walker != -1) {
		walker++;
	}
			//Loop iterates to the end of the walker array
			//(signified by a -1).

	return walker - sizes;
			//walker - sizes = the length of the array. This is
			//returned.
}

bool isValid(int* sizes, int row, int col) {
return (row < getSize(sizes) && col < *(sizes + row));
			//Checks if the indexed row and column
			//values are within the bounds of the
			//signified by sizes.
}

void initDebug(int** arr2D, int* sizes) {
	int** currentRow = arr2D;
	int** rowEnd = arr2D + getSize(sizes);
			//Pointers to the start and end of the array
			//used to iterate through every value in the
			//array.

	int* currentCol;
	int* colEnd;
			//Pointers signifying the start and end of each
			//array of columns of each row in the loop.
			//(This is needed because there is no init debug
			//function in the "oned" file that can be
			//utilized in this function.)

	int row = 0, column = 0;
			//ints representing the current row and the column
			//value assign in the 2D array through the loop
			//Ex.
			// row = 2, column = 1 =====>> value = 21 for
			// that row and column in the array.

	while (currentRow < rowEnd) {
		currentCol = *currentRow;
		colEnd = *currentRow + *sizes;
				//pointers are assigned to the start and end
				//of the current row in the 2D array.

		while (currentCol < colEnd) {

			*currentCol = row * 10 + column;
					//The value at row, column is assigned to a
					//two digit number signifying it's place in
					//the array (As stated before).

			column++;
			currentCol++;
					//Iterates to the next value in the current row.
		}

		row++;
		column = 0;
		currentRow++;
		sizes++;
				//Iterating the next row and resetting the column value
				//back to 0.
	}
}