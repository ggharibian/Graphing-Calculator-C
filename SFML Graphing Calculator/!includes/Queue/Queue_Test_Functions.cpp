#include "Queue_Test_Functions.h"

Queue<int> getAscendingQueue()
{	//Returns an ascending Queue.
	Queue<int> q;

	for (int i = 1; i <= 10; i++)
		q.Push(i * 10);

	return q;
}

Queue<int> getDecendingQueue()
{	//Returns an decending Queue.
	Queue<int> q;

	for (int i = 10; i >= 1; i--)
		q.Push(i * 10);

	return q;
}

Queue<int> getRandomQueue()
{	//Returns a Queue of random values
	Queue<int> q;

	for (int i = 0; i < 10; i++)
		q.Push(rand() % 100 + 1);

	return q;
}

void testQueueCopyConstructor()
{
	cout << "============ Testing Copy Constructor ============" << endl;
	cout << endl << "Copying Filled Queue:" << endl;
	cout << "//Calling 'copy = q'; copy ==> H->[10]->[20]-> ... ->[100]->|||"
		<< endl << endl;

	Queue<int> q = getAscendingQueue();

	Queue<int> copy(q);

	cout << "Popping " << q.Pop() << " out of q." << endl << endl;

	cout << "Printing s: " << q << endl;
	cout << "Printing copy: " << copy;

	cout << endl << endl << "Copying Empty Queue:" << endl;
	cout << "//Calling 'otherCopy(s)'; otherCopy ==> H->|||" << endl << endl;

	q.~Queue();

	Queue<int> otherCopy(q);

	cout << "Printing s: " << q << endl;
	cout << "Printing otherCopy: " << otherCopy << endl;

	cout << "\n============ END TEST ========================" << endl << endl;
}

void testQueueAssignmentOperator()
{
	cout << "============ Testing '=' operator ============" << endl;
	cout << endl << "Copying Filled Queue:" << endl;
	cout << "//Calling 'copy = q'; copy ==> H->[10]->[20]-> ... ->[100]->|||"
		<< endl << endl;

	Queue<int> q = getAscendingQueue();

	Queue<int> copy = q;

	cout << "Popping " << q.Pop() << " out of q." << endl << endl;

	cout << "Printing s: " << q << endl;
	cout << "Printing copy: " << copy;

	cout << endl << endl << "Self Reference:" << endl;
	cout << "//Calling 'q =  s'; q ==> H->[20]->[30]-> ... ->[100]->|||"
		<< endl << endl;

	q = q;

	cout << "Printing s: " << q << endl;

	cout << endl << endl << "Copying Empty Queue:" << endl;
	cout << "//Calling 'copy = q'; copy ==> H->|||" << endl << endl;

	q.~Queue();

	copy = q;

	cout << "Printing s: " << q << endl;
	cout << "Printing copy: " << copy;

	

	cout << "\n============ END TEST ========================" << endl << endl;
}

void testQueueDeallocate() {
	cout << "============ Testing Deallocation ============" << endl << endl;
	cout << "//Calling q.~Queue(); H->[10]->[20]->... ==> H->|||"
		<< endl << endl;

	Queue<int> q = getAscendingQueue();

	cout << q << endl << endl;

	q.~Queue();

	cout << q << endl;

	cout << "\n============ END TEST ========================" << endl << endl;
}

void testQueuePush()
{	//Tests 
	cout << "============ Testing Push() ============" << endl;
	cout << endl <<"//Adding multiples of 10 to s: 10 -> 20 -> 30 -> ... 90 -> 100 -> |||"
		<< endl << endl;

	Queue<int> q;

	cout << q << endl << endl;

	for (int i = 10; i >= 1; i--)
		cout << *q.Push(i * 10) << " has been pushed." << endl;

	cout << endl << q << endl;

	cout << "\n============ END TEST ========================" << endl << endl;
}

void testQueuePop() {
	cout << "============ Testing Pop() ============" << endl;
	cout << endl << "Popping all values from a Queue:" << endl;
	cout << "//H->[10]->[20]->[30]->... ==> H->|||" << endl << endl;

	Queue<int> q;

	q =  getAscendingQueue();

	cout << q << endl << endl;

	while (!q.Empty())
		cout << q.Pop() << " has been popped." << endl;

	cout << endl << q << endl;

	
	cout << "\n============ END TEST ========================" << endl << endl;
}

void testQueueFront()
{
	cout << "============ Testing Front ============" << endl;
	cout << endl << "Accessing Front of filled Queue:" << endl;
	cout << "//Calling q.Front() ==> 100"
		<< endl << endl;

	Queue<int> q = getDecendingQueue();

	cout << q << endl << endl;

	cout << "q.Front() = " << q.Front() << endl;

	cout << "\n============ END TEST ========================" << endl << endl;
}

void testQueueEmpty()
{
	cout << "============ Testing Empty ============" << endl;
	cout << endl << "Checking if filled Queue is empty:" << endl;
	cout << "//Calling q.Empty() ==> 0 (false)"
		<< endl << endl;

	Queue<int> q = getAscendingQueue();

	cout << q << endl << endl;
	cout << "q.Empty() = " << q.Empty() << endl;

	q.~Queue();

	cout << endl << endl << "Checking if empty Queue is empty:" << endl;
	cout << "//Calling q.Empty() ==> 1 (true)"
		<< endl << endl;

	cout << q << endl << endl;
	cout << "q.Empty() = " << q.Empty() << endl;

	cout << "\n============ END TEST ========================" << endl << endl;
}

void testQueueOutput()
{	//Tests 
	cout << "============ Testing Print / '<<' ============" << endl;
	cout << endl << "//Adding multiples of 10 to s: 10 -> 20 -> 30 -> ... 90 -> 100 -> |||"
		<< endl << endl;

	Queue<int> q = getAscendingQueue();

	cout << "q.Print() ==> ";
	q.Print();

	cout << endl << "'cout << s' ==> ";
	cout << q << endl;


	cout << "\n============ END TEST ========================" << endl << endl;
}

void testQueueIterator()
{
	cout << "============ Testing Queue Iterator ============" << endl << endl;
	cout << "Calling the current value of the iterator in the Queue:";
	cout << endl << "//*iter ==> [10]->"
		<< endl << endl;

	Queue<int> q = getAscendingQueue();

	cout << q << endl << endl;

	Queue<int>::Iterator iter = q.Begin();

	cout << "*iter = " << *iter << endl << endl;

	cout << "Calling the next value of the Queue using iterator:";
	cout << endl << "//*(iter.Next()) ==> [20]->"
		<< endl << endl;

	cout << q << endl << endl;
	cout << "*(iter.Next()) = " << *(iter.Next()) << endl << endl;

	cout << "Accessing a value inside iterator using '->':";
	cout << endl << "//iter->_obj ==> 10"
		<< endl << endl;

	cout << q << endl << endl;
	cout << "iter->_obj = " << *iter << endl << endl;

	cout << "Calling the prefix and postfix '++' operators:";
	cout << endl << "//otherIter = ++iter; otherIter, iter ==> [20]->, [20]->"
		<< endl << endl;

	iter = q.Begin();

	cout << "Calling otherIter = ++iter" << endl << endl;
	Queue<int>::Iterator otherIter = ++iter;

	cout << "*otherIter = " << *otherIter << endl;
	cout << "*iter = " << *iter << endl;

	cout << endl << "//otherIter = iter++; otherIter, iter ==> [10]->, [20]->"
		<< endl;

	iter = q.Begin();

	cout << endl << "Calling otherIter = iter++" << endl;
	otherIter = iter++;

	cout << "*otherIter = " << *otherIter << endl;
	cout << "*iter = " << *iter << endl;

	cout << endl << "Calling the '!=' operators:";
	cout << endl << "//otherIter != iter ==> 1 (true) "
		<< endl << endl;

	cout << "otherIter != iter: " << (otherIter != iter) << endl;

	cout << endl << "//otherIter != otherIter ==> 0 (false) "
		<< endl << endl;

	cout << "otherIter != otherIter: " << (otherIter != otherIter) << endl;

	cout << "\n============ END TEST ========================" << endl << endl;
}