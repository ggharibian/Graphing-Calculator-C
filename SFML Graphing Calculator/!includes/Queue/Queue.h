#ifndef QUEUE_H
#define QUEUE_H
#include "../List/List.h"

template<typename T>
class Queue {
public:

	class Iterator {
	public:
		friend class Queue;

		Iterator(typename List<T>::Iterator ptr = typename List<T>::Iterator(nullptr)) : _ptr(ptr) {}

		Iterator Next() {
			return Iterator(_ptr.Next());
		}

		T& operator *() {		//Accesses the object at this location in
									//the Queue.
			return *_ptr;
		}

		const T operator *() const {
			return *_ptr;
		}

		typename List<T>::Iterator operator ->() {	//Accesses the elements 
													//of the Object at this
													//Iterator.
			return _ptr;
		}

		const typename List<T>::Iterator operator ->() const {
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

			_ptr = _ptr.Next();

			return *this;
		}

		friend bool operator !=(const Iterator& left, const Iterator& right) {
			return left._ptr != right._ptr;
		}

	private:
		typename List<T>::Iterator _ptr; //Traces a Iterator location of a 
										 //Node in a List object.
	};

	//Constructor
	Queue();

	//Big Three Functions
	Queue(const Queue<T>& copyThis);
	Queue<T>& operator =(const Queue<T>& rhs);

	//Push Function
	Queue<T>::Iterator Push(T item);

	//Pop Function
	T Pop();

	//Print Function
	void Print() const;

	//Front Function
	T Front();

	//Traversal Functions
	Queue<T>::Iterator Begin();
	Queue<T>::Iterator End();

	//Empty Function
	bool Empty();

	//Output Operator
	template<typename U>
	friend ostream& operator <<(ostream& outs, const Queue<U>& l);

private:

	
	List<T> _queue;	//List object representing the Queue

	typename List<T>::Iterator _rear;	//Iterator at the end of the Queue


};

//------------------------------------------
//Constructor:
//------------------------------------------

template<typename T>
Queue<T>::Queue() : _rear(_queue.Begin())
{
	//Intentionally Blank.
}

//------------------------------------------
//Big Three Functions
//------------------------------------------

template<typename T>
Queue<T>::Queue(const Queue<T>& copyThis)
{
	_queue = copyThis._queue;
	_rear = _queue.lastValue();
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs)
{

	if (this->_queue == rhs._queue)
		return *this;
	//Checking for self reference.

	_queue = rhs._queue;
	_rear = _queue.lastValue();

	return *this;

}

//------------------------------------------
//Insertion Functions:
//------------------------------------------

template<typename T>
typename Queue<T>::Iterator Queue<T>::Push(T item)
{
	if (_queue.Empty())
		_rear = _queue.InsertHead(item);
			//If the queue is empty, we insert at the head to avoid getting
			//an error in the InsertAfter function
	else
		_rear = _queue.InsertAfter(item, _rear);
			//Inserts the item at the end of the Queue.

	return Iterator(_rear);
}

//------------------------------------------
//Delete Function:
//------------------------------------------

template<typename T>
T Queue<T>::Pop()
{
	return _queue.Delete(_queue.Begin());
	//Deletes the node at the head of the Queue.

	if (Empty())
		_rear = List<T>::Iterator(nullptr);

}

//------------------------------------------
//Print Function:
//------------------------------------------

template<typename T>
void Queue<T>::Print() const
{
	_queue.Print();
	//Prints the Queue to the console.
}

//------------------------------------------
//Accessor Functions:
//------------------------------------------

template<typename T>
T Queue<T>::Front() {
	return *_queue.Begin();
}

template<typename T>
typename Queue<T>::Iterator Queue<T>::Begin()
{
	return Queue::Iterator(_queue.Begin());
}

template<typename T>
typename Queue<T>::Iterator Queue<T>::End()
{
	return Iterator(_queue.End());
}

template<typename T>
bool Queue<T>::Empty()
{
	return _queue.Empty();
}

//------------------------------------------
//Output Operator:
//------------------------------------------

template<typename U>
ostream& operator<<(ostream& outs, const Queue<U>& q)
{
	outs << q._queue;

	return outs;
}


#endif // !QUEUE_H