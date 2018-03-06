#pragma 
#include<iostream>
#include<fstream>
#include<vector>
#include"Vertex.h"
#include"HashTable.h"

using namespace std;
//const int maxWeight = INT_MAX;
const int DefaultSize = 100;
const int MaxVertices = 10000;
//enum KindOfStatus { Active, Empty, Deleted };
const int DeafultVertices = 30;			//代表最大顶点数 =n
class Graphlnk
{
public:
	Graphlnk(int sz);
	~Graphlnk() {};
	void Initial();
	int vertexCount();       //返回图中的顶点数
	int edgeCount();         //返回图中的边数
	void getVertices();  //返回包含所有顶点的数组
	void addVertex(Vertex *x);        //添加顶点
	void removeVertex(string a);     //删除顶点
	int isVertex(string a);          //判断该顶点是否在图中
	int degree(string a);       //顶点的度
	string getFirstNeighbor(string a);//返回第一个邻接顶点
	string getNextNeighbor(string v1, string v2); //返回下一个邻接顶点
	void addEdge(Edge* edge);        //添加边
	void removeEdge(string v1, string v2);     //删除边
	int isEdge(string u, string v);                        //判断是否为边
	int weightcost(string u, string v);                        //求某边的权值
	int weightdist(string u, string v);
	int getWeight(int a, int b, int type);
	void dijstra(string a, string b, int *path, int type);                 //克鲁斯卡算法
private:
	Verhash  NodeHashtable{ 1000, MaxVertices };////这里有很大的疑惑
	Edghash  EdgeHashtable{ 1000,MaxVertices };////
											   //VertexDblList NodeTable;
	Vertex *real;
	Vertex *first;
	void print(int* dist, int* path, int u, int v);
	string getvalue(int v);
	int maxVertices;
	int numEdges;
	int numVertices;
};
