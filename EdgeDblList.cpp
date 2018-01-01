#include "EdgeDblList.h"

EdgeDblList::~EdgeDblList()
{
}

Edge * EdgeDblList::Locate(int i, int d)
{
	if (i<0) return NULL;
	if (first->rLink == first || i == 0) return first;//空双向循环链表或i为0
	Edge *current;//遍历指针
	if (d == 0) current = first->lLink;//前驱方向， 遍历指针初始为尾结点
	else current = first->rLink;//后继方向， 遍历指针初始为首元结点
	for (int j = 1; j<i; j++)
		if (current == first) break; //遍历结束
		else if (d == 0) current = current->lLink;
		else current = current->rLink;
		if (current != first) return current;
		else return NULL;
}

bool EdgeDblList::Insert(int i,  Edge * x, int d)
{
	Edge * current = Locate(i,d);
	Edge * newNode = x;
	newNode->lLink = current->lLink;
	current->lLink = newNode;
	newNode->lLink->rLink = newNode;
	newNode->rLink = current;
	return true;
}

bool EdgeDblList::Remove(int i, Edge* x, int d)
{
	Edge * current = Locate(i,d);
	current->rLink->lLink = current->lLink;
	current->lLink->rLink = current->rLink;
	x = current;
	delete current;
	return true;
}

