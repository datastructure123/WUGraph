#pragma once
#include"WUGraph.h"
//num�����
//
struct VerNode//��ϣ���еĵ�����
{
	Vertex* data;
	VerNode *link;
};
struct EdgNode//��ϣ���еı߽����
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
    bool Search(int num);//����������
    bool Remove(int num);
protected:
	int key;
	int divisor;
	int TableSize;
	//KindOfStatus* info = new KindOfStatus[TableSize];��ɢ���ﲻ���������

};
class Verhash:public Hash//��Ĺ�ϣ��
{
public:
	Verhash(int d,int sz);
	~Verhash() { delete[]ht; };
	bool Insert(Vertex vertex);
private:
	VerNode**ht;
	VerNode*FindPos(const int num);
};
class Edghash:public Hash//�ߵĹ�ϣ��
{
public:
	Edghash(int d,int sz);
    ~Edghash() { delete[]ht; };
	bool Insert(Edge edge);
private:
	EdgNode**ht;
	EdgNode*FindPos(const int u,const int v);
};