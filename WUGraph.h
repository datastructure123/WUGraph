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
	void removeVertex(string a);     //ɾ������
	int isVertex(string a);          //�жϸö����Ƿ���ͼ��
	int degree(string a);       //����Ķ�
	string getFirstNeighbor(string a);//���ص�һ���ڽӶ���
	string getNextNeighbor(string v1, string v2); //������һ���ڽӶ���
	void addEdge(Edge* edge);        //��ӱ�
	void removeEdge(string v1, string v2);     //ɾ����
	int isEdge(string u, string v);                        //�ж��Ƿ�Ϊ��
	int weightcost(string u, string v);                        //��ĳ�ߵ�Ȩֵ
	int weightdist(string u, string v);
	int getWeight(int a, int b, int type);
	void dijstra(string a, string b, int *path, int type);                 //��³˹���㷨
private:
	Verhash  NodeHashtable{ 1000, MaxVertices };////�����кܴ���ɻ�
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
