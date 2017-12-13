#include "Stack.h"
#include "Node.h"
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
		top = new SNode();
		top->PutItem(prevStack.top->GetItem());
		SNode *newPtr = top;
		for (SNode *prevPtr = prevStack.top->GetNext(); prevPtr != NULL; prevPtr = prevPtr->GetNext())
		{
			newPtr->PutNext(new SNode);
			newPtr = newPtr->GetNext();
			newPtr->PutItem(prevPtr->GetItem());
		}
		newPtr->PutNext(NULL);
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
		NewStack->PutItem(newitem);
		NewStack->PutNext(top);
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
		top = top->GetNext();
		tmp->PutNext(NULL);
		delete tmp;
	}
}

void Stack::find(int item)
{
	SNode *key = top;
	while (key)
	{
		if (key->GetItem() == item)
		{
			std::cout << "Item " << item << " is found" << "\n";
			break;
		}
		key = key->GetNext();
	}
	if (key == NULL)
	{
		std::cout << "Item " << item << " isn't found" << "\n";
	}
}

int Stack::amount()
{
	SNode *ptr = top;
	int count = 0;
	while (ptr)
	{
		++count;
		ptr = ptr->GetNext();
	}
	std::cout << "Amount of items in stack: " << count << "\n";
	return count;
}

Stack* Stack::sort()
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
			max = aPtr->GetItem();
			tmp.push(aPtr->GetItem());
			pop();
			aPtr = top;
		}
		else
		{
			break;
		}
		while (aPtr != NULL)
		{
			if (aPtr->GetItem() > max)
			{
				max = aPtr->GetItem();
			}
			tmp.push(aPtr->GetItem());
			pop();
			aPtr = top;
		}

		bPtr = tmp.top;

		while (bPtr != NULL)
		{
			if (bPtr->GetItem() == max)
			{
				res->push(bPtr->GetItem());
			}
			else
			{
				push(bPtr->GetItem());
			}
			tmp.pop();
			bPtr = tmp.top;
		}
	}
	return res;
}

void Stack::print()
{
	SNode *ptr = top;
	std::cout << "Stack: ";
	if (!ptr)
	{
		std::cout << "empty";
	}
	else
	{
		while (ptr != NULL)
		{
			std::cout << ptr->GetItem() << " ";
			ptr = ptr->GetNext();
		}
	}
	std::cout << "\n";
}