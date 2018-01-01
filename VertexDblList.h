#pragma once
#include"Vertex.h"
using namespace std;
class VertexDblList { //双向循环链表类定义
public:
	VertexDblList() { //构造函数
		first = new Vertex;
		if (first == NULL) { cerr << "存储分配出错!" << endl; exit(1); }
		first->rLink = first->lLink = first;//双向循环链表
	};
	~VertexDblList();
	Vertex *getHead() const { return first; }
	void setHead(Vertex *ptr) { first = ptr; }
	//Vertex *Search(const int& x, int d);
	Vertex *Locate(int i, int d);
	bool Insert(int i, Vertex * x, int d);
	bool Remove(int i, Vertex * x, int d); //删除第i个结点
	bool IsEmpty() { return first->rLink == first; }
	//判双链表空否
private:
	Vertex *first; //表头指针
};