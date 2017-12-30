#pragma 
#include<iostream>
#include"EdgeDblList.h"
#include"VertexDblList.h"
#include"HashTable.h"
using namespace std;
const int maxWeight = INT_MAX;
const int DefaultSize = 100;
const int MaxVertices = 10000;
//enum KindOfStatus { Active, Empty, Deleted };
const int DeafultVertices = 30;			//代表最大顶点数 =n
struct Vertex
{
	int key;
	int code;//序号
	int value;//实际值
	Edge *adj;
	Vertex *rLink,*lLink;
};
struct  Edge
{
	int dest;            //边的另一个顶点位置这个是在数组中的序号
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
	int vertexCount();       //返回图中的顶点数
	int edgeCount();         //返回图中的边数
	Vertex * getVertices();  //返回包含所有顶点的数组
	void addVertex();        //添加顶点
	void removeVertex();     //删除顶点
	int isVertex();          //判断该顶点是否在图中
	int degree(int v);       //顶点的度
	int getFirstNeighbor(int v1, int v2);//返回第一个邻接顶点
	int getNextNeighbor(int v1, int v2); //返回下一个邻接顶点
	void addEdge(int v1, int v2);        //添加边
	void removeEdge(int v1, int v2);     //删除边
	int isEdge();                        //判断是否为边
	int weight();                        //求某边的权值
	void kruskal(int v);                 //克鲁斯卡算法
private:
	Verhash  NodeHashtable;
	Edghash  EdgeHashtable;
	VertexDblList NodeTable;
	EdgeDblList EdgeTable;
	int maxVertices;
	int numEdges;
	int numVertices;
};


