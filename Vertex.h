#pragma once
#include<iostream>
const int maxWeight = 0xfffffff;
struct  Edge
{
	int dest;            //�ߵ���һ������λ��������������е����
	int cost;              //���ϵ�Ȩֵ
	int key;             //�ߵĹؼ���
	Edge  *lLink, *rLink;   //��һ������ָ��
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
	int code;//���
	int value;//ʵ��ֵ
	int degree;//��Ķ���
	Edge *adj;
	Vertex *rLink, *lLink;
};
