#pragma once
#include"Vertex.h"
using namespace std;
class EdgeDblList { //˫��ѭ�������ඨ��
public:
	EdgeDblList() { //���캯��
		first = new Edge();
		if (first == nullptr) { cerr << "�洢�������!"  << endl; exit(1); }
		first->rLink = first->lLink = first;//˫��ѭ������
	};
	~EdgeDblList();
	Edge *getHead() const { return first; }
	void setHead(Edge *ptr) { first = ptr; }
	Edge *Search(const int& x, int d);
	bool Insert(int i, const int& x, int d);
	bool Remove(int i, int& x, int d); 
	bool IsEmpty() { return first->rLink == first; }
	//��˫����շ�
private:
	Edge *first; //��ͷָ��
};