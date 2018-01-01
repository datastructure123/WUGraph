#pragma once
#include<iostream>
const int maxWeight = 0xfffffff;
struct  Edge
{
	int dest;            //�ߵ���һ���������ʵcode
	int cost;              //���ϵ�Ȩֵ
	int key;     //�ߵĹؼ���
	int head;//���յ�
	Edge  *lLink=nullptr, *rLink=nullptr;   //��һ������ָ��
	Edge * partner;//���ָ��
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
	int code;//���ʵ��ֵ
	int degree;//��Ķ���
	Edge *adj=new Edge;
	Vertex *rLink=nullptr, *lLink=nullptr;
};
