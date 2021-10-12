#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <cassert>
#include "../Add_remove/Add_Entry.h"
using namespace std;

template<typename T>
class myVector
{
public:
	//Constructors

	myVector(unsigned int capacity = 6);
	myVector(int size, int capacity);

	//Big Three
	myVector(const myVector& v);
	myVector& operator =(const myVector& other);
	~myVector();

	//Accessors
	const int getSize(); 
	const int getCapacity();

	//Mutators
	int setSize(int size);		//Sets _size to size. Throws error if 
								//size > _capacity || size < 0
	int setCapacity(int capacity);	//Sets _capacity to capacity. Throws an
									//error if _capacity < 0.

	//Member Access Functions

	const T operator [](const unsigned int index) const;
	T& operator [](const unsigned int index);
	T& at(int index);             //return reference to item at position index
    const T at(int index) const;  //return a const item at position index
    T& front() const;             //return item at position 0.
    T& back() const;              //return item at the last position

	//Push and Pop functions:
	myVector<T>& operator +=(const T& item); //push_back
	void push_back(const T& item);      //append to the end
	T pop_back();                       //remove last item and return it

	//Insert and Erase:
	void insert(int insert_here, const T& insert_this); //insert at pos
	void erase(int erase_index);        //erase item at position
	int index_of(const T& item);        //search for item. retur index.

	bool empty() const;                 //return true if vector is empty

	//Output
	template<typename U>
	friend ostream& operator<<(ostream& outs, const myVector<U>& v);

private:
	T* _v;
	int _size;
	int _capacity;
	
};

//------------------------------------------
//Constructors:
//------------------------------------------

template<typename T>
myVector<T>::myVector(unsigned int capacity): _size(0), _capacity(capacity)
{
	_v = allocate<T>(_capacity);
			//Utilizes the "oned" functionallocate to create the array. Checks
			//for a negative capacity and returns errors if needed.
}

template<typename T>
myVector<T>::myVector(int size, int capacity): _capacity(capacity)
{
	_v = allocate<T>(_capacity);
	setSize(size);
			//Set size will automatically check for an invalid size.

}

//------------------------------------------
//Big Three functions:
//------------------------------------------

template<typename T>
myVector<T>::myVector(const myVector<T>& v)
{		//Needed to utilize "myVector" as a function parameter.

	_size = v._size;
	_capacity = v._capacity;
	_v = allocate<T>(v._capacity);

	copy_list(_v, v._v, _capacity, v._capacity, _size);
			//Creates exact copy of all elements in vector v.
}

template<typename T>
myVector<T>& myVector<T>::operator=(const myVector& other)
{
	if (_v == other._v)
		return *this;
			//Checks for self reference. Needed to avoid deleting the array
			//and all it's values.

	delete[] _v;

	_size = other._size;
	_capacity = other._capacity;
	_v = allocate<T>(other._capacity);

	copy_list(_v, other._v, _capacity, other._capacity, _size);

	return *this;
}

template<typename T>
myVector<T>::~myVector()
{		//Needed to deallocate the array after the vector is deallocated.

	delete[] _v;
}

//------------------------------------------
//Accessor functions:
//------------------------------------------

template<typename T>
const int myVector<T>::getSize()
{
	return _size;
}

template<typename T>
const int myVector<T>::getCapacity()
{
	return _capacity;
}

//------------------------------------------
//Mutator functions:
//------------------------------------------

template<typename T>
int myVector<T>::setSize(int size)
{
	assert(size <= _capacity && size >= 0);
	//The user is not allowed to expand the capacity of the
	//vector through the setSize function.

	if (size > _size)
		init(_v + _size, size - _size);
	//Sets inital values for all new accessible locations for the
	//vector of the new size.

	_size = size;

	return _size;
}

template<typename T>
int myVector<T>::setCapacity(int capacity)
{
	assert(capacity >= 0);

	if (_size > capacity)
		_size = capacity;

	_capacity = capacity;
	_v = reallocate<T>(_v, _capacity, capacity);

	return _capacity;
}

//------------------------------------------
//Member Access functions:
//------------------------------------------

template<typename T>
const T myVector<T>::operator[](const unsigned int index) const
{
	return at(index);
}

template<typename T>
T& myVector<T>::operator[](const unsigned int index)
{
	return at(index);
}

template<typename T>
T& myVector<T>::at(int index)
{
	return get(_v, index, _size);
}

template<typename T>
const T myVector<T>::at(int index) const
{
	return at(index);
}

template<typename T>
T& myVector<T>::front() const
{
	return get(_v, 0, _size);
}

template<typename T>
T& myVector<T>::back() const
{
	return get(_v, _size - 1, _size);
}

//------------------------------------------
//Push and Pop functions:
//------------------------------------------

template<typename T>
myVector<T>& myVector<T>::operator+=(const T& item)
{
	push_back(item);
	return *this;
}

template<typename T>
void myVector<T>::push_back(const T& item){
	addEntry(_v, item, _size, _capacity);
			//Utilizes the Add_Entry class for expanding and reducing the 
			//size.
}

template<typename T>
T myVector<T>::pop_back()
{
	T temp = back();
	removeEntryAtIndex(_v, _size - 1, _size, _capacity);

	return temp;
}

//------------------------------------------
//Insert and Erase functions:
//------------------------------------------

template<typename T>
void myVector<T>::insert(int insert_here, const T& insert_this)
{
	addEntryAtIndex(_v, insert_this, insert_here, _size, _capacity);
}

template<typename T>
void myVector<T>::erase(int erase_index)
{
	removeEntryAtIndex(_v, erase_index, _size, _capacity);
			//The Add_entry functions will automatically assert the validity
			//of the index as the function is called. Throws error is needed.
}

template<typename T>
int myVector<T>::index_of(const T& item)
{
	return indexOf(_v, item, _size);
}

//------------------------------------------
//Empty functions:
//------------------------------------------

template<typename T>
bool myVector<T>::empty() const
{
	return _size == 0;
}

#endif // !MYVECTOR_H