#include "EdgeDblList.h"

EdgeDblList::~EdgeDblList()
{
}

Edge * EdgeDblList::Search(const int & x, int d)
{
	int i = x;
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
