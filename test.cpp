#include<iostream>
#include"WUGraph.h"
#include<string>
using namespace std;
void main()
{
	char x;
	char c;
	string name, nameA, nameB;
	Vertex* city = new Vertex;
	string Start;
	string End;
	Edge * way=new Edge;

	Graphlnk Railway(100000);
	int* path = new int[10];
	Railway.Initial();
	while (1) {
		cout << "=================旅游导航系统系统==================" << endl
			<< "==           1.旅游城市信息                      ==" << endl
			<< "==           2.旅游路线规划                      ==" << endl
			<< "==           3.添加城市信息                      ==" << endl
			<< "==           4.删除城市信息                      ==" << endl
			<< "==           5.添加可达路径                      ==" << endl
			<< "==           6.删除已有路径	                  ==" << endl
			<< "==           7.退出界面                          ==" << endl;

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
				<< "==           最短路径:1              ==" << endl
				<< "==           最少花费:0              ==" << endl;
			int ans;
			cin >> ans;
			Railway.dijstra(Start, End, path, ans);
			break;

		case'3':
			cout << "=============添加城市信息=============" << endl
				<< "==      请输入城市名称以及编号      ==" << endl;
			cin >> city->name >> city->code;
			Railway.addVertex(city);
			break;
		case'4':
			cout << "=============删除城市信息==============" << endl
				<< "==       请输入删除城市的名称        ==" << endl;
			cin >> name;
			Railway.removeVertex(name);
			break;
		case'5':
			cout << "=============添加可达路径==============" << endl
				<< "==       请输入添加的路径信息        ==" << endl
				<< "== 编号A 城市A 编号B 城市B 距离 花费 ==" << endl;
			cin >> way->head >> way->h_name >> way->dest >> way->d_name >> way->dist >> way->cost;
			Railway.addEdge(way);
			break;
		case'6':
			cout << "=============删除可达路径==============" << endl
				<< "==       请输入删除的路径信息        ==" << endl
				<< "==    城市名A           城市名B      ==" << endl;
			cin >> nameA >> nameB;
			Railway.removeEdge(nameA, nameB);
			break;
		case'7':exit(0); break;
		}
	}
}
