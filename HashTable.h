#pragma once
#include"Vertex.h"
struct VerNode//��Ĺ�ϣ����
{
	Vertex* data;
	VerNode *link;
};
struct EdgNode//�ߵĹ�ϣ����
{
	Edge* data;
	int head;//�ߵ����
	EdgNode *link;
};
class Hash
{
public:
	Hash();
	~Hash() {};
    virtual bool Search(int num);//����
    bool Remove(int num);
protected:
	int key;
	int divisor;
	int TableSize;
	//KindOfStatus* info = new KindOfStatus[TableSize];��ɢ����ûʲô����
};
class Verhash:public Hash//��Ĺ�ϣ��
{
public:
	Verhash(int d,int sz);
	~Verhash() { delete[]ht; };
	bool Insert(Vertex vertex);
private:
	VerNode**ht;
	VerNode*FindPos(const int num);//�����num������ʵ�ĵ�ĺ�
};
class Edghash:public Hash//�ߵĹ�ϣ��
{
public:
	Edghash(int d,int sz);
    ~Edghash() { delete[]ht; };
	bool Search(const int u, const int v);
	bool Insert(Edge edge, int head);//����Ҫ�ѱ�ָ�봫������ҲҪ�ѱߵ���һ�봫����
private:
	EdgNode**ht;
	EdgNode*FindPos(const int u,const int v);
};