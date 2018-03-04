#include<iostream>
#include"WUGraph.h"
#include<fstream>
#include<string>
using namespace std;
void Initial(Graphlnk M)
{
	ifstream read, inE;
	read.open("C:\\Users\\dell\\Desktop\\ѧϰ�����\\DataStructure\\WUG\\city.txt");
	while (!read.eof())
	{
		Vertex *a = new Vertex();
		read >> a->code >> a->name;
		M.addVertex(a);
	}
	read.close();
	inE.open("C:\\Users\\dell\\Desktop\\ѧϰ�����\\DataStructure\\WUG\\lines.txt");
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
	char x;
	char c;
	string Start;
	string End;
	Graphlnk Railway(100000);

	Initial(Railway);
	while (1) {
		cout << "================���ε���ϵͳϵͳ=================" << endl
			<< "==           1.���γ�����Ϣ                      ==" << endl
			<< "==           2.����·�߹滮                      ==" << endl
			<< "==           3.�˳�����                          ==" << endl;

		cin >> x;
		switch (x)
		{
		case'1':
			cout << "���У�" << "����" << Railway.vertexCount() << endl;
			Railway.getVertices();
			c = getchar();
			break;
		case'2':
			system("cls");
			cout << "=============����·�߹滮==============" << endl
				<< "������ʼ�����Ŀ�ĵ�-->" << endl;
			cin >> Start >> End;
			system("cls");
			cout << "=============����·�߹滮==============" << endl
				<< "==           ���·��                ==" << endl
				<< "==           ���ٻ���                ==" << endl;
			break;

		case'3':exit(0); break;
		}
	}
}