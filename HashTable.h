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
	Hash();
	~Hash() {};
    bool Search(int num);//传入结点的序号
    bool Remove(int num);
    int key(const int num);
protected:
	int divisor;
	int TableSize;
};
class Verhash:public Hash
{
public:
	Verhash(int d,int sz);
	~Verhash() { delete[]ht; };
	bool Insert(Vertex vertex);
private:
	VerNode**ht;
	VerNode*FindPos(int num);
};
class Edghash:public Hash
{
public:
	Edghash(int d,int sz);
    ~Edghash() { delete[]ht; };
	bool Insert(Edge edge);
private:
	EdgNode**ht;
	EdgNode*FindPos(int num);
};
