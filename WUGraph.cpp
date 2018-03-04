#include "WUGraph.h"

Graphlnk::Graphlnk(int sz)
{
	maxVertices = sz;
	first = new Vertex;
	real = nullptr;
	edg_sort = new Edge;
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
	if (NodeHashtable.Insert(x))
	{
		Vertex *temp;
		temp = real;
		if (temp == nullptr)
			first->rLink = x;
		x->lLink = temp;
		real = x;///这里也有问题！！！
		numVertices++;
	}
}

void Graphlnk::removeVertex(int num)
{
	Vertex*p, *t;
	t = p = NodeHashtable.Find(num);
	if (p != nullptr)
	{
		Edge *q = p->adj->rLink;
		while (q != nullptr)
		{
			removeEdge(p->code, q->dest);//同时删一对
			q = q->rLink;
		}
		NodeHashtable.Remove(num);
	}
	//删除邻接链表里的
	if (t != nullptr)
	{
		Vertex *a = real;
		real = real->lLink;
		p->adj = a->adj;
		p->code = a->code;
		p->degree = a->degree;
		p->key = a->key;
		p->name = a->name;
		real->rLink = nullptr;
		a = nullptr;
		numVertices--;
	}

	//删除哈希表里的和双向链表里的
}


int Graphlnk::isVertex(int num)
{
	//从哈希表里遍历顶点
	if (NodeHashtable.Search(num))
		return 1;
	else return -1;
}

int Graphlnk::degree(int v)//点的code
{
	//从邻接表找到边的个数
	Vertex *p;
	p = NodeHashtable.Find(v);
	if (p != nullptr)
		return p->degree;
	else return -1;
}

int Graphlnk::getFirstNeighbor(int v)
{   
	Vertex *p;
	p = NodeHashtable.Find(v);
	if (p != nullptr)
		return p->code;
	else return -1;
}

int Graphlnk::getNextNeighbor(int v1, int v2)
{
	Edge *p = EdgeHashtable.Find(v1, v2);
	if(p!=nullptr)
	return p->rLink->dest;
	else return -1;
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
	if (EdgeHashtable.Remove(v1, v2))
	{
		NodeHashtable.Find(v1)->degree--;
		//从哈希表找到边，然后找到邻接表的半条边，再通过伙伴指针删除另外半条边
		Edge *p, *q, *t;
		p = EdgeHashtable.Find(v1, v2);
		q = p->lLink;
		t = p->rLink;
		q->rLink = t;
		t->lLink = q;
		///////////////////////////////////////////////////////////////////////////////////
		NodeHashtable.Find(v2)->degree--;
		Edge *m, *n, *k;
		m = p->partner;
		n = p->lLink;
		k = p->rLink;
		n->rLink = k;
		k->lLink = n;
		///////////////////////////////////////////////////////////////////////////////////
		delete p, m;
	}

}

int Graphlnk::isEdge(const int u,const int v)
{
	//用哈希表直接遍历边
	if (EdgeHashtable.Search(u, v))
		return 1;
	else return -1;
	return 0;
}

int Graphlnk::weight(const int u,const int v)
{
	Edge*p=EdgeHashtable.Find(u, v);
	if(p!=nullptr)
	return p->cost;
	else return -1;
	//用哈希表遍历边
}

void Graphlnk::sort_edge(bool cmp_(const Edge&, const Edge&))
{
	Vertex*p = first;
	while (p !=nullptr)
	{
		Edge*q = p->adj->rLink;
		while (q != nullptr)
		{
			if (edg_sort->rLink == nullptr)
			{
				edg_sort->rLink = q;
			}
			else
			{
				Edge* temp = edg_sort->rLink,*m;
				m = temp;
				while (temp!=nullptr)
				{
					m = temp;
					if (temp->cost < q->cost)
						temp = temp->rLink;
				}
				q->rLink = m->rLink;
				m->rLink = q;
			}
			q = q->rLink;
		}
		p = p->rLink;
	}
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

