#include "Stack.h"
#include <stdlib.h>
#include <iostream>

Stack::Stack()
{
	top == NULL;
}

Stack::Stack(const Stack& prevStack)
{
	if (prevStack.top == NULL)
	{
		top = NULL;
	}
	else
	{
		top = new SNode;
		top->item = prevStack.top->item;
		SNode *newPtr = top;
		for (SNode *prevPtr = prevStack.top->next; prevPtr != NULL; prevPtr = prevPtr->next)
		{
			newPtr->next = new SNode;
			newPtr = newPtr->next;
			newPtr->item = prevPtr->item;
		}
		newPtr->next = NULL;
	}
}

Stack::~Stack()
{
	while (top != NULL)
	{
		pop();
	}
}

void Stack::push(int newitem)
{
	SNode *NewStack = new SNode;
	if (NewStack == NULL)
	{
		std::cout << "Memory allocation is impossible" << "\n";
	}
	else
	{
		NewStack->item = newitem;
		NewStack->next = top;
		top = NewStack;
	}
}

void Stack::pop()
{
	if (top == NULL)
	{
		std::cout << "Stack is empty" << "\n";
	}
	else
	{
		SNode *tmp = top;
		top = top->next;
		tmp->next = NULL;
		delete tmp;
	}
}

void Stack::find(int item)
{
	SNode *key = top;
	while (key)
	{
		if (key->item == item)
		{
			std::cout << "Item " << item << " is found" << "\n";
			break;
		}
		key = key->next;
	}
	if (key == NULL)
	{
		std::cout << "Item " << item << " isn't found" << "\n";
	}
//	return key;
}

void Stack::amount()
{
	SNode *ptr = top;
	int count = 0;
	while (ptr)
	{
		++count;
		ptr = ptr->next;
	}
	std::cout << "Amount of items in stack: " << count << "\n";
}

void Stack::sort()
{
	Stack tmp;
	Stack *res = new Stack();
	int max;
	SNode *aPtr;
	SNode *bPtr;
	while (true)
	{
		if (top != NULL)
		{
			aPtr = top;
			max = aPtr->item;
			tmp.push(aPtr->item);
			pop();
			aPtr = top;
		}
		else
		{
			break;
		}
		while (aPtr != NULL)
		{
			if (aPtr->item > max)
			{
				max = aPtr->item;
			}
			tmp.push(aPtr->item);
			pop();
			aPtr = top;
		}

		bPtr = tmp.top;

		while (bPtr != NULL)
		{
			if (bPtr->item == max)
			{
				res->push(bPtr->item);
			}
			else
			{
				push(bPtr->item);
			}
			tmp.pop();
			bPtr = tmp.top;
		}
	}
//	top = res->top;
//	return *res;
}

void Stack::print()
{
	SNode *ptr = top;
	std::cout << "Stack: ";
	while (ptr != NULL)
	{
		std::cout << ptr->item << " ";
		ptr = ptr->next;
	}
	std::cout << "\n";
}