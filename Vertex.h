#pragma once
#include<iostream>
#include<string>
using namespace std;
const int maxWeight = 0xfffffff;
class  Edge
{
public:
	int dest = 0;            //�ߵ���һ���������ʵcode
	int cost = 0;              //���ϵ�Ȩֵ
	int dist = 0;
	int key = 0;     //�ߵĹؼ���
	int head = 0;//���յ�
	string d_name = "";
	string h_name = "";

	Edge  *lLink = nullptr, *rLink = nullptr;   //��һ������ָ��
	Edge * partner = nullptr;//���ָ��
	Edge() { cost = maxWeight; }
	Edge(int num, int weight, string name) : dest(num), cost(weight), lLink(nullptr), rLink(nullptr), d_name(name) {};
	bool operator != (Edge& R)const
	{
		return (dest != R.dest) ? true : false;
	}
};

class Vertex
{
public:
	int key = 0;
	int number = 0;
	int code = 0;//���ʵ��ֵ
	string name = "";
	int degree = 0;//��Ķ���
	Edge *adj = new Edge();
	Vertex *rLink = nullptr, *lLink = nullptr;
};
