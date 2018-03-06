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
bool Verhash::Remove(string a)
{
	VerNode*p, *q;
	p = FindPos(a);//��ʱ���ص���ǰһ��
	if (p == nullptr)
	{
		return false;//�����������
	}
	else if (p != nullptr)
	{
		if (p->link != nullptr)
		{
			q = p->link;
			if (q != nullptr)
				p->link = q->link;
			delete q;
		}
		else return false;//������������
	}
}
Verhash::Verhash(int d, int sz)
{
	divisor = d;
	TableSize = sz;
	ht = (VerNode**)new VerNode*[d];
	for (int i = 0; i < d; i++)
	{
		ht[i] = new VerNode[d];
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
VerNode* Verhash::FindPos(string a)
{
	int num = 0;
	for (int i = 0; i<a.size(); i++)
	{
		num += a[i];
	}
	if (num < 0)
		num *= -1;
	int HashValue = num % divisor;
	VerNode*p = ht[HashValue], *q = p;

	//�޸�һ����λ�ã�ʹ�����շ��ر�����ǰһ�����`
	while (p != NULL && p->data->name != a)
	{
		q = p;
		p = p->link;
	}
	return q;
}
Vertex* Verhash::Find(string a)
{
	return (FindPos(a)->link->data);
}
bool Verhash::Search(string a)
{
	VerNode*p;
	p = FindPos(a);
	if (p != nullptr&&p->link != nullptr)
		return true;
	else
		return false;
}
bool Verhash::Insert(Vertex* vertex)
{
	VerNode*p, *q;
	int num = 0;
	for (int i = 0; i < vertex->name.size(); i++)
	{
		num += vertex->name[i];
	}
	if (num < 0)
		num *= -1;
	p = FindPos(vertex->name);
	q = p;
	while (p->link!=NULL)
	{
		p = p->link;
	}
		if (p != NULL && p->link == NULL)
		{
			p->link = new VerNode;
			p->link->data = vertex;
			p->link->last = q;
		}
		else if (p != NULL && p->link != NULL)
		{
			return false;//�Ѿ����ڲ���ʧ��
		}
		else//p������null�����
		{
			p = new VerNode;
			p->data = vertex;
			p->link = q;
		}

	vertex->key = num % divisor;
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
EdgNode* Edghash::FindPos(string u, string v)//�����U v�����
{
	
	int num1 = 0;
	for (int i = 0; i < u.size(); i++)
	{
		num1 += u[i];
	}
	if (num1 < 0)
		num1 *= -1;
	int num2 = 0;
	for (int i = 0; i < v.size(); i++)
	{
		num2 += v[i];
	}
	if (num2 < 0)
		num2 *= -1;

	int HashValue = num1 + num2;
	HashValue %= divisor;
	EdgNode*p = ht[HashValue], *q = p;
	//�޸�һ����λ�ã�ʹ�����շ��ر�����ǰһ�����

	while (p != NULL)
	{
		if (p->data->h_name == u && p->data->d_name == v)
		{
			break;
		}
		q = p;
		p = p->link;
	}
	return q;
}
Edge* Edghash::Find(string u, string v)
{
	EdgNode*p = FindPos(u, v)->link;
	if (p == nullptr)
	{
		p = FindPos(v, u)->link;
		if (p == nullptr)
			return nullptr;
		else
			return p->data;
	}
	else
		return p->data;
}
bool Edghash::Insert(Edge* edge)//���headҲ����ţ����������Ŀ��ò�Ʋ���Ҫ��Űɣ��������ʵ�ʱ��Ҳ��ͨ��hash������Ѿ
{
	EdgNode*p, *q;
	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i < edge->h_name.size(); i++)
	{
		num1 += edge->h_name[i];
	}
	if (num1 < 0)
		num1 *= -1;
	for (int i = 0; i < edge->d_name.size(); i++)
	{
		num2 += edge->d_name[i];
	}
	if (num2 < 0)
		num2 *= -1;
	p = FindPos(edge->h_name, edge->d_name);
	q = p;
	if (p != NULL && p->link == NULL)
	{
		p->link = new EdgNode;
		p->link->data = edge;
		p->link->last = q;
	}
	else if (p != NULL && p->link != NULL)
	{
		return false;//�Ѿ����ڲ���ʧ��
	}
	else//p������null�����
	{
		p->data = edge;
		p->link = q;
	}
	edge->key = (num1 + num2) % divisor;
	return true;
}
bool Edghash::Search(string u, string v)
{
	EdgNode*p;
	p = FindPos(u, v);
	if (p != nullptr&&p->link != nullptr)
		return true;
	else
		return false;
}
bool Edghash::Remove(string u, string v)
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
			q = p->link;
			if (q != nullptr)
				p->link = q->link;
			delete q;
		}
		else return false;//������������
	}
}
