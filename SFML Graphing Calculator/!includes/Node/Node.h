#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

template<typename T>
struct Node {
	T _obj;
	Node<T>* _next;

	Node(const T& obj = T(), Node<T>* next = nullptr) :
		_obj(obj), _next(next){}

	friend ostream& operator<<(ostream& outs, const Node<T> n) {
		outs << "[" << n._obj << "]->";
		return outs;
	}

};
#endif // !NODE_H
