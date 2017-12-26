#pragma once
#include "Node.h"
class Stack
{
private:
	SNode *top; // ��������� �� ������� �������

	int* TurnIntoArr();
	void PutEmBack(int*, int);

	void quick_sortpr(int* arr, int left, int right);

	void merge(int*, int, int, int);
	void merge_sortpr(int*, int, int);

public:
	Stack();
	Stack(const Stack&);
	~Stack();

	void push(int);// ���������� ��������
	void pop(); // ��������
	void find(int); // �����
	int amount(); // ����������
	Stack* sort(); // ����������
	void bottle_sort(); // ��� ����
	void quick_sort(); // � ���
	void merge_sort(); // �� ������ ���, � �����!
	void insertion_sort(); // $$!0&!!!11
	void print(); // ������
};