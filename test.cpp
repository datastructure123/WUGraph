#include<iostream>
#include"WUGraph.h"
#include<string>
using namespace std;
void main()
{
	char x;
	char c;
	string Start;
	string End;
	Graphlnk Railway(100000);

	Railway.Initial();
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