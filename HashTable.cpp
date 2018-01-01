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
	divisor = 0;
	TableSize = 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                     Verhash 的函数们
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Verhash::Remove(const int num)
{
	VerNode*p,*q;
	p=FindPos(num);//这时返回的是前一个
	if (p == nullptr)
	{
		return false;//不存在这个点
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
		else return false;//不存在这条边
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
	VerNode*p = ht[HashValue],*q=p;
	//修改一下找位置，使得最终返回本结点的前一个结点
	while (p != NULL&&p->data->value != num)
	{
		q = p;
		p = p->link;
	}
	return q;
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
		p->link->data = vertex;
		p->link->last = q;
	}
	else if(p!=NULL&&p->link!=NULL)
	{
		return false;//已经存在插入失败
	}
	else//p本身是null的情况
	{
		p->data = vertex;
		p->link = q;
	}
	vertex->key = vertex->code%divisor;
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
	ht = new EdgNode*[sz];
	assert(ht != NULL);
}
EdgNode* Edghash::FindPos(const int u, const int v)//这里的U v是序号
{
	int HashValue=u+v;
	HashValue %= divisor;
	EdgNode*p = ht[HashValue], *q = p;
	//修改一下找位置，使得最终返回本结点的前一个结点
	while (p->head != u&&p->data->dest != v && p->link != NULL)
	{
		q = p;
		p = p->link;
	}
	return p;
}
bool Edghash::Insert(Edge* edge)//这个head也是序号？我们这个题目中貌似不需要序号吧，反正访问的时候，也是通过hash表来的丫
{
	EdgNode*p, *q;
	p = FindPos(edge->head,edge->dest);
	q = p;
	if (p != NULL&&p->link == NULL)
	{
		p->link->data = edge;
		p->link->last = q;
	}
	else if (p != NULL&&p->link != NULL)
	{
		return false;//已经存在插入失败
	}
	else//p本身是null的情况
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
	p = FindPos(u,v);//这时返回的是前一个
	if (p == nullptr)
	{
		return false;//不存在这个点
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
		else return false;//不存在这条边
	}
}
