#pragma once
#include "Node.h"
class Stack
{
private:
	SNode *top; // ��������� �� ������� �������

public:
	Stack();
	Stack(const Stack&);
	~Stack();

	void push(int);// ���������� ��������
	void pop(); // ��������
	void find(int); // �����
	int amount(); // ����������
	Stack* sort(); // ����������
	void print(); // ������
};