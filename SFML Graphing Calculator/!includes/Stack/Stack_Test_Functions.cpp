#include "Stack_Test_Functions.h"

Stack<int> getAscendingStack()
{	//Returns an ascending Stack.
	Stack<int> s;

	for (int i = 10; i >= 1; i--)
		s.Push(i * 10);

	return s;
}

Stack<int> getDecendingStack()
{	//Returns an decending Stack.
	Stack<int> s;

	for (int i = 1; i <= 10; i++)
		s.Push(i * 10);

	return s;
}

Stack<int> getRandomStack()
{	//Returns a Stack of random values
	Stack<int> s;

	for (int i = 0; i < 10; i++)
		s.Push(rand() % 100 + 1);

	return s;
}

void testStackCopyConstructor()
{
	cout << "============ Testing Copy Constructor ============" << endl;
	cout << endl << "Copying Filled Stack:" << endl;
	cout << "//Calling 'copy = s'; copy ==> H->[10]->[20]-> ... ->[100]->|||"
		<< endl << endl;

	Stack<int> s = getAscendingStack();

	Stack<int> copy(s);

	cout << "Popping " << s.Pop() << " out of s." << endl << endl;

	cout << "Printing s: " << s << endl;
	cout << "Printing copy: " << copy;

	cout << endl << endl << "Copying Empty Stack:" << endl;
	cout << "//Calling 'otherCopy(s)'; otherCopy ==> H->|||" << endl << endl;

	s.~Stack();

	Stack<int> otherCopy(s);

	cout << "Printing s: " << s << endl;
	cout << "Printing otherCopy: " << otherCopy << endl;

	cout << "\n============ END TEST ========================" << endl 
		<< endl;
}

void testStackAssignmentOperator()
{
	cout << "============ Testing '=' operator ============" << endl;
	cout << endl << "Copying Filled Stack:" << endl;
	cout << "//Calling 'copy = s'; copy ==> H->[10]->[20]-> ... ->[100]->|||"
		<< endl << endl;

	Stack<int> s = getAscendingStack();

	Stack<int> copy = s;

	cout << "Popping " << s.Pop() << " out of s." << endl << endl;

	cout << "Printing s: " << s << endl;
	cout << "Printing copy: " << copy;

	cout << endl << endl << "Copying Empty Stack:" << endl;
	cout << "//Calling 'copy = s'; copy ==> H->|||" << endl << endl;

	s.~Stack();

	copy = s;

	cout << "Printing s: " << s << endl;
	cout << "Printing copy: " << copy;

	cout << "\n============ END TEST ========================" << endl 
		<< endl;
}

void testStackDeallocate() {
	cout << "============ Testing Deallocation ============" << endl 
		<< endl;
	cout << "//Calling s.~Stack(); H->[10]->[20]->... ==> H->|||"
		<< endl << endl;

	Stack<int> s = getAscendingStack();

	cout << s << endl << endl;

	s.~Stack();

	cout << s << endl;

	cout << "\n============ END TEST ========================" << endl 
		<< endl;
}

void testStackPush()
{	//Tests 
	cout << "============ Testing Push() ============" << endl;
	cout << endl <<"//Adding multiples of 10 to s: 10 -> 20 -> 30 -> ... 90 -> 100 -> |||"
		<< endl << endl;

	Stack<int> s;

	cout << s << endl << endl;

	for (int i = 10; i >= 1; i--)
		cout << s.Push(i * 10)->_obj << " has been pushed." << endl;

	cout << endl << s << endl;

	cout << "\n============ END TEST ========================" << endl 
		<< endl;
}

void testStackPop() {
	cout << "============ Testing Pop() ============" << endl;
	cout << endl << "Popping all values from a Stack:" << endl;
	cout << "//H->[10]->[20]->[30]->... ==> H->|||" << endl << endl;

	Stack<int> s;

	s = getAscendingStack();

	cout << s << endl << endl;

	while (!s.Empty())
		cout << s.Pop() << " has been popped." << endl;

	cout << endl << s << endl;

	
	cout << "\n============ END TEST ========================" << endl 
		<< endl;
}

void testStackTop()
{
	cout << "============ Testing Top ============" << endl;
	cout << endl << "Accessing Top of filled Stack:" << endl;
	cout << "//Calling s.Top() ==> 100"
		<< endl << endl;

	Stack<int> s = getDecendingStack();

	cout << s << endl << endl;

	cout << "s.Top() = " << s.Top() << endl;

	cout << "\n============ END TEST ========================" << endl 
		<< endl;
}

void testStackEmpty()
{
	cout << "============ Testing Empty ============" << endl;
	cout << endl << "Checking if filled Stack is empty:" << endl;
	cout << "//Calling s.Empty() ==> 0 (false)"
		<< endl << endl;

	Stack<int> s = getAscendingStack();

	cout << s << endl << endl;
	cout << "s.Empty() = " << s.Empty() << endl;

	s.~Stack();

	cout << endl << endl << "Checking if empty Stack is empty:" << endl;
	cout << "//Calling s.Empty() ==> 1 (true)"
		<< endl << endl;

	cout << s << endl << endl;
	cout << "s.Empty() = " << s.Empty() << endl;

	cout << "\n============ END TEST ========================" << endl 
		<< endl;
}

void testStackOutput()
{	//Tests 
	cout << "============ Testing Print / '<<' ============" << endl;
	cout << endl << "//Adding multiples of 10 to s: 10 -> 20 -> 30 -> ..."
		<< " 90 -> 100 -> |||" << endl << endl;

	Stack<int> s = getAscendingStack();

	cout << "s.Print() ==> ";
	s.Print();

	cout << endl << "'cout << s' ==> ";
	cout << s << endl;


	cout << "\n============ END TEST ========================" << endl
		<< endl;
}

void testStackIterator()
{
	cout << "============ Testing Stack Iterator ============" << endl 
		<< endl;
	cout << "Calling the current value of the iterator in the Stack:";
	cout << endl << "//*iter ==> [10]->"
		<< endl << endl;

	Stack<int> s = getAscendingStack();

	cout << s << endl << endl;

	Stack<int>::Iterator iter = s.Begin();

	cout << "*iter = " << *iter << endl << endl;

	cout << "Calling the next value of the Stack using iterator:";
	cout << endl << "//*(iter.Next()) ==> [20]->"
		<< endl << endl;

	cout << s << endl << endl;
	cout << "*(iter.Next()) = " << *(iter.Next()) << endl << endl;

	cout << "Accessing a value inside iterator using '->':";
	cout << endl << "//iter->_obj ==> 10"
		<< endl << endl;

	cout << s << endl << endl;
	cout << "iter->_obj = " << iter->_obj << endl << endl;

	cout << "Calling the prefix and postfix '++' operators:";
	cout << endl << "//otherIter = ++iter; otherIter, iter ==> [20]->, [20]->"
		<< endl << endl;

	iter = s.Begin();

	cout << "Calling otherIter = ++iter" << endl << endl;
	Stack<int>::Iterator otherIter = ++iter;

	cout << "*otherIter = " << *otherIter << endl;
	cout << "*iter = " << *iter << endl;

	cout << endl << "//otherIter = iter++; otherIter, iter ==> [10]->, [20]->"
		<< endl;

	iter = s.Begin();

	cout << endl <<"Calling otherIter = iter++" << endl << endl;
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

	cout << "\n============ END TEST ========================" << endl 
		<< endl;
}
