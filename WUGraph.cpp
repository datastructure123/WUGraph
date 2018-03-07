#include "WUGraph.h"
#include<assert.h>
Graphlnk::Graphlnk(int sz)
{
	maxVertices = sz;
	first = new Vertex;
	real = nullptr;
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
		read >> t;
		if (read.eof())
			break;
		read>> a->name;
		a->code = t;
		addVertex(a);
	}
	read.close();
	inE.open("lines.txt");
	int i = 0;
	while (!inE.eof())
	{
		Edge *b = new Edge();
		inE >> b->head;
		if (inE.eof())
			break;
		inE >> b->h_name >> b->dest >> b->d_name >> b->dist >> b->cost;
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
		x->number = numVertices;
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

void Graphlnk::removeVertex(string a)
{
	Vertex*p, *t;
	Edge *d;
	t = p = NodeHashtable.Find(a);
	if (p != nullptr)
	{  
		Edge *q = p->adj->rLink;
		
 		while (q->rLink != nullptr)
		{   d = q->rLink;
			removeEdge(q->h_name, q->d_name);//ͬʱɾһ��
			q = d;
		}
		NodeHashtable.Remove(a);
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

int Graphlnk::isVertex(string a)
{
	//�ӹ�ϣ�����������
	int num = 0;
	string::iterator ptr1 = a.begin();
	for (int i = 0; ptr1 != a.end(); i++)
	{
		num += *ptr1;
		ptr1++;
	}
	if (num < 0)
		num *= -1;
	if (NodeHashtable.Search(a))
		return 1;
	else return -1;
}

int Graphlnk::degree(string a)//���code
{
	//���ڽӱ��ҵ��ߵĸ���
	Vertex *p;
	p = NodeHashtable.Find(a);
	if (p != nullptr)
		return p->degree;
	else return -1;
}

string Graphlnk::getFirstNeighbor(string a)
{
	Vertex *p;
	int num = 0;
	p = NodeHashtable.Find(a);
	if (p != nullptr)
		return p->name;
	else return '\0';
}

string Graphlnk::getNextNeighbor(string v1, string v2)
{
	Edge *p = EdgeHashtable.Find(v1, v2);
	if (p != nullptr)
		return p->rLink->d_name;
	else return '\0';
}

void Graphlnk::addEdge(Edge *edge)
{
	//��ӵ���ϣ���ڽӱ����ڽӱ�Ķ�Ӧλ����������
	EdgeHashtable.Insert(edge);
	Edge*p, *q, *t;
	Vertex*temp,*temp1;
	if (edge->head == 0)
		cout << "!" << endl;
	int num1 = 0;
	int num2 = 0;
	string::iterator ptr1 = edge->h_name.begin();
	for (int i = 0; ptr1 != edge->h_name.end(); i++)
	{
		num1 += *ptr1;
		ptr1++;
	}
	if (num1 < 0)
		num1 *= -1;
	ptr1 = edge->d_name.begin();
	for (int i = 0; ptr1 != edge->d_name.end(); i++)
	{
		num2 += *ptr1;
		ptr1++;
	}
	if (num2 < 0)
		num2 *= -1;
	temp = NodeHashtable.Find(edge->h_name);
	if (temp == nullptr)
	{
		cout << edge->h_name << "δ��ѯ��\n";
		return;
	}
	temp1 = NodeHashtable.Find(edge->d_name);
	if (temp1 == nullptr)
	{
		cout << edge->d_name << "δ��ѯ��\n";
		return;
	}
	temp->degree++;
	p = temp->adj;
	if (p->lLink == NULL && p->rLink == NULL)
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
	temp = temp1;
	temp->degree++;
	p = temp->adj;
	if (p->lLink == NULL && p->rLink == NULL)
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

void Graphlnk::removeEdge(string v1, string v2)
{   Edge *p, *q, *t;
    p = EdgeHashtable.Find(v1, v2);
	if (EdgeHashtable.Remove(v1, v2))
	{
		NodeHashtable.Find(v1)->degree--;
		//�ӹ�ϣ���ҵ��ߣ�Ȼ���ҵ��ڽӱ�İ����ߣ���ͨ�����ָ��ɾ�����������
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

int Graphlnk::isEdge(string v1, string v2)
{
	//�ù�ϣ��ֱ�ӱ�����
	if (EdgeHashtable.Search(v1, v2))
		return 1;
	else return -1;
	return 0;
}

int Graphlnk::weightcost(string v1, string v2)
{
	Edge*p = EdgeHashtable.Find(v1, v2);
	if (p != nullptr)
		return p->cost;
	else return -1;
	//�ù�ϣ�������
}

int Graphlnk::weightdist(string v1, string v2)
{
	Edge*p = EdgeHashtable.Find(v1, v2);
	if (p != nullptr)
		return p->dist;
	else return -1;
	//�ù�ϣ�������
}

int Graphlnk::getWeight(int a, int b, int type)
{
	Vertex*p = first->rLink;
	Vertex*q = first->rLink;
	while (p != nullptr&q!=nullptr)
	{
		if (p->number != a)
			p = p->rLink;
		if (q->number != b)
			q = q->rLink;
		if (p->number == a&&q->number == b)
			break;
	}
	if (p != nullptr&&q != nullptr && p->number == a && p->number == a)
	{
		int num;
		if (type == 0)
			num = weightcost(p->name, q->name);
		else
			num = weightdist(p->name, q->name);
		if (num == -1)
			return 0xfffff;
		else return num;
	}
	else
		return 0xfffff;
}

void Graphlnk::dijstra(string a, string b, int *path, int type)
{
	int n = numVertices;
	bool *S = new bool[n];
	int *dist = new int[n];
	path = new int[n];
	int i, j, k;
	int w, min;
	Vertex *temp, *t;
	t = NodeHashtable.Find(b);
	temp = NodeHashtable.Find(a);//a�����
	if (temp == nullptr&&t!=nullptr)
	{
		cout << "���У�" << a << "�������ڼ�¼��\n";
		return;
	}
	else if (temp != nullptr&&t == nullptr)
	{
		cout << "���У�" << a << "�������ڼ�¼ \n";
		return;
	}
	else if (temp == nullptr&&t == nullptr)
	{
		cout << "���У�" << a << "����У�" << b << "���������ڼ�¼ \n";
		return;
	}
	for (i = 0; i < n; i++)
	{
		dist[i] = 0xfffff;
		S[i] = false;
		if (i != temp->number && dist[i] < 0xfffff)
			path[i] = temp->number;
		else
		{
			path[i] = -1;
		}
	}
	S[temp->number] = true;
	dist[temp->number] = 0;
	for (i = 0; i < n - 1; i++)
	{
		min = 0xfffff;
		int u = temp->number;
		for (j = 0; j < n; j++)
		{
			if (S[j] == false && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		}
		S[u] = true;
		for (k = 0; k < n; k++)
		{
			if (k == u)continue;
			w = getWeight(u, k, type);//;����֮��ĳ���
									  //�������м�������·��
			if (S[k] == false && w < 0xfffff && dist[u] + w < dist[k])
			{
				dist[k] = dist[u] + w;
				path[k] = u;
			}
		}
	}
	print(dist, path, temp->number, t->number,type);
}

void Graphlnk::print(int* dist, int* path, int u, int v,int type)
{
	int i, j, k;
	int n = numVertices;
	int *d = new int[n];
	j = v;
	k = 0;
	if (path[v] == -1)
	{
		cout << "�ó��в��ɴ\n\n";
		return;
	}
	while (j != u)
	{
		d[k++] = j;
		j = path[j];
	}
	d[k++] = u;
	while (k > 1)
	{
		cout << getvalue(d[--k]) << "->";
	}
	cout << getvalue(d[--k]) << endl<< endl;
	if (type == 1)
		cout << "���·������Ϊ��" << dist[v] << endl<< endl;
	else if (type == 2)
		cout << "���ٻ���Ϊ��" << dist[v] << endl<< endl;

	delete[] d;
}

string Graphlnk::getvalue(int v)
{
	Vertex*p = first->rLink;
	if (v > numVertices)
		cout << "�����ڸó���\n";
	while (p->number != v)
	{
		p = p->rLink;
	}
	return p->name;
}