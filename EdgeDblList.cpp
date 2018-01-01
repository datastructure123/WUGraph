#include "EdgeDblList.h"

EdgeDblList::~EdgeDblList()
{
}

Edge * EdgeDblList::Locate(int i, int d)
{
	if (i<0) return NULL;
	if (first->rLink == first || i == 0) return first;//��˫��ѭ�������iΪ0
	Edge *current;//����ָ��
	if (d == 0) current = first->lLink;//ǰ������ ����ָ���ʼΪβ���
	else current = first->rLink;//��̷��� ����ָ���ʼΪ��Ԫ���
	for (int j = 1; j<i; j++)
		if (current == first) break; //��������
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

