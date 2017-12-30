#pragma once
#include"WUGraph.h"
class EdgeDblList { //˫��ѭ�������ඨ��
public:
	EdgeDblList() { //���캯��
		first = new Edge();
		if (first == NULL) { cerr << "�洢�������!"  << endl; exit(1); }
		first->rLink = first->lLink = first;//˫��ѭ������
	};
	~EdgeDblList();
	Edge *getHead() const { return first; }
	void setHead(Edge *ptr) { first = ptr; }
	Edge *Search(const int& x, int d);
	bool Insert(int i, const int& x, int d);
	bool Remove(int i, int& x, int d); 
	bool IsEmpty() { return first->rlink == first; }
	//��˫����շ�
private:
	Edge *first; //��ͷָ��
};