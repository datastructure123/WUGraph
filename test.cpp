#include<iostream>
#include"WUGraph.h"
#include<fstream>
#include<string>
using namespace std;
void Inistial(Graphlnk M)
{
	ifstream read, inE;
	read.open("C:\\Users\\dell\\Desktop\\学习大二上\\DataStructure\\WUG\\city.txt");
	while (!read.eof())
	{
		Vertex *a = new Vertex();
		read >> a->code >> a->name;
		M.addVertex(a);
	}
	read.close();
	inE.open("C:\\Users\\dell\\Desktop\\学习大二上\\DataStructure\\WUG\\lines.txt");
	while (!inE.eof())
	{
		Edge *b = new Edge();
		inE >> b->head >> b->h_name >> b->dest >> b->d_name >> b->dist >> b->cost;
		M.addEdge(b);
	}
	inE.close();
	return;
}
void main()
{

	Graphlnk M(10000);
	Inistial(M);
	return;
}