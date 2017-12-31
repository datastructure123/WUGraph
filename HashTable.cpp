#pragma once
#include"HashTable.h"
#include<assert.h>
//FindPos是插入时使用的函数，可是我们search要返回什么呢？
Hash::Hash()
{
	divisor = 0;
	TableSize = 0;
}
Verhash::Verhash(int d, int sz)
{
	divisor = d;
	TableSize = sz;
	ht = new VerNode*[sz];
	assert(ht != NULL);
}
Edghash::Edghash(int d, int sz)
{
	divisor = d;
	TableSize = sz;
	ht = new EdgNode*[sz];
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
EdgNode* Edghash::FindPos(const int u, const int v)//这里的U v是序号
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
VerNode* Verhash::FindPos(const int num)
{
	
}