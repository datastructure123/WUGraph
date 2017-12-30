#pragma 
const int maxWeight = 0xfffffff;
const int DefaultSize = 100;
enum KindOfStatus { Active, Empty, Deleted };
const int DeafultVertices = 30;			//������󶥵��� =n
//template<class T,class E>
struct Vertex
{
	int key;
	T data;
	Edge<T, E> *adj;
	Vertex<T, E> *prior,*next;
};
//template<class T, class E>
struct  Edge
{
	int dest;            //�ߵ���һ������λ��
	E cost;              //���ϵ�Ȩֵ
	Edge<T, E> * Llink,Rlink;   //��һ������ָ��
	Edge<T, E> * partner;//���ָ��
	Edge() { cost = maxWeight; }
	Edge(int num, E weight) : dest(num), cost(weight), Rlink(NULL), Llink(NULL) {}
	bool operator != (Edge<T, E>& R)const
	{
		return (dest != R.dest) ? true : false;
	}
};
template<class T, class E>
class Graphlnk
{
public:
	Graphlnk(int sz = MaxVertices);
	~Graphlnk();
	T getValue(int i)					//ȡλ��Ϊi�Ķ����е�ֵ
	{
		return (i >= 0 && i< numVertices) ? NodeTable[i].nameRouter : 0;
	}
	E getWeight(int v1, int v2);			//���ر�(v1,v2)��Ȩֵ
	bool insertVertex(const Vertex<T, E> vertex);     
	bool removeVertex(int v);
	bool insertEdge(int v1, int v2, const Edge<T, E> edge);
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
	void cruskal(int v);
	
private:
	HashTable<Vertex,int> NodeHashtable;
	HashTable<Edge, int> EdgeHashtable;
	int maxVertices;
	int numEdges;
	int numVertices;
};

