#pragma once
#include"HashTable.h"
#include<assert.h>
//FindPos�ǲ���ʱʹ�õĺ�������������searchҪ����ʲô�أ�
Hash::Hash()
{
	divisor = 0;
	TableSize = 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                Verhash �ĺ�����
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Verhash::Remove(const int num)
{
	VerNode*p,*q;
	p=FindPos(num);
	if (p != nullptr)
	{
		q = p->last;
		q->link = p->link;
		delete p;
	}
}
Verhash::Verhash(int d, int sz)
{
	divisor = d;
	TableSize = sz;
	ht = new VerNode*[sz];
	assert(ht != NULL);
}

VerNode* Verhash::FindPos(const int num)
{
	int HashValue = num%divisor;
	VerNode*p = ht[HashValue];
	while (p->data->value != num && p->link != NULL)
	{
		p = p->link;
	}
	return p;
}
bool Verhash::Search(const int num)
{
	VerNode*p;
	p=FindPos(num);
	if (p != nullptr)
		return true;
	else
		return false;
}
bool Verhash::Insert(Vertex vertex)
{
	VerNode*p;
	p = FindPos(vertex.code);
	if (p == NULL)
		p->data=&vertex;
	else return false;//�Ѿ����ڲ���ʧ��
	vertex.code = vertex.code%divisor;
	return true;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                     Edgehash �ĺ�����
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
EdgNode* Edghash::FindPos(const int u, const int v)//�����U v�����
{
	int HashValue=u+v;
	HashValue %= divisor;
	EdgNode*p = ht[HashValue];
	while (p->head!=u&&p->data->dest!=v && p->link != NULL)
	{
		p = p->link;
	}
	return p;
}
Edghash::Edghash(int d, int sz)
{
	divisor = d;
	TableSize = sz;
	ht = new EdgNode*[sz];
	assert(ht != NULL);
}
