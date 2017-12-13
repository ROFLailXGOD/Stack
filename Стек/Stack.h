#pragma once
#include "Node.h"
class Stack
{
private:
	SNode *top; // Указатель на верхний элемент

public:
	Stack();
	Stack(const Stack&);
	~Stack();

	void push(int);// Добавление элемента
	void pop(); // Удаление
	void find(int); // Поиск
	int amount(); // Количество
	Stack* sort(); // Сортировка
	void print(); // Печать
};