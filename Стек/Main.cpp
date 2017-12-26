#include "Stack.h"
#include <iostream>
#include <stdlib.h>

int main()
{
	Stack *a = new Stack();
	a->push(3);
	a->push(5);
	a->push(1);
	a->push(2);
	a->push(3);
	a->push(4);
	a->push(6);
	a->push(0);
	a->push(-1);
	Stack *b = new Stack(*a);
	Stack *c = new Stack(*a);
	Stack *d = new Stack(*a);
	Stack *e = new Stack(*a);
	std::cout << "Amount of elements in queue is " << a->amount() << "\n";
	a->find(7);
	a->find(5);
/*	a->pop();
	a->pop();
	a->pop();
	a->pop();
	a->pop();
	a->pop();
	a->pop();
	a->pop();
	a->pop();
	a->pop();
	a->pop();
	a->pop(); */
	std::cout << "Amount of elements in queue is " << a->amount() << "\n";
	a->print();

	a = a->sort();
	b->quick_sort();
	c->merge_sort();
	d->bottle_sort();
	e->insertion_sort();

	a->print();
	system("PAUSE");
}