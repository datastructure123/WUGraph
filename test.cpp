#include<iostream>
#include"WUGraph.h"
#include<fstream>
#include<string>
using namespace std;
void Initial(Graphlnk M)
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
	char x;
	char c;
	string Start;
	string End;
	Graphlnk Railway(100000);

	Initial(Railway);
	while (1) {
		cout << "================旅游导航系统系统=================" << endl
			<< "==           1.旅游城市信息                      ==" << endl
			<< "==           2.旅游路线规划                      ==" << endl
			<< "==           3.退出界面                          ==" << endl;

		cin >> x;
		switch (x)
		{
		case'1':
			cout << "城市：" << "数量" << Railway.vertexCount() << endl;
			Railway.getVertices();
			c = getchar();
			break;
		case'2':
			system("cls");
			cout << "=============旅游路线规划==============" << endl
				<< "请输入始发点和目的地-->" << endl;
			cin >> Start >> End;
			system("cls");
			cout << "=============旅游路线规划==============" << endl
				<< "==           最短路径                ==" << endl
				<< "==           最少花费                ==" << endl;
			break;

		case'3':exit(0); break;
		}
	}
}