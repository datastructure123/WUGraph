#pragma once
#include"Vertex.h"
//num是序号
//
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
    bool Search(int num);//查找
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
	VerNode*FindPos(const int num);
};
class Edghash:public Hash//边的哈希表
{
public:
	Edghash(int d,int sz);
    ~Edghash() { delete[]ht; };
	bool Insert(Edge edge);
private:
	EdgNode**ht;
	EdgNode*FindPos(const int u,const int v);
};