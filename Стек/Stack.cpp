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
//	std::cout << "Amount of items in stack: " << count << "\n";
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

int* Stack::TurnIntoArr()
{
	int* arr = new int[amount()];
	int i = 0;
	for (SNode *ptr = top; ptr != NULL; ptr = ptr->GetNext())
	{
		arr[i] = ptr->GetItem();
		++i;
	}
	return arr;
}

void Stack::PutEmBack(int* arr, int size)
{
	while (top != NULL)
	{
		pop();
	}
	for (int i = 0; i < size; ++i)
	{
		push(arr[i]);
	}
	delete [] arr;
}

void Stack::bottle_sort()
{
	int tmp = 0;
	int flag = 1;
	int count = 0;
	int* arr = TurnIntoArr();
	int size = amount();

	while (flag)
	{
		flag = 0;
		for (int i = 0; i < (size - 1); ++i)
		{
			if (arr[i] < arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				++count;
				flag = 1;
			}
		}
	}
	PutEmBack(arr, size);
}

void Stack::quick_sortpr(int* arr, int left, int right)
{
	int l = left;
	int r = right;
	int op = arr[(l + r) / 2];
	int tmp = 0;
	while (l <= r)
	{
		while (arr[l] > op)
		{
			++l;
		}
		while (arr[r] < op)
		{
			--r;
		}
		if (l <= r)
		{
			tmp = arr[l];
			arr[l] = arr[r];
			arr[r] = tmp;
			++l;
			--r;
		}
	}

	if (left < r)
	{
		quick_sortpr(arr, left, r);
	}

	if (right > l)
	{
		quick_sortpr(arr, l, right);
	}
	return;
}

void Stack::quick_sort()
{
	int* arr = TurnIntoArr();
	int size = amount();
	quick_sortpr(arr, 0, size - 1);
	PutEmBack(arr, size);
}

void Stack::merge(int* arr, int first, int mid, int last)
{
	int* tempArr = new int[amount()];

	int firstl = first;
	int lastl = mid;
	int first2 = mid + 1;
	int last2 = last;
	int index = firstl;

	for (; (firstl <= lastl) && (first2 <= last2); ++index)
	{

		if (arr[firstl] > arr[first2])
		{
			tempArr[index] = arr[firstl];
			++firstl;
		}
		else
		{
			tempArr[index] = arr[first2];
			++first2;
		}
	} 
	for (; firstl <= lastl; ++firstl, ++index)
	{
		tempArr[index] = arr[firstl];
	}

	for (; first2 <= last2; ++first2, ++index)
	{
		tempArr[index] = arr[first2];
	}
	for (index = first; index <= last; ++index)
	{
		arr[index] = tempArr[index];
	}
	delete [] tempArr;
}

void Stack::merge_sortpr(int* arr, int first, int last)

{
	if (first < last)
	{
		int mid = (first + last) / 2;

		merge_sortpr(arr, first, mid);
		merge_sortpr(arr, mid + 1, last);
		merge(arr, first, mid, last);
	}
}

void Stack::merge_sort()
{
	int* arr = TurnIntoArr();
	int size = amount();
	merge_sortpr(arr, 0, size - 1);
	PutEmBack(arr, size);
}

void Stack::insertion_sort()
{
	int* arr = TurnIntoArr();
	int size = amount();
	for (int unsorted = 1; unsorted < size; ++unsorted)
	{
		int nextltem = arr[unsorted];
		int sort = unsorted;
		for (; (sort > 0) && (arr[sort-1] < nextltem); --sort)
		{
			arr[sort] = arr[sort-1];
		}
		arr[sort] = nextltem;
	}
	PutEmBack(arr, size);
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