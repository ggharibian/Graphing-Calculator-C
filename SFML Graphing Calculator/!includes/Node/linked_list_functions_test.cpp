#include "linked_list_functions_test.h"

Node<int>* getAscendingList()
{	//Returns an ascending linked list.

	Node<int>* head = nullptr;

	for (int i = 10; i >= 1; i--)
		insertHead(head, i * 10);

	return head;
}

Node<int>* getDecendingList()
{	//Returns an decending linked list.
	Node<int>* head = nullptr;

	for (int i = 1; i <= 10; i++)
		insertHead(head, i * 10);

	return head;
}

Node<int>* getRandomList()
{	//Returns a linked list of random values
	Node<int>* head = nullptr;

	for (int i = 0; i < 10; i++)
		insertHead(head, rand() % 100 + 1);

	return head;
}

//NOTE: All test conditions and outcomes are printed before their respective 
//		calls. For info on what each case does, you may look there.

void testInsertHead()
{	//Tests 
	cout << "============ Testing Insert Head ============" << endl;
	cout << "//Adding multiples of 10 to Head: 100 -> 90 -> 80 -> ... 20 ->"
		<< "10 -> |||"
		<< endl << endl;

	Node<int>* head = getAscendingList();

	print(head);

	clearList(head);
	cout << "\n============ END TEST ========================" << endl;
}

void testSearchList()
{	//Tests 
	cout << "============ Testing Search List ============" << endl;
	cout << "//Searching for value in empty list:" << endl;
	cout << "searchList(head, 10) ==> nullptr(00000000)"
		<< endl << endl;

	Node<int>* head = nullptr;

	cout << searchList(head, 10) << endl;

	cout << endl << endl << "//Searching for value inside list:" << endl;
	cout << "*searchList(head, 50) ==> [50]->" << endl << endl;

	head = getAscendingList();

	cout << *searchList(head, 50) << endl;

	cout << endl << endl << "//Searching for value not in list:" << endl;
	cout << "searchList(head, 110) ==> nullptr(00000000)" << endl << endl;

	cout << searchList(head, 110) << endl;

	clearList(head);
	cout << "\n============ END TEST ========================" << endl;
}

void testInsertAfter()
{
	cout << "============ Testing Insert After ============" << endl;
	cout << "Inserting value at the End of a List:" << endl;
	cout << "//... ->[100]->||| ===> ... ->[100]->[22]->|||" << endl << endl;

	Node<int>* head = getAscendingList();

	insertAfter(head, lastNode(head), 22);

	print(head);

	cout << endl << endl << "Inserting value after index 0 of a List:" << endl;
	cout << "//H->[10]->[20]-> ... ===> H->[10]->[999]->[20]-> ..."
		<< endl << endl;

	insertAfter(head, head, 999);

	print(head);


	cout << "\n============ END TEST ========================" << endl;
}

void testInsertBefore()
{
	cout << "============ Testing Insert Before ============" << endl;
	cout << "Inserting value at the Start of a List:" << endl;
	cout << "//H->[10]-> ... ===>H->[22]->[10]-> ..." << endl << endl;

	Node<int>* head = getAscendingList();

	insertBefore(head, head, 22);

	print(head);

	cout << endl << endl << "Inserting value before index 1 of a List:" << endl;
	cout << "//H->[22]->[10]-> ... ===> H->[22]->[999]->[10]-> ..."
		<< endl << endl;

	insertBefore(head, nextNode(head, head), 999);

	print(head);

	cout << "\n============ END TEST ========================" << endl;
}

void testPreviousNode(){
	cout << "============ Testing Previous Node ============" << endl;
	cout << "Getting previous value at head of a List:"
		<< endl;
	cout << "previousNode ==> nullptr(00000000)"
		<< endl << endl;

	Node<int>* head = getAscendingList();

	cout << previousNode(head, head) << endl;

	cout << endl << endl << "Getting previous value at index 1 of a List:"
		<< endl;
	cout << "//*previousNode(head, head->_next) ==> 10"
		<< endl << endl;

	cout << *previousNode(head, head->_next) << endl;


	cout << "\n============ END TEST ========================" << endl;
}

void testNextNode() {
	cout << "============ Testing Next Node ============" << endl;
	cout << "Getting Next value at end of a List:"
		<< endl;
	cout << "nextNode(head, lastNode(head)) ==> nullptr(00000000)"
		<< endl << endl;

	Node<int>* head = getAscendingList();

	cout << nextNode(head, lastNode(head)) << endl;

	cout << endl << endl << "Getting Next value at index 0 of a List:"
		<< endl;
	cout << "//*nextNode(head, head) ==> 20"
		<< endl << endl;

	cout << *nextNode(head, head) << endl;


	cout << "\n============ END TEST ========================" << endl;
}
void testDeleteNode(){
	cout << "============ Testing Delete() ============" << endl;
	cout << endl << endl << "Deleting Head of a List:" << endl;
	cout << "//H->[10]->[20]-> ... ==> H->[20]-> ..." << endl << endl;

	Node<int>* head = getAscendingList();

	deleteNode(head, head);

	print(head);

	cout << endl << endl << "Deleting Last Node in List:" << endl;
	cout << "//... [90]->[100]->||| ===> ... ->[80]->[90]->|||"
		<< endl << endl;

	deleteNode(head, lastNode(head));

	print(head);

	cout << endl << endl << "Deleting Node at index 1 in List:" << endl;
	cout << "//H->[20]->[30]->[40]-> ... ===> H->[20]->[40]-> ..."
		<< endl << endl;

	deleteNode(head, head->_next);

	print(head);

	cout << "\n============ END TEST ========================" << endl;
}

void testCopyList()
{
	cout << "============ Testing Copy List ============" << endl;
	cout << "//copyList(head) ==> H->[10]->[20]-> ... ->[100]->|||"
		<< endl << endl;

	Node<int>* head = getAscendingList();

	Node<int>* copy = copyList(head);

	print(copy);

	clearList(head);
	clearList(copy);

	cout << endl << endl << "Copying Empty List:" << endl;
	cout << "//copyList(head) ==> H->|||" << endl << endl;

	copy = copyList(head);

	print(copy);

	cout << "\n============ END TEST ========================" << endl;
}

void testClearList(){
	cout << "============ Testing Clear List ============" << endl;
	cout << "//clearList(head) ==> H->|||"
		<< endl << endl;

	Node<int>* head = getAscendingList();

	clearList(head);

	print(head);

	cout << "\n============ END TEST ========================" << endl;
}

void testAt(){
	cout << "============ Testing At ============" << endl;
	cout << "//At(3) ==> [40]->"
		<< endl << endl;

	Node<int>* head = getAscendingList();

	cout << "at: " << at(head, 3) << endl;

	cout << "\n============ END TEST ========================" << endl;
}

void testInsertSorted()
{
	srand(time(NULL));
	cout << "============ Testing Insert Sorted ============" << endl;
	cout << "Inserting 10 Random Values into list using insertSorted\n"
		<< "(ascending)" << endl << endl;

	Node<int>* head = nullptr;

	for (int i = 0; i < 10; i++)
		insertSorted(head, rand() % 100 + 1, true);

	print(head);

	cout << "\n\nInserting 10 Random Values into list using insertSorted\n"
		<< "(decending)" << endl << endl;

	clearList(head);

	for (int i = 0; i < 10; i++)
		insertSorted(head, rand() % 100 + 1, false);

	print(head);

	clearList(head);
	cout << "\n============ END TEST ========================" << endl;
}

void testWhereThisGoes()
{
	cout << "============ Testing WhereThisGoes ============" << endl;
	Node<int>* head = getAscendingList();

	print(head);
	cout << "\n\nGetting location 'whereThisGoes' in the middle of the list\n"
		<< "*whereThisGoes(55) ==>  [60]->" << endl << endl;

	cout << *whereThisGoes(head, 55, true);

	cout << "\nGetting location 'whereThisGoes' in the middle of the list\n"
		<< "*whereThisGoes(0) ==>  [10]->" << endl << endl;

	cout << whereThisGoes(head, 0, true);

	cout << "\nGetting location 'whereThisGoes' in the middle of the list\n"
		<< "whereThisGoes(101) ==>  nullptr" << endl << endl;

	cout << whereThisGoes(head, 101, true);

	cout << "\n============ END TEST ========================" << endl;
}

void testLastNode()
{
	cout << "============ Testing Last Node ============" << endl;
	Node<int>* head = getAscendingList();

	print(head);
	cout << "\n\nGetting Last Node:" << endl;
	cout << "*lastNode ==> 100"
		<< endl << endl;

	cout << *lastNode(head);

	clearList(head);
	cout << "\n============ END TEST ========================" << endl;
}
