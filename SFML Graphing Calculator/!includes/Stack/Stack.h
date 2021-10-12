#ifndef STACK_H
#define STACK_H
#include "../Node/Linked_List_Functions.h"

template<typename T>
class Stack {
public:

	class Iterator {
	public:
		friend class Stack;

		Iterator(Node<T>* ptr = nullptr): _ptr(ptr){}

		Iterator Next() {
			return Iterator(_ptr->_next);
		}

		Node<T>& operator *() {	//Accesses the object at this location in
								//the Stack.
			assert(_ptr);
			return *_ptr;
		}

		const Node<T> operator *() const{
			assert(_ptr);
			return *_ptr;
		}

		Node<T>* operator ->() {	//Accesses the elements 
									//of the Object at this
									//Iterator.
			assert(_ptr);
			return _ptr;
		}

		const Node<T>* operator ->() const{
			assert(_ptr);
			return _ptr;
		}

		friend Iterator operator ++(Iterator& it, int unused) {
			//prefix

			Iterator old;
					//Holds the old value to return at the end.
			old = it;
			it = it.Next();
			return old;
		}

		Iterator& operator ++() {
			//postfix

			*this = (*this).Next();
			return *this;
		}

		friend bool operator !=(const Iterator& left, const Iterator& right) {
			return left._ptr != right._ptr;
		}

	private:
		Node<T>* _ptr; //Traces a Node location in a Stack object.
	};

	//Constructor
	Stack();

	//Big Three Functions
	~Stack();
	Stack(const Stack<T>& copyThis);
	Stack<T>& operator =(const Stack<T>& rhs);

	//Push Function
	Stack<T>::Iterator Push(T item);

	//Pop Function
	T Pop();

	//Print Function
	void Print() const;

	//Top Function
	T Top();

	//Accessor Functions
	Stack<T>::Iterator Begin();
	Stack<T>::Iterator End();

	//Empty Function
	bool Empty();

	//Output Operator
	template<typename U>
	friend ostream& operator <<(ostream& outs, const Stack<U>& l);

private:

	//The top of the Stack.
	Node<T>* _top;


};

	//Note: Check the "Linked_Stack_Functions.h" file for documentation for 
	//further info helper functions.

//------------------------------------------
//Constructor:
//------------------------------------------

template<typename T>
Stack<T>::Stack(): _top(nullptr)
{
	//Intentionally Blank.
}

//------------------------------------------
//Big Three Functions
//------------------------------------------

template<typename T>
Stack<T>::~Stack()
{	//Deallocates the Stack using the clearList() function.

	clearList(_top);
}

template<typename T>
Stack<T>::Stack(const Stack<T>& copyThis)
{	//Copies the Stack using thr copyList() function.

	_top = copyList(copyThis._top);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& rhs)
{

	if (this->_top == rhs._top)
		return *this;
			//Checking for self reference.

	clearList(_top);
			//Deletes old Stack

	_top = copyList(rhs._top);
			//Creates a new copy of the Stack.

	return *this;

}

//------------------------------------------
//Insertion Functions:
//------------------------------------------

template<typename T>
typename Stack<T>::Iterator Stack<T>::Push(T item)
{
	return Iterator(insertHead(_top, item));
			//Inserts the item at the Top of the Stack.
}

//------------------------------------------
//Delete Function:
//------------------------------------------

template<typename T>
T Stack<T>::Pop()
{
	return deleteNode(_top, _top);
			//Deletes removes and returns item at the top of the Stack.
}

//------------------------------------------
//Print Function:
//------------------------------------------

template<typename T>
void Stack<T>::Print() const
{
	print(_top);
			//Prints the Stack to the console.
}

//------------------------------------------
//Traversal Functions:
//------------------------------------------

template<typename T>
T Stack<T>::Top() {
	assert(_top != nullptr);

	return _top->_obj;
			//Returns the Top element of the stack.
}

template<typename T>
typename Stack<T>::Iterator Stack<T>::Begin()
{
	return Iterator(_top);
}

template<typename T>
typename Stack<T>::Iterator Stack<T>::End()
{
	return Iterator(nullptr);
}

//------------------------------------------
//Empty Operator:
//------------------------------------------

template<typename T>
bool Stack<T>::Empty()
{
	return _top == nullptr;
}

//------------------------------------------
//Output Operator:
//------------------------------------------

template<typename U>
ostream& operator<<(ostream& outs, const Stack<U>& l)
{
	print(l._top, outs);
			//Prints the Stack to the console.
	return outs;
}


#endif // !STACK_H