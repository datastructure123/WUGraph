#pragma 
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
	int vertexCount();       //返回图中的顶点数
	int edgeCount();         //返回图中的边数
	void getVertices();  //返回包含所有顶点的数组
	void addVertex(Vertex *x);        //添加顶点
	void removeVertex(int num);     //删除顶点
	int isVertex(int num);          //判断该顶点是否在图中
	int degree(int v);       //顶点的度
	int getFirstNeighbor(int v);//返回第一个邻接顶点
	int getNextNeighbor(int v1, int v2); //返回下一个邻接顶点
	void addEdge(Edge* edge);        //添加边
	void removeEdge(int v1, int v2);     //删除边
	int isEdge(const int u, const int v);                        //判断是否为边
	int weight(const int u, const int v);                        //求某边的权值
	void kruskal(int v);                 //克鲁斯卡算法
private:
	void sort_edge(bool cmp_(const Edge&, const Edge&));
	//并查集所需
	Edge *edg_sort;   //存储排好序的边
	Verhash  NodeHashtable{MaxVertices, MaxVertices};////这里有很大的疑惑
	Edghash  EdgeHashtable{MaxVertices,MaxVertices};////
	//VertexDblList NodeTable;
	Vertex *real;
	Vertex *first;
	int maxVertices;
	int numEdges;
	int numVertices;
};


