#pragma once
#include<iostream>
const int maxWeight = 0xfffffff;
struct  Edge
{
	int dest;            //边的另一个顶点位置这个是在数组中的序号
	int cost;              //边上的权值
	int key;             //边的关键码
	Edge  *lLink, *rLink;   //下一条边链指针
	Edge * partner;//伙伴指针
	Edge() { cost = maxWeight; }
	Edge(int num, int weight) : dest(num), cost(weight), lLink(nullptr), rLink(nullptr) {};
	bool operator != (Edge& R)const
	{
		return (dest != R.dest) ? true : false;
	}
};
struct Vertex
{
	int key;
	int code;//序号
	int value;//实际值
	int degree;//点的度数
	Edge *adj;
	Vertex *rLink, *lLink;
};
