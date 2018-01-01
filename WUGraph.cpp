#include "WUGraph.h"

Graphlnk::Graphlnk(int sz)
{
	maxVertices = sz;
}
int Graphlnk::vertexCount()
{   
	return numVertices;
}

int Graphlnk::edgeCount()
{
	return numEdges;
}

Vertex * Graphlnk::getVertices()
{   //不太懂要返回什么具体的东西
	return nullptr;
}

void Graphlnk::addVertex(Vertex *x)
{
	//先创建一个点，然后调用哈希表和双向链表的插入函数，顶点数+1
	NodeHashtable.Insert(x);
	NodeTable.Insert(numVertices, x, 1);
	numVertices++;
}

void Graphlnk::removeVertex()
{

	//删除哈希表里的和双向链表里的
}

int Graphlnk::isVertex()
{
	//从哈希表里遍历顶点
	return 0;
}

int Graphlnk::degree(int v)
{
	//从邻接表找到边的个数
	return 0;
}

int Graphlnk::getFirstNeighbor(int v1, int v2)
{   
	return 0;
}

int Graphlnk::getNextNeighbor(int v1, int v2)
{
	return 0;
}

void Graphlnk::addEdge(int v1, int v2)
{
	//添加到哈希表，邻接表，把邻接表的对应位置链接起来
}

void Graphlnk::removeEdge(int v1, int v2)
{
	//从哈希表找到边，然后找到邻接表的半条边，再通过伙伴指针删除另外半条边
}

int Graphlnk::isEdge()
{
	//用哈希表直接遍历边
	return 0;
}

int Graphlnk::weight()
{
	//用哈希表遍历边
	return 0;
}
void Graphlnk::sort_edge(bool cmp_(const Edge&, const Edge&))
{

}
bool comp(const Edge& a, const Edge& b)
{
	return a.cost < b.cost;
}
void Graphlnk::kruskal(int v)
{
	//克鲁斯卡算法
	bool *vis = new bool[numVertices];
	sort_edge(comp);
	int result{ 0 };
	for (int i = 0; i < numEdges; i++)
	{
		Edge e{ edg_sort[i] };
		if (vis[e.dest] == false || vis[e.head] == false)
		{
			result += e.cost;
			vis[e.dest] = true;
			vis[e.head] = true;
		}
	}

	delete[] vis;
	//接着调用输出函数
	//result是最小值

}                                                                                                                                                                                                     
