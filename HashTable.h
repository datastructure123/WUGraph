#pragma once
#include"Vertex.h"
struct VerNode//��Ĺ�ϣ����
{
	Vertex* data = nullptr;
	VerNode *link = nullptr;
	VerNode* last = nullptr;//ָ��ǰһ����㣻
};
struct EdgNode//�ߵĹ�ϣ����
{
	Edge* data = nullptr;
	//int head;//�ߵ����             //�ڱ߽����������
	EdgNode *link = nullptr;
	EdgNode *last = nullptr;
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
class Verhash :public Hash//��Ĺ�ϣ��
{
public:
	Verhash();
	Verhash(int d, int sz);
	~Verhash() { delete[]ht; };
	bool Remove(string a);
	bool Search(string a);
	Vertex* Find(string a);
	bool Insert(Vertex* vertex);
private:
	VerNode * *ht;
	VerNode*FindPos(string);
	//�����num������ʵ�ĵ�ĺ�
};
class Edghash :public Hash//�ߵĹ�ϣ��
{
public:
	Edghash() {}
	Edghash(int d, int sz);
	~Edghash() { delete[]ht; };
	bool Remove(string u, string v);
	Edge* Find(string u, string v);
	bool Search(string u, string v);
	bool Insert(Edge* edge);//����Ҫ�ѱ�ָ�봫������ҲҪ�ѱߵ���һ�봫����
private:
	EdgNode * *ht;
	EdgNode*FindPos(string, string v);
};