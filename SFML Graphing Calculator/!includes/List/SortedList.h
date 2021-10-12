#ifndef SortedList_H
#define SortedList_H
#include "../Node/Linked_List_Functions.h"

template<typename T>
class SortedList {
public:

	class Iterator {
	public:
		friend class SortedList;

		Iterator(Node<T>* ptr = nullptr): _ptr(ptr){}

		Iterator Next() {
			return Iterator(_ptr->_next);
		}

		Node<T>& operator *() {
			assert(_ptr);
			return *_ptr;
		}

		const Node<T> operator *() const{
			assert(_ptr);
			return *_ptr;
		}

		Node<T>* operator ->() { //Uhhhh doesn't this give the user access to
								 //the Node "_next"? Ask barkeshli monday
			assert(_ptr);
			return _ptr;
		}

		const Node<T>* operator ->() const{
			assert(_ptr);
			return _ptr;
		}

		operator bool() {
			return _ptr != nullptr;
		}

		bool isNull() {
			return _ptr == nullptr;
		}

		friend bool operator !=(const Iterator& left, const Iterator& right) {
			return left._ptr != right._ptr;
		}

		friend bool operator ==(const Iterator& left, const Iterator& right) {
			return left._ptr == right._ptr;
		}

		friend Iterator operator ++(Iterator& it, int unused) {
			Iterator old = it;
			it = it.Next();
			return old;
		}

		Iterator& operator ++() {
			*this = this->Next();
			return *this;
		}

	private:
		Node<T>* _ptr;
	};

	//Constructor
	SortedList(bool order = true, bool unique = true);

	//Big Three Functions
	~SortedList();
	SortedList(const SortedList<T>& copyThis);
	SortedList<T>& operator =(const SortedList<T>& rhs);

	SortedList<T>::Iterator InsertItem(const T& item);

	//Delete Function
	T Delete(SortedList::Iterator location);

	//Print Function
	void Print() const;

	//Search Function
	SortedList<T>::Iterator Search(const T key) const;

	//Traversal Functions
	SortedList<T>::Iterator Next(SortedList<T>::Iterator location) const;
	SortedList<T>::Iterator Prev(SortedList<T>::Iterator location) const;

	//Bracket Access Operator
	T& operator [](int index) const;

	//Accessor Functions
	SortedList<T>::Iterator Begin() const;
	SortedList<T>::Iterator End() const;
	bool Empty() const;

	//Output Operator
	template<typename U>
	friend ostream& operator <<(ostream& outs, const SortedList<U>& l);

	template<typename U>
	friend bool operator ==(const SortedList<U>& lhs, const SortedList<U>& rhs);

private:

	//The head of the linked SortedList.
	Node<T>* _head;
	bool _order;
	bool _unique;

};

	//Note: Check the "Linked_List_Functions.h" file for documentation for 
	//further info helper functions.

//------------------------------------------
//Constructor:
//------------------------------------------

template<typename T>
SortedList<T>::SortedList(bool order, bool unique): _head(nullptr), _order(order), _unique(unique)
{

}

//------------------------------------------
//Big Three Functions
//------------------------------------------

template<typename T>
SortedList<T>::~SortedList()
{	//Deallocates the SortedList using the clearList() function.
	clearList(_head);
}

template<typename T>
SortedList<T>::SortedList(const SortedList<T>& copyThis)
{	//Copies the SortedList using thr copySortedList() function.

	_head = copyList(copyThis._head);
	_order = copyThis._order;
	_unique = copyThis._unique;
}

template<typename T>
SortedList<T>& SortedList<T>::operator=(const SortedList<T>& rhs)
{

	if (this->_head == rhs._head)
		return *this;
			//Checking for self reference.

	clearList(_head);
			//Deletes old SortedList

	_head = copyList(rhs._head);
			//Creates a new copy of the SortedList.

	_order = rhs._order;
	_unique = rhs._unique;

	return *this;

}

//------------------------------------------
//Insertion Functions:
//------------------------------------------

template<typename T>
typename SortedList<T>::Iterator SortedList<T>::InsertItem(const T& item)
{
	if (_unique) {
		return SortedList<T>::Iterator(insertSortedAndAdd(_head, item, _order));
	}
	else
		return SortedList<T>::Iterator(insertSorted(_head, item, _order));
			//Inserts an item into a sorted SortedList.
			//SortedList must be sorted to work.
}

//------------------------------------------
//Delete Function:
//------------------------------------------

template<typename T>
T SortedList<T>::Delete(SortedList<T>::Iterator location)
{
	return deleteNode(_head, location._ptr);
			//Deletes the node at location from the SortedList.
}

//------------------------------------------
//Print Function:
//------------------------------------------

template<typename T>
void SortedList<T>::Print() const
{
	print(_head);
			//Prints the SortedList to the console.
}

//------------------------------------------
//Search Function:
//------------------------------------------

template<typename T>
typename SortedList<T>::Iterator SortedList<T>::Search(const T key) const
{
	return Iterator(searchList(_head, key));
			//Returns the location of key in SortedList.
}

//------------------------------------------
//Traversal Functions:
//------------------------------------------

template<typename T>
typename SortedList<T>::Iterator SortedList<T>::Next(SortedList<T>::Iterator location) const{
	return location.Next();
			//Gets the next node. Asserts if location is not in the SortedList.
}

template<typename T>
typename SortedList<T>::Iterator SortedList<T>::Prev(SortedList<T>::Iterator location) const
{
	return previousNode(_head, location._ptr);
			//Gets the previous node. Asserts if location is not in the SortedList.
}

//------------------------------------------
//Bracket Access Operator:
//------------------------------------------

template<typename T>
T& SortedList<T>::operator[](int index) const
{
	return at(_head, index);
			//Gets value at index. Asserts if out of bounds.
}

//------------------------------------------
//Accessor Functions:
//------------------------------------------

template<typename T>
typename SortedList<T>::Iterator SortedList<T>::Begin() const
{
	return Iterator(_head);
}

template<typename T>
typename SortedList<T>::Iterator SortedList<T>::End() const
{
	return Iterator(nullptr);
}

template<typename T>
bool SortedList<T>::Empty() const
{
	return _head == nullptr;
}

//------------------------------------------
//Output Operator:
//------------------------------------------

template<typename U>
ostream& operator<<(ostream& outs, const SortedList<U>& l)
{
	print(l._head, outs);
			//Prints the SortedList to the console.
	return outs;
}

template<typename U>
bool operator==(const SortedList<U>& lhs, const SortedList<U>& rhs)
{
	typename SortedList<U>::Iterator walker1 = lhs.Begin();
	typename SortedList<U>::Iterator walker2 = rhs.Begin();

	while (walker1 != lhs.End() && walker2 != rhs.End()) {
		if (walker1->_obj != walker2->_obj)
			return false;

		walker1++;
		walker2++;
	}

	if (walker1 == walker2)
		return true;

	return false;
}


#endif // !SortedList_H