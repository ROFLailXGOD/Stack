#pragma once
#include "Node.h"
class Stack
{
private:
	SNode *top; // Указатель на верхний элемент

	int* TurnIntoArr();
	void PutEmBack(int*, int);

	void quick_sortpr(int* arr, int left, int right);

	void merge(int*, int, int, int);
	void merge_sortpr(int*, int, int);

public:
	Stack();
	Stack(const Stack&);
	~Stack();

	void push(int);// Добавление элемента
	void pop(); // Удаление
	void find(int); // Поиск
	int amount(); // Количество
	Stack* sort(); // Сортировка
	void bottle_sort(); // Ещё одна
	void quick_sort(); // И ещё
	void merge_sort(); // ДА ХВАТИТ УЖЕ, Я УСТАЛ!
	void insertion_sort(); // $$!0&!!!11
	void print(); // Печать
};