#ifndef ADD_ENTRY_H
#define ADD_ENTRY_H
#include "../oned/oned.h"
using namespace std;

template<typename T>
void addEntry(T*& arr, const T value, int& size, int& capacity);
											//Function that adds a value to
											//a dynamic array and increases
											//it's size if necessary.
									//Precondition: size > 0
									//				size <= capacity
									//				capacity == len(arr)
									//Postcondition: The value "value"
									//has been added to the array and the
									//capacity has been increased if needed.

template<typename T>
void addEntryAtIndex(T*& arr, T value, int index, int& size, int& capacity);
											//Function that adds a value to
											//a dynamic array at an index
											//and increases it's size if 
											//necessary.
									//Precondition: size > 0
									//				size <= capacity
									//				capacity == len(arr)
									//				index <= size
									//				index >= 0
									//Postcondition: The value "value"
									//has been added to the array and the
									//capacity has been increased if needed.

template<typename T>
bool removeEntry(T*& arr, const T value, int& size, int& capacity);
											//Function that removes a value 
											//from a dynamic array and 
											//decreases it's size if
											//necessary.
									//Precondition: size > 0
									//				size <= capacity
									//				capacity == len(arr)
									//Postcondition: The value "value"
									//has been removed from the array
									//(if it even exists) and the capacity has
									//been decreased if necessary.

template<typename T>
void removeEntryAtIndex(T*& arr, int index, int& size, int& capacity);
											//Function that removes a value 
											//from a dynamic array at an index
											//and decreases it's size if
											//necessary.
									//Precondition: size > 0
									//				size <= capacity
									//				capacity == len(arr)
									//				index < size
									//				index >= 0
									//Postcondition: The value "value"
									//has been removed from the array
									//(if it even exists) and the capacity has
									//been decreased if necessary.

template<typename T>
void addEntry(T*& arr, T value, int& size, int& capacity) {
	const int initialCapacity = 6;

	if (size == capacity) {
		if (capacity == 0) {
			arr = reallocate(arr, capacity, capacity + initialCapacity);
		}
		else {
			arr = reallocate(arr, capacity, capacity * 2);
		}
		//Reallocates memory to double the size of the array in
		//order to add another element into the array.
	}

	T* loc = arr + size;
	//Location of the end of the array (where the new value will
	//be written).

	*loc = value;
	size++;
	//The new value is inserted at the end of the array and the
	//size has been increased.
}

template<typename T>
void addEntryAtIndex(T*& arr, T value, int index, int& size, int& capacity) {
	assert(index >= 0 && index <= size);
	const int initialCapacity = 6;

	if (capacity < 6) {
		arr = reallocate(arr, capacity, 6);
	}
		//Reallocates memory to 6 if the capacity < 6.

	if (size == capacity) {
			arr = reallocate(arr, capacity, capacity * 2);
	}
		//Reallocates memory to double the size of the array in
		//order to add another element into the array.

	
	T* loc = arr + index;
	//Location of the index in the array (where the new value will
	//be written).
	shiftRight(loc, arr, size, capacity);

	*loc = value;
	//The new value is inserted at index location in the array and the
	//size has been increased.
}

template<typename T>
bool removeEntry(T*& arr, T value, int& size, int& capacity) {

	if (findInArray(arr, value, size) == nullptr) {
		return false;
		//Returns false and ends function if the desired value is not in the
		//array.
	}

	T* loc = findInArray(arr, value, size);
	//The memory location of the value to be removed.

	shiftLeft(loc, arr, size);
	//The location "loc" has been overwritten and the
	//size has been reduced.

	if (capacity > 6 && capacity / 4 == size) {
		arr = reallocate(arr, capacity, capacity / 2);
	}
	//If the array's current size is equal to half of it's
	//capacity, then the capacity of the array is decreased by one
	//half.

	return true;
	//The function returns true to signify that the function
	//has removed the desired value.
}

template<typename T>
void removeEntryAtIndex(T*& arr, int index, int& size, int& capacity) {
	assert(index < size && index >= 0);

	T* loc = arr + index;
	//The memory location of the value to be removed.

	shiftLeft(loc, arr, size);
	//The location "loc" has been overwritten and the
	//size has been reduced.

	if (capacity > 6 && capacity / 4 == size) {
		arr = reallocate(arr, capacity, capacity / 2);
	}
	//If the array's current size is equal to half of it's
	//capacity, then the capacity of the array is decreased by one
	//half.
}
#endif // !ADD_ENTRY_H
