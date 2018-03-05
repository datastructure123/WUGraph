#pragma 
#include<iostream>
#include<fstream>
#include"Vertex.h"
#include"HashTable.h"

using namespace std;
//const int maxWeight = INT_MAX;
const int DefaultSize = 100;
const int MaxVertices = 10000;
//enum KindOfStatus { Active, Empty, Deleted };
const int DeafultVertices = 30;			//������󶥵��� =n
class Graphlnk
{
public:
	Graphlnk(int sz);
	~Graphlnk() {};
	void Initial();
	int vertexCount();       //����ͼ�еĶ�����
	int edgeCount();         //����ͼ�еı���
	void getVertices();  //���ذ������ж��������
	void addVertex(Vertex *x);        //��Ӷ���
	void removeVertex(int num);     //ɾ������
	int isVertex(int num);          //�жϸö����Ƿ���ͼ��
	int degree(int v);       //����Ķ�
	int getFirstNeighbor(int v);//���ص�һ���ڽӶ���
	int getNextNeighbor(int v1, int v2); //������һ���ڽӶ���
	void addEdge(Edge* edge);        //��ӱ�
	void removeEdge(int v1, int v2);     //ɾ����
	int isEdge(const int u, const int v);                        //�ж��Ƿ�Ϊ��
	int weight(const int u, const int v);                        //��ĳ�ߵ�Ȩֵ
	void kruskal(int v);                 //��³˹���㷨
private:
	void sort_edge(bool cmp_(const Edge&, const Edge&));
	//���鼯����
	Edge *edg_sort;   //�洢�ź���ı�
	Verhash  NodeHashtable{MaxVertices, MaxVertices};////�����кܴ���ɻ�
	Edghash  EdgeHashtable{MaxVertices,MaxVertices};////
	//VertexDblList NodeTable;
	Vertex *real;
	Vertex *first;
	int maxVertices;
	int numEdges;
	int numVertices;
};


