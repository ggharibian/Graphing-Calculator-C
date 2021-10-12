#ifndef TWOD_H
#define TWOD_H
#include "oned.h"
#include <cassert>
#include <iostream>
using namespace std;

//DEFINITIONS

int getSize(int* sizes);

bool isValid(int* sizes, int row, int col);
											//Function that takes in an
											//array of sizes and row / column
											//locations and returns whether 
											//the index is within the array's 
											//range.
									//Precondition: None
									//Postcondition: The function will return
									//true if 0 <= row < len(sizes) and
									//if 0 <= col < sizes[row].

template<typename T>
T read(T** arr, int row, int col, int* sizes);
											//This function returns the value
											//at the row/ column location in
											//the array "arr".
									//Precondition: 0 <= row < len(sizes)
									//				0 <= col < sizes[row]
									//Postcondition: The value at the index
									//location row, col in the 2D array has 
									//been returned.

template<typename T>
T& get(T** arr, int row, int col, int* sizes);
											//This function returns the
											//reference location of the
											//value at the index row, col
											//in the array.
									//Precondition: 0 <= row < len(sizes)
									//				0 <= col < sizes[row]
									//Postcondition: The reference location at
									//the index location row, col in the 2D 
									//array has been returned.

template<typename T>
void write(T** arr, T value, int row, int col, int* sizes);
											//This function takes in a value
											//and row and column locations
											//and assigns the value at
											//that location in the array.
									//Precondition: 0 <= row < len(sizes)
									//				0 <= col < sizes[row]
									//Postcondition: The location at index 
									//row, col in the array has been 
									//assigned array  the value "value".

template<typename T>
bool search(T** twod, const T& key, int& row, int& col, int* sizes);
										    //Searchs through the array for 
											//the first occurence of the value
											//"key" and assigns the row and
											//column index of this key to row
											//and col while also returning
											//whether the key has been found 
											//or not.
									//Precondition: None.
									//Postcondition: The row and column
									//location of the key is assigned
									//to row and col whether or not the
									//value was found is returned.

template<typename T>
T* search(T** twod, int* sizes, const T& key);
											//Searchs through the array for 
											//the first occurence of the value
											//"key" and returns a pointer to
											//the location of key. nullptr if
											//it doesn't exist.
									//Precondition: None.
									//Postcondition: The location of "key" in
									//the array is returned if it exists.

template<typename T>
T** allocate(int* sizes);
											//This function returns a 2D
											//dynamic array with len(sizes)
											//rows and *sizes length columns
											//for every value in sizes.
									//Precondition: capacity >= 0
									//Postcondition: An array of size capacity
									//has been returned.

template<typename T>
void deallocate(T** arr, int* sizes);
											//This function takes in a dynamic
											//2D array and deallocates it.
									//Precondition: 0 <= loc < size
									//				loc < size <= len(arr)
									//Postcondition: The 2D array has been 
									//deallocated.

template<typename T>
void print(T** arr, int* sizes, int width = -1);
												//Prints all the values in the
												//2D array.
										//Precondition: None
										//Postcondition: All elements in
										//				the 2D arr have been
										//				printed.

template<typename T>
void init(T value, T** arr2D, int* sizes);
											//This function assigns all
											//values in the 2D array
											//to the value "value".
									//Precondition: *sizes for all values in
									//				sizes <= len(*arr2D) for
									//				all values in arr2D.
									//Postcondition: All values in arr2D
									//have been assigned to value.

void initDebug(int** arr2D, int* sizes);
											//This function assigns all
											//values in the 2D array
											//to a pattern for debugging.
									//Precondition: *sizes for all values in
									//				sizes <= len(*arr2D) for
									//				all values in arr2D.
									//Postcondition: All values in arr2D
									//have been assigned to a debug value.

//DECLARATIONS

template<typename T>
T read(T** arr, int row, int col, int* sizes) {
	assert(isValid(sizes, row, col));	//Exits the program if row, col is not
	
	return get(arr, row, col, sizes);
							//The value at the desired row, column is 
							//returned.
}

template<typename T>
void write(T** arr, T value, int row, int col, int* sizes) {
	assert(isValid(sizes, row, col));	//Exits the program if row, col is not
										// a valid location int the array.

	get(arr, row, col, sizes) = value;
							//The value at the location of the desired row,
							//column is assigned to "value".
}

template<typename T>
T& get(T** arr, int row, int col, int* sizes) {
	assert(isValid(sizes, row, col));	//Exits the program if row, col is not
										// a valid location int the array.

	T** arrRow = arr + row;
							//The reference location designated by the 
							//inputted row, col value.

	return get(*arrRow, col, *(sizes + row));
							//The memory location of the desired row, column
							//is returned.
}

template<typename T>
bool search(T** twod, const T& key, int& row, int& col, int* sizes)
{
	T** rowP = twod;
	T** rowEnd = twod + getSize(sizes);
							//Pointers to the start and end of the row array
							//used for iterating over the entire array.

	T* item;
					//Pointer representing the location of key in the array of
					//columns for a specific row.

	while (rowP < rowEnd) {
		item = findInArray(*rowP, key, * sizes);
					//item => The location of key in the array.

		if (item != NULL) {
					//If the item has been found in this row.

			row = rowP - twod;
			col = item - *rowP;
			return true;
					//The values of row and col are reassigned to the row and
					//column locations of the item, and the function returns 
					//true.
		}

		rowP++;
		sizes++;
	}

	return false;
				//Return false if the item has not been found.
}

template<typename T>
T* search(T** twod, int* sizes, const T& key)
{
	T** rowP = twod;
	T** rowEnd = twod + getSize(sizes);
							//Pointers to the start and end of the row array
							//used for iterating over the entire array.

	T* item;
					//Pointer representing the location of key in the array of
					//columns for a specific row.

	while (rowP < rowEnd) {
		item = findInArray(*rowP, key, *sizes);
				//item => The location of key in the array.

		if (item != NULL) {
			//If the item has been found in this row.

			return item;
					//The reference location of item is returned.
		}

		rowP++;
		sizes++;
	}

	return nullptr;
			//Returns a null pointer if the item wasn't found.
}

template<typename T>
T** allocate(int* sizes)
{
	T** arr = new T * [getSize(sizes)];	//Pointer to the start of the 2D 
										//array.

	T** arrCurrent = arr;
	T** arrEnd = arr + getSize(sizes);
								//Pointers to the start and end of the array
								//used to iterate through every value in the
								//array.

	while (arrCurrent < arrEnd) {
		*arrCurrent = allocate<T>(*sizes);
						//Creates a new array signifying the columns for each
						//row in a 2D array.

		sizes++;
		arrCurrent++;
					//Iterates to the next row in the 2D array.
	}

	arrCurrent = nullptr;
					//The last value in the array will be set to a null
					//pointer in order to signify an end to our array.
					//(A precursor to the link lists we will build in the
					//future).

	return arr;
				//Returns the newly allocated array.
}

template<typename T>
void deallocate(T** arr, int* sizes) {
	T** current = arr;
	T** end = arr + getSize(sizes);
								//Pointers to the start and end of the array
								//used to iterate through every value in the
								//array.

	while (current < end) {
		deallocate(*current);
		current++;
						//Loop deallocates all the individual dynamic arrays
						//in the 2D array to avoid wasting space later on.
	}

	delete[] arr;
					//Deallocation of the dynamic 2D array.

}

template<typename T>
void print(T** arr, int* sizes, int width) {
	T** currentRow = arr;
	T** endRow = arr + getSize(sizes);
								//Pointers to the start and end of the array
								//used to iterate through every value in the
								//array.

	while (currentRow < endRow) {

		print(*currentRow, *sizes, width);

		currentRow++;
		sizes++;
						//Loop prints every row in the 2D array on a new line
						//in the console.
						//Ex.
						//	* * *
						//	* * * * *
						//	*
	}
}

template<typename T>
void init(T value, T** arr2D, int* sizes) {
	T** arrCurrent = arr2D;
	T** arrEnd = arr2D + getSize(sizes);
								//Pointers to the start and end of the array
								//used to iterate through every value in the
								//array.

	while (arrCurrent < arrEnd) {
		init(value, *arrCurrent, *sizes);

		sizes++;
		arrCurrent++;

					//Loop initializes all values in the 2D array to the 
					//value "value".
	}
}

#endif