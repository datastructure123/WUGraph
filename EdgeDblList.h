#pragma once
#include"WUGraph.h"
class EdgeDblList { //双向循环链表类定义
public:
	EdgeDblList() { //构造函数
		first = new Edge();
		if (first == NULL) { cerr << "存储分配出错!"  << endl; exit(1); }
		first->rLink = first->lLink = first;//双向循环链表
	};
	~EdgeDblList();
	Edge *getHead() const { return first; }
	void setHead(Edge *ptr) { first = ptr; }
	Edge *Search(const int& x, int d);
	bool Insert(int i, const int& x, int d);
	bool Remove(int i, int& x, int d); 
	bool IsEmpty() { return first->rlink == first; }
	//判双链表空否
private:
	Edge *first; //表头指针
};