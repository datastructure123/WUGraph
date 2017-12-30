#pragma once
#include"WUGraph.h"
class VertexDblList { //˫��ѭ�������ඨ��
public:
	VertexDblList() { //���캯��
		first = new Vertex;
		if (first == NULL) { cerr << "�洢�������!" << endl; exit(1); }
		first->rLink = first->lLink = first;//˫��ѭ������
	};
	~VertexDblList();
	Vertex *getHead() const { return first; }
	void setHead(Vertex *ptr) { first = ptr; }
	Vertex *Search(const int& x, int d);
	
	bool Insert(int i, const int& x, int d);
	bool Remove(int i, int& x, int d); //ɾ����i�����
	bool IsEmpty() { return first->rLink == first; }
	//��˫����շ�
private:
	Vertex *first; //��ͷָ��
};