#include "EdgeDblList.h"

EdgeDblList::~EdgeDblList()
{
}

Edge * EdgeDblList::Search(const int & x, int d)
{
	int i = x;
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

bool EdgeDblList::Insert(int i, const int & x, int d)
{
	Edge * current = Search();
	Edge *newNode = new Edge(num,x);
	newNode->lLink = current->lLink;
	current->lLink = newNode;
	newNode->lLink->rlink = newNode;
	newNode->rLink = current;
}

bool EdgeDblList::Remove(int i, int & x, int d)
{
	return false;
}
