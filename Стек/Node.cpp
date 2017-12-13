#include "Node.h"
#include <stdlib.h>

SNode::SNode()
{
	next = NULL;
}

int SNode::GetItem()
{
	return item;
}

SNode* SNode::GetNext()
{
	return next;
}

void SNode::PutNext(SNode* n)
{
	next = n;
}

void SNode::PutItem(int value)
{
	item = value;
}