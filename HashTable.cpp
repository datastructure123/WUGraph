#pragma once
#include"HashTable.h"
#include<assert.h>
//FindPos是插入时使用的函数，可是我们search要返回什么呢？
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                     Hash 的函数们
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Hash::Hash()
{
	divisor = 1000;
	TableSize = 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                     Verhash 的函数们
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Verhash::Remove(string a)
{
	VerNode*p, *q;
	p = FindPos(a);//这时返回的是前一个
	if (p == nullptr)
	{
		return false;//不存在这个点
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
		else return false;//不存在这条边
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

	//修改一下找位置，使得最终返回本结点的前一个结点`
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
			return false;//已经存在插入失败
		}
		else//p本身是null的情况
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
//                     Edgehash 的函数们
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
EdgNode* Edghash::FindPos(string u, string v)//这里的U v是序号
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
	//修改一下找位置，使得最终返回本结点的前一个结点

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
bool Edghash::Insert(Edge* edge)//这个head也是序号？我们这个题目中貌似不需要序号吧，反正访问的时候，也是通过hash表来的丫
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
		return false;//已经存在插入失败
	}
	else//p本身是null的情况
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
	p = FindPos(u,v);//这时返回的是前一个
	if (p == nullptr)
	{
		return false;//不存在这个点
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
		else return false;//不存在这条边
	}
}
