#include "Stack.h"
#include <iostream>
#include <stdlib.h>

int main()
{
	Stack a;
	a.push(3);
	a.push(5);
	a.push(1);
	a.amount();
/*	a.find(7);
	a.find(5);
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.amount(); */
	a.print();
	a.sort();
	a.print();
	system("PAUSE");
}