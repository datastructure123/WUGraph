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