#include "list_test.h"

List<int> getAscendingList()
{	//Returns an ascending linked list.
	List<int> l;

	for (int i = 10; i >= 1; i--)
		l.InsertHead(i * 10);

	return l;
}

List<int> getDecendingList()
{	//Returns an decending linked list.
	List<int> l;

	for (int i = 1; i <= 10; i++)
		l.InsertHead(i * 10);

	return l;
}

List<int> getRandomList()
{	//Returns a linked list of random values
	List<int> l;

	for (int i = 0; i < 10; i++)
		l.InsertHead(rand() % 100 + 1);

	return l;
}

void testInsertHead()
{	//Tests 
	cout << "============ Testing InsertHead() ============" << endl;
	cout << "\\\\Adding multiples of 10 to l: 100 -> 90 -> 80 -> ... 20 -> 10 -> |||"
		<< endl << endl;

	List<int> l = getAscendingList();

	l.Print();

	cout << "\n============ END TEST ========================" << endl;
}

void testInsertAfter()
{
	cout << "============ Testing InsertAfter() ============" << endl;
	cout << "Inserting value at the End of a List:" << endl;
	cout << "//... ->[100]->||| ===> ... ->[100]->[22]->|||" << endl << endl;

	List<int> l;

	l = getAscendingList();

	cout << l << endl;

	l.InsertAfter(22, l.Prev(l.End()));

	l.Print();

	cout << endl << endl << "Inserting value after index 0 of a List:" << endl;
	cout << "//H->[10]->[20]-> ... ===> H->[10]->[999]->[20]-> ..."
		<< endl << endl;

	l.InsertAfter(999, l.Begin());

	l.Print();

	
	cout << "\n============ END TEST ========================" << endl;
}

void testInsertBefore()
{
	cout << "============ Testing InsertBefore() ============" << endl;
	cout << "Inserting value at the Start of a List:" << endl;
	cout << "//H->[10]-> ... ===>H->[22]->[10]-> ..." << endl << endl;

	List<int> l;

	l = getAscendingList();

	l.InsertBefore(22, l.Begin());

	l.Print();

	cout << endl << endl << "Inserting value before index 1 of a List:" << endl;
	cout << "//H->[22]->[10]-> ... ===> H->[22]->[999]->[10]-> ..."
		<< endl << endl;

	l.InsertBefore(999, l.Begin().Next());

	l.Print();

	
	cout << "\n============ END TEST ========================" << endl;
}

void testNext() {
	cout << "============ Testing Next() ============" << endl;
	cout << "Getting Next value at end of a List:"
		<< endl;
	cout << "(l.Next() == nullptr) ==> true(1)"
		<< endl << endl;

	List<int> l;

	l = getAscendingList();

	cout << (l.Next(l.Prev(l.End())) == List<int>::Iterator(nullptr));

	cout << endl << endl << "Getting Next value at index 0 of a List:"
		<< endl;
	cout << "//Next(l.Begin()) ==> 20"
		<< endl << endl;

	cout << *l.Next(l.Begin()) << endl;


	cout << "\n============ END TEST ========================" << endl;
}

void testPrev() {
	cout << "============ Testing Prev() ============" << endl;
	cout << "Getting previous value at Begin of a List:"
		<< endl;
	cout << "previousNode ==> nullptr(00000000)"
		<< endl << endl;

	List<int> l;

	l = getAscendingList();

	cout << (l.Prev(l.Begin()) == List<int>::Iterator(nullptr));

	cout << endl << endl << "Getting previous value at index 1 of a List:"
		<< endl;
	cout << "//previousNode(l, l->_next) ==> 10"
		<< endl << endl;

	cout << *l.Prev(l.Begin().Next()) << endl;

	
	cout << "\n============ END TEST ========================" << endl;
}

void testDelete() {
	cout << "============ Testing Delete() ============" << endl;
	cout << endl << endl << "Deleting Begin of a List:" << endl;
	cout << "//H->[10]->[20]-> ... ==> H->[20]-> ..." << endl << endl;

	List<int> l;

	l = getAscendingList();

	l.Delete(l.Begin());

	l.Print();

	cout << endl << endl << "Deleting Last Node in List:" << endl;
	cout << "//... [90]->[100]->||| ===> ... ->[80]->[90]->|||"
		<< endl << endl;

	l.Delete(l.Prev(l.End()));

	l.Print();

	cout << endl << endl << "Deleting Node at index 1 in List:" << endl;
	cout << "//H->[20]->[30]->[40]-> ... ===> H->[20]->[40]-> ..."
		<< endl << endl;

	l.Delete(l.Begin().Next());

	l.Print();

	
	cout << "\n============ END TEST ========================" << endl;
}

void testOutput()
{
	cout << "============ Testing Print / '<<' ============" << endl;
	cout << endl << "//Adding multiples of 10 to s: 10 -> 20 -> 30 -> ..."
		<< " 90 -> 100 -> |||" << endl << endl;

	List<int> l = getAscendingList();

	cout << "l.Print() ==> ";
	l.Print();

	cout << endl << "'cout << l' ==> ";
	cout << l << endl;


	cout << "\n============ END TEST ========================" << endl
		<< endl;
}

void testSearch()
{
	cout << "============ Testing Search ============" << endl;
	cout << endl << "//Searching for value in list:"
		<< " *l.Search(50) ===> 50";

	List<int> l = getAscendingList();

	cout << *l.Search(50) << endl;

	cout << endl << "Searching for value not in list:";
	cout << endl << "l.Search(55) == Iterator(nullptr) ==> 1";
	
	cout << (l.Search(55) == List<int>::Iterator(nullptr)) << endl;

	cout << "\n============ END TEST ========================" << endl
		<< endl;
}

void testAssignmentOperator()
{
	cout << "============ Testing '=' operator ============" << endl;
	cout << "//copyList(l) ==> H->[10]->[20]-> ... ->[100]->|||"
		<< endl << endl;

	List<int> l = getAscendingList();

	List<int> copy = l;

	copy.Print();

	cout << endl << endl << "Copying Empty List:" << endl;
	cout << "//copyList(l) ==> H->|||" << endl << endl;

	copy = l;

	copy.Print();

	cout << "\n============ END TEST ========================" << endl;
}

void testDeallocate() {
	cout << "============ Testing Deallocation ============" << endl;
	cout << "//l.~List() ==> H->|||"
		<< endl << endl;

	List<int> l = getAscendingList();

	l.~List();

	l.Print();

	cout << "\n============ END TEST ========================" << endl;
}

void testBracketOperator() {
	cout << "============ Testing At ============" << endl;
	cout << "//At(3) ==> [40]->"
		<< endl << endl;

	List<int> l = getAscendingList();

	cout << "at: " << l[3] << endl;

	cout << "\n============ END TEST ========================" << endl;
}

void testInsertSorted()
{
	srand(time(NULL));
	cout << "============ Testing InsertSorted() ============" << endl;
	cout << "Inserting 10 Random Values into list using InsertSorted\n"
		<< "(ascending)" << endl << endl;

	List<int> l;

	for (int i = 0; i < 10; i++)
		l.InsertSorted(rand() % 100 + 1);

	l.Print();

	
	cout << "\n============ END TEST ========================" << endl;
}

void testBegin()
{
	cout << "============ Testing Begin() ============" << endl;
	List<int> l = getAscendingList();

	l.Print();
	cout << "\n\nGetting Beginning of list:"
		<< endl;
	cout << "*l.Begin() ==> 10"
		<< endl << endl;

	cout << *l.Begin();

	cout << "\n============ END TEST ========================" << endl;
}

void testEnd()
{
	cout << "============ Testing End() ============" << endl;
	List<int> l = getAscendingList();

	l.Print();
	cout << "\n\nGetting lastNode of list (to see if end points to the end):"
		<< endl;
	cout << "l.Prev(l.End()) ==> [100]->"
		<< endl << endl;

	cout << *l.Prev(l.End());

	cout << "\n============ END TEST ========================" << endl;
}

void testEmpty()
{
	cout << "============ Testing Empty() ============" << endl;
	List<int> l;
	cout << "\n\nChecking if empty list is empty:"
		<< endl;
	cout << "l.Empty() ==> 1"
		<< endl << endl;

	cout << l.Empty() << endl;

	l = getAscendingList();

	cout << "\n\nChecking if filled list is empty:"
		<< endl;
	cout << "l.Empty() ==> 0"
		<< endl << endl;

	cout << l.Empty() << endl;

	cout << "\n============ END TEST ========================" << endl;
}


void testIterator()
{
	cout << "============ Testing Iterator ============" << endl << endl;
	cout << "Calling the current value of the iterator in the List:";
	cout << endl << "//*iter ==> [10]->"
		<< endl << endl;

	List<int> l = getAscendingList();

	cout << l << endl << endl;

	List<int>::Iterator iter = l.Begin();

	cout << "*iter = " << *iter << endl << endl;

	cout << "Calling the next value of the List using iterator:";
	cout << endl << "//*(iter.Next()) ==> [20]->"
		<< endl << endl;

	cout << l << endl << endl;
	cout << "*(iter.Next()) = " << *(iter.Next()) << endl << endl;

	cout << "Accessing a value inside iterator using '->':";
	cout << endl << "//iter->_obj ==> 10"
		<< endl << endl;

	cout << l << endl << endl;
	cout << "iter->_obj = " << *iter << endl << endl;

	cout << "Calling the prefix and postfix '++' operators:";
	cout << endl << "//otherIter = ++iter; otherIter, iter ==> [20]->, [20]->"
		<< endl << endl;

	iter = l.Begin();

	cout << "Calling otherIter = ++iter" << endl << endl;
	List<int>::Iterator otherIter = ++iter;

	cout << "*otherIter = " << *otherIter << endl;
	cout << "*iter = " << *iter << endl;

	cout << endl << "//otherIter = iter++; otherIter, iter ==> [10]->, [20]->"
		<< endl;

	iter = l.Begin();

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
