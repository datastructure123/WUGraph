#pragma 
#include<iostream>
#include"HashTable.h"
using namespace std;
const int maxWeight = INT_MAX;
const int DefaultSize = 100;
const int MaxVertices = 10000;
enum KindOfStatus { Active, Empty, Deleted };
const int DeafultVertices = 30;			//������󶥵��� =n
struct Vertex
{
	int key;
	int data;
	Edge *adj;
	Vertex *rLink,*lLink;
};
struct  Edge
{
	int dest;            //�ߵ���һ������λ��
	int cost;              //���ϵ�Ȩֵ
	int key;             //�ߵĹؼ���
	Edge  *lLink,*rLink;   //��һ������ָ��
	Edge * partner;//���ָ��
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
	int getValue(int i)					//ȡλ��Ϊi�Ķ����е�ֵ
	{
		return (i >= 0 && i< numVertices) ? NodeTable[i].nameRouter : 0;
	}
	int getWeight(int v1, int v2);			//���ر�(v1,v2)��Ȩֵ
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

