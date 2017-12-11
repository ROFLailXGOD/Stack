#pragma once
class Stack
{
private:
	struct SNode
	{
		int item; //Меняем тип хранящегося объекта, если нужно
		SNode *next;
	};
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