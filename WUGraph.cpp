#include "WUGraph.h"

Graphlnk::Graphlnk(int sz)
{
	maxVertices = sz;
	first = new Vertex;
	real = first;
}
int Graphlnk::vertexCount()
{   
	return numVertices;
}

int Graphlnk::edgeCount()
{
	return numEdges;
}

void Graphlnk::getVertices()
{   //不太懂要返回什么具体的东西
	Vertex*p = first->rLink;
	for(int i=1;p != nullptr;i++)
	{
		cout << "第 " << i << " 个结点：\t";
		cout << p->code<<endl;
		p = p->rLink;
	}
}

void Graphlnk::addVertex(Vertex *x)
{
	//先创建一个点，然后调用哈希表和双向链表的插入函数，顶点数+1
	NodeHashtable.Insert(x);
	real->rLink = x;
	x->lLink = real;
	real = x->rLink;
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

int Graphlnk::degree(int v)//点的code
{
	//从邻接表找到边的个数
	return NodeHashtable.Find(v)->degree;
}

int Graphlnk::getFirstNeighbor(int v)
{   
	return NodeHashtable.Find(v)->code;
}

int Graphlnk::getNextNeighbor(int v1, int v2)
{
	return EdgeHashtable.Find(v1, v2)->rLink->dest;
}

void Graphlnk::addEdge(Edge *edge)
{
	//添加到哈希表，邻接表，把邻接表的对应位置链接起来
	EdgeHashtable.Insert(edge);
	Edge*p,*q,*t;
	Vertex*temp;
	temp = NodeHashtable.Find(edge->head);
	temp->degree++;
	p=temp->adj;
	q = p->rLink;
	p->rLink = edge;
	edge->rLink = q;
	edge->lLink = p;
	q->lLink = edge;
//////////////////////////////////////////////////////////////////////////////////////////////
	Edge*current = new Edge;
	*current = *edge;
	current->head = edge->dest;
	current->dest = edge->head;
	temp = NodeHashtable.Find(edge->dest);
	temp->degree++;
	p = temp->adj;
	q = p->rLink;
	p->rLink = current;
	current->rLink = q;
	current->lLink = p;
	q->lLink = current;
/////////////////////////////////////////////////////////////////////////////////////////////
	current->partner = edge;
	edge->partner = edge;
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
