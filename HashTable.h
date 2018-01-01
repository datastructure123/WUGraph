#pragma once
#include"Vertex.h"
struct VerNode//��Ĺ�ϣ����
{
	Vertex* data=nullptr;
	VerNode *link=nullptr;
	VerNode* last=nullptr;//ָ��ǰһ����㣻
};
struct EdgNode//�ߵĹ�ϣ����
{
	Edge* data=nullptr;
	int head;//�ߵ����
	EdgNode *link=nullptr;
	EdgNode *last=nullptr;
};
class Hash
{
public:
	Hash();
	~Hash() {};
	virtual bool Search(const int num) { return true; }//����
protected:
	int key;
	int divisor;
	int TableSize;
	//KindOfStatus* info = new KindOfStatus[TableSize];��ɢ����ûʲô����
};
class Verhash:public Hash//��Ĺ�ϣ��
{
public:
	Verhash(){}
	Verhash(int d,int sz);
	~Verhash() { delete[]ht; };
	bool Remove(const int num);
	bool Search(const int num);
	bool Insert(Vertex* vertex);
private:
	VerNode**ht;
	VerNode*FindPos(const int num);
	//�����num������ʵ�ĵ�ĺ�
};
class Edghash:public Hash//�ߵĹ�ϣ��
{
public:
	Edghash() {}
	Edghash(int d,int sz);
    ~Edghash() { delete[]ht; };
	bool Remove(const int u,const int v);
	bool Search(const int u, const int v);
	bool Insert(Edge* edge);//����Ҫ�ѱ�ָ�봫������ҲҪ�ѱߵ���һ�봫����
private:
	EdgNode**ht;
	EdgNode*FindPos(const int u,const int v);
};