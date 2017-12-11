#pragma once
class Stack
{
private:
	struct SNode
	{
		int item; //������ ��� ����������� �������, ���� �����
		SNode *next;
	};
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