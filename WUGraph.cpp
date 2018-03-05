#include "WUGraph.h"
#include<assert.h>
Graphlnk::Graphlnk(int sz)
{
	maxVertices = sz;
	first = new Vertex;
	real = nullptr;
	edg_sort = new Edge;
	numVertices = 0;
	numEdges = 0;
}

void Graphlnk::Initial()
{
	ifstream read, inE;
	read.open("city.txt");
	while (!read.eof())
	{
		Vertex *a = new Vertex();
		int t;
		read >> t >> a->name;
		a->code = t;
		if (read.eof())
			break;
		addVertex(a);
	}
	read.close();
	inE.open("lines.txt");
	int i = 0;
	while (!inE.eof())
	{
		Edge *b = new Edge();
		inE >> b->head >> b->h_name >> b->dest >> b->d_name >> b->dist >> b->cost;
		if (inE.eof())
			break;
		addEdge(b);
	}
	inE.close();
	return;
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
{   //��̫��Ҫ����ʲô����Ķ���
	Vertex*p = first->rLink;
	for(int i=1;p != nullptr;i++)
	{
		cout << "�� " << i << " ����㣺\t";
		cout << p->code<<p->name<<endl;
		p = p->rLink;
	}
}

void Graphlnk::addVertex(Vertex *x)
{
	//�ȴ���һ���㣬Ȼ����ù�ϣ���˫������Ĳ��뺯����������+1
	if (NodeHashtable.Insert(x))
	{
		Vertex *temp;
		temp = real;
		if (temp == nullptr)
		{
			first->rLink = x;
			x->rLink = first;
			real = x;
			numVertices++;
		}
		else
		{
			x->lLink = temp;
			temp->rLink = x;
			real = x;///����Ҳ�����⣡����
			numVertices++;
		}
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
			removeEdge(p->code, q->dest);//ͬʱɾһ��
			q = q->rLink;
		}
		NodeHashtable.Remove(num);
	}
	//ɾ���ڽ��������
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

	//ɾ����ϣ����ĺ�˫���������
}


int Graphlnk::isVertex(int num)
{
	//�ӹ�ϣ�����������
	if (NodeHashtable.Search(num))
		return 1;
	else return -1;
}

int Graphlnk::degree(int v)//���code
{
	//���ڽӱ��ҵ��ߵĸ���
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
	//��ӵ���ϣ���ڽӱ����ڽӱ�Ķ�Ӧλ����������
	EdgeHashtable.Insert(edge);
	Edge*p,*q,*t;
	Vertex*temp;
	if (edge->head == 0)
		cout << "!" << endl;
	temp = NodeHashtable.Find(edge->head);
	temp->degree++;
	p=temp->adj;
	p->lLink = p->rLink = new Edge;
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
	p->lLink = p->rLink = new Edge;
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
		//�ӹ�ϣ���ҵ��ߣ�Ȼ���ҵ��ڽӱ�İ����ߣ���ͨ�����ָ��ɾ�����������
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
	//�ù�ϣ��ֱ�ӱ�����
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
	//�ù�ϣ�������
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
	//��³˹���㷨
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
	//���ŵ����������
	//result����Сֵ

}             

