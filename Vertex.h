#pragma once
#include<iostream>
#include<string>
using namespace std;
const int maxWeight = 0xfffffff;
class  Edge
{
public:
	int dest = 0;            //边的另一个顶点的真实code
	int cost = 0;              //边上的权值
	int dist = 0;
	int key = 0;     //边的关键码
	int head = 0;//存终点
	string d_name = "";
	string h_name = "";

	Edge  *lLink = nullptr, *rLink = nullptr;   //下一条边链指针
	Edge * partner = nullptr;//伙伴指针
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
	int code = 0;//点的实际值
	string name = "";
	int degree = 0;//点的度数
	Edge *adj = new Edge();
	Vertex *rLink = nullptr, *lLink = nullptr;
};
