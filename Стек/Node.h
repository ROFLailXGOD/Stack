#pragma once
class SNode
{
private:
	int item;
	SNode *next;
public:
	SNode();
	int GetItem();
	SNode* GetNext();
	void PutNext(SNode*);
	void PutItem(int);
};