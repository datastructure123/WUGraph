#pragma once
#include"Vertex.h"
struct VerNode//点的哈希表结点
{
	Vertex* data=nullptr;
	VerNode *link=nullptr;
	VerNode* last=nullptr;//指向前一个结点；
};
struct EdgNode//边的哈希表结点
{
	Edge* data=nullptr;
	//int head;//边的起点             //在边结点里增加量
	EdgNode *link=nullptr;
	EdgNode *last=nullptr;
};
class Hash
{
public:
	Hash();
	~Hash() {};
	virtual bool Search(const int num) { return true; }//查找
protected:
	int key;
	int divisor;
	int TableSize;
	//KindOfStatus* info = new KindOfStatus[TableSize];开散列里没什么卵用
};
class Verhash:public Hash//点的哈希表
{
public:
	Verhash(){}
	Verhash(int d,int sz);
	~Verhash() { delete[]ht; };
	bool Remove(const int num);
	bool Search(const int num);
	Vertex* Find(const int num);
	bool Insert(Vertex* vertex);
private:
	VerNode**ht;
	VerNode*FindPos(const int num);
	//这里的num就是真实的点的号
};
class Edghash:public Hash//边的哈希表
{
public:
	Edghash() {}
	Edghash(int d,int sz);
    ~Edghash() { delete[]ht; };
	bool Remove(const int u,const int v);
	Edge* Find(const int u,const int v);
	bool Search(const int u, const int v);
	bool Insert(Edge* edge);//不仅要把边指针传进来，也要把边的另一半传进来
private:
	EdgNode**ht;
	EdgNode*FindPos(const int u,const int v);
};