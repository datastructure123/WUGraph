#pragma once
#include"HashTable.h"
#include<assert.h>
//FindPos�ǲ���ʱʹ�õĺ�������������searchҪ����ʲô�أ�
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                     Hash �ĺ�����
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Hash::Hash()
{
	divisor = 1000;
	TableSize = 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                     Verhash �ĺ�����
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Verhash::Remove(const int num)
{
	VerNode*p,*q;
	p=FindPos(num);//��ʱ���ص���ǰһ��
	if (p == nullptr)
	{
		return false;//�����������
	}
	else if (p != nullptr)
	{
		if (p->link != nullptr)
		{
			q = p->last;
			if (q != nullptr)
				q->link = p->link;
			delete p;
		}
		else return false;//������������
	}
}
Verhash::Verhash(int d, int sz)
{
	divisor = d;
	TableSize = sz;
	ht = (VerNode**)new VerNode*[1000];
	for (int i = 0; i < 1000; i++)
	{
		ht[i] = new VerNode[1000];
		ht[i]->data = new Vertex;
	}
	assert(ht != NULL);
}
Verhash::Verhash()
{
	ht = (VerNode**)new VerNode*[1000];
	for (int i = 0; i < 1000; i++)
	{
		ht[i] = new VerNode[1000];
		ht[i]->data = new Vertex;
	}
	
	assert(ht != NULL);
}
VerNode* Verhash::FindPos(const int num)
{
	int HashValue = num%divisor;
	VerNode*p = ht[HashValue],*q=p;
	//�޸�һ����λ�ã�ʹ�����շ��ر�����ǰһ�����
	while (p != NULL&&p->data->code!= num)
	{
		q = p;
		p = p->link;	
	}
	return q;
}
Vertex* Verhash::Find(const int num)
{
	return (FindPos(num)->link->data);
}
bool Verhash::Search(const int num)
{
	VerNode*p;
	p=FindPos(num);
	if (p != nullptr&&p->link!=nullptr)
		return true;
	else
		return false;
}
bool Verhash::Insert(Vertex* vertex)
{
	VerNode*p,*q;
	p = FindPos(vertex->code);
	q = p;
	if (p != NULL&&p->link == NULL)
	{
		p->link = new VerNode;
		p->link->data = vertex;
		p->link->last = q;
	}
	else if(p!=NULL&&p->link!=NULL)
	{
		return false;//�Ѿ����ڲ���ʧ��
	}
	else//p������null�����
	{
		p = new VerNode;
		p->data = vertex;
		p->link = q;
	}
	vertex->key = vertex->code%divisor;
	return true;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                     Edgehash �ĺ�����
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Edghash::Edghash(int d, int sz)
{
	divisor = d;
	TableSize = sz;
	ht = (EdgNode**)new EdgNode*[1000];
	for (int i = 0; i < 1000; i++)
	{
		ht[i] = new EdgNode[1000];
		ht[i]->data =new Edge;
	}
	assert(ht != NULL);
}
EdgNode* Edghash::FindPos(const int u, const int v)//�����U v�����
{
	int HashValue=u+v;
	HashValue %= divisor;
	EdgNode*p = ht[HashValue], *q = p;
	//�޸�һ����λ�ã�ʹ�����շ��ر�����ǰһ�����
	while (p->link != NULL)
	{
		if (p->data->head == u && p->data->dest == v)
		{
			break;
		}
		q = p;
		p = p->link;
	}
	return q;
}
Edge* Edghash::Find(const int u, const int v)
{
	return (FindPos(u, v)->data);
}
bool Edghash::Insert(Edge* edge)//���headҲ����ţ����������Ŀ��ò�Ʋ���Ҫ��Űɣ��������ʵ�ʱ��Ҳ��ͨ��hash������Ѿ
{
	EdgNode*p, *q;
	p = FindPos(edge->head,edge->dest);
	q = p;
	if (p != NULL&&p->link == NULL)
	{
		p->link = new EdgNode;
		p->link->data = edge;
		p->link->last = q;
	}
	else if (p != NULL&&p->link != NULL)
	{
		return false;//�Ѿ����ڲ���ʧ��
	}
	else//p������null�����
	{
		p->data = edge;
		p->link = q;
	}
	edge->key = (edge->head+edge->dest)%divisor;
	return true;
}
bool Edghash::Search(int u, int v)
{
	EdgNode*p;
	p = FindPos(u,v);
	if (p != nullptr&&p->link != nullptr)
		return true;
	else
		return false;
}
bool Edghash::Remove(int u, int v)
{
	EdgNode*p, *q;
	p = FindPos(u,v);//��ʱ���ص���ǰһ��
	if (p == nullptr)
	{
		return false;//�����������
	}
	else if (p != nullptr)
	{
		if (p->link != nullptr)
		{
			q = p->last;
			if (q != nullptr)
				q->link = p->link;
			delete p;
		}
		else return false;//������������
	}
}
