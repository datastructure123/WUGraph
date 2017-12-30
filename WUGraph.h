#pragma 
#include<iostream>
#include"HashTable.h"
using namespace std;
const int maxWeight = INT_MAX;
const int DefaultSize = 100;
const int MaxVertices = 10000;
enum KindOfStatus { Active, Empty, Deleted };
const int DeafultVertices = 30;			//代表最大顶点数 =n
struct Vertex
{
	int key;
	int data;
	Edge *adj;
	Vertex *rLink,*lLink;
};
struct  Edge
{
	int dest;            //边的另一个顶点位置
	int cost;              //边上的权值
	int key;             //边的关键码
	Edge  *lLink,*rLink;   //下一条边链指针
	Edge * partner;//伙伴指针
	Edge() { cost = maxWeight; }
	Edge(int num, int weight) : dest(num), cost(weight), Rlink(NULL), Llink(NULL) {}
	bool operator != (Edge& R)const
	{
		return (dest != R.dest) ? true : false;
	}

};
class Graphlnk
{
public:
	Graphlnk(int sz = MaxVertices);
	~Graphlnk();
	int getValue(int i)					//取位置为i的顶点中的值
	{
		return (i >= 0 && i< numVertices) ? NodeTable[i].nameRouter : 0;
	}
	int getWeight(int v1, int v2);			//返回边(v1,v2)的权值
	bool insertVertex(const Vertex vertex);     
	bool removeVertex(int v);
	bool insertEdge(int v1, int v2, const Edge edge);
	bool removeEdge(int v1, int v2);
	int NumberOfVertices()
	{
		return this->numVertices;
	}
	int getVertexPos(const int num)
	{
		for (int i = 0; i< numVertices; i++)
			if (NodeTable[i].numRouter == num)
				return i;
		return -1;
	}
	void kruskal(int v);
	
private:
	Verhash  NodeHashtable;
	Edghash  EdgeHashtable;
	VertexDblList NodeTable;
	EdgeDblList EdgeTable;
	int maxVertices;
	int numEdges;
	int numVertices;
};

