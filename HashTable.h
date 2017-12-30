#pragma once
#include"WUGraph.h"
//num是序号
//
struct VerNode
{
	Vertex data;
	VerNode *link;
};
struct EdgNode
{
	Edge data;
	EdgNode *link;
};
class Hash
{
public:
	Hash(int d,int sz);
	~Hash();
    bool Search(int num);//传入结点的序号
    bool Remove(int num);
    int key(const int num);
private:
	int divisor;
	int TableSize;
};
class Verhash:public Hash
{
public:
	Verhash();
    ~Verhash();
	bool Insert(Vertex vertex);
private:
	VerNode**ht;
	VerNode*FindPos(int num);
};
class Edghash:public Hash
{
public:
	Edghash();
    ~Edghash();
	bool Insert(Edge edge);
private:
	EdgNode**ht;
	EdgNode*FindPos(int num);
};