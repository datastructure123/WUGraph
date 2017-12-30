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
class hash
{
public:
	hash(int d,int sz);
	~hash();
	virtual bool Search(int num);//传入结点的序号
	virtual bool Insert();
	virtual bool Remove(int num);
	virtual int key(const int num);
private:
	int divisor;
	int TableSize;
};
class Verhash:public hash
{
public:
	Verhash();
    ~Verhash();
	bool Insert(Vertex vertex);
private:
	VerNode**ht;
	VerNode*FindPos(int num);
};
class Edghash:public hash
{
public:
	Edghash();
    ~Edghash();
	bool Insert(Edge edge);
private:
	EdgNode**ht;
	EdgNode*FindPos(int num);
};