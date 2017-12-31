#pragma once
#include"Vertex.h"
struct VerNode//点的哈希表结点
{
	Vertex* data;
	VerNode *link;
};
struct EdgNode//边的哈希表结点
{
	Edge* data;
	int head;//边的起点
	EdgNode *link;
};
class Hash
{
public:
	Hash();
	~Hash() {};
    virtual bool Search(int num);//查找
    bool Remove(int num);
protected:
	int key;
	int divisor;
	int TableSize;
	//KindOfStatus* info = new KindOfStatus[TableSize];开散列里没什么卵用
};
class Verhash:public Hash//点的哈希表
{
public:
	Verhash(int d,int sz);
	~Verhash() { delete[]ht; };
	bool Insert(Vertex vertex);
private:
	VerNode**ht;
	VerNode*FindPos(const int num);//这里的num就是真实的点的号
};
class Edghash:public Hash//边的哈希表
{
public:
	Edghash(int d,int sz);
    ~Edghash() { delete[]ht; };
	bool Search(const int u, const int v);
	bool Insert(Edge edge, int head);//不仅要把边指针传进来，也要把边的另一半传进来
private:
	EdgNode**ht;
	EdgNode*FindPos(const int u,const int v);
};