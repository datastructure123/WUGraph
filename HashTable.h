#pragma once
#include"Vertex.h"
//num是序�?
//
struct VerNode//哈希表中的点结点�?
{
	Vertex* data;
	VerNode *link;
};
struct EdgNode//哈希表中的边结点�?
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
    bool Search(int num);//传入结点的序�?
    bool Remove(int num);
protected:
	int key;
	int divisor;
	int TableSize;
	//KindOfStatus* info = new KindOfStatus[TableSize];开散列里不用这个功�?
};
class Verhash:public Hash//点的哈希�?
{
public:
	Verhash(int d,int sz);
	~Verhash() { delete[]ht; };
	bool Insert(Vertex vertex);
private:
	VerNode**ht;
	VerNode*FindPos(const int num);
};
class Edghash:public Hash//边的哈希�?
{
public:
	Edghash(int d,int sz);
    ~Edghash() { delete[]ht; };
	bool Insert(Edge edge);
private:
	EdgNode**ht;
	EdgNode*FindPos(const int u,const int v);
};