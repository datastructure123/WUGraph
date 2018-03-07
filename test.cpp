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
		cout << "=================���ε���ϵͳϵͳ==================" << endl
			<< "==           1.���γ�����Ϣ                      ==" << endl
			<< "==           2.����·�߹滮                      ==" << endl
			<< "==           3.��ӳ�����Ϣ                      ==" << endl
			<< "==           4.ɾ��������Ϣ                      ==" << endl
			<< "==           5.��ӿɴ�·��                      ==" << endl
			<< "==           6.ɾ������·��	                  ==" << endl
			<< "==           7.�˳�����                          ==" << endl;

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
				<< "==           ���·��:1              ==" << endl
				<< "==           ���ٻ���:0              ==" << endl;
			int ans;
			cin >> ans;
			Railway.dijstra(Start, End, path, ans);
			break;

		case'3':
			cout << "=============��ӳ�����Ϣ=============" << endl
				<< "==      ��������������Լ����      ==" << endl;
			cin >> city->name >> city->code;
			Railway.addVertex(city);
			break;
		case'4':
			cout << "=============ɾ��������Ϣ==============" << endl
				<< "==       ������ɾ�����е�����        ==" << endl;
			cin >> name;
			Railway.removeVertex(name);
			break;
		case'5':
			cout << "=============��ӿɴ�·��==============" << endl
				<< "==       ��������ӵ�·����Ϣ        ==" << endl
				<< "== ���A ����A ���B ����B ���� ���� ==" << endl;
			cin >> way->head >> way->h_name >> way->dest >> way->d_name >> way->dist >> way->cost;
			Railway.addEdge(way);
			break;
		case'6':
			cout << "=============ɾ���ɴ�·��==============" << endl
				<< "==       ������ɾ����·����Ϣ        ==" << endl
				<< "==    ������A           ������B      ==" << endl;
			cin >> nameA >> nameB;
			Railway.removeEdge(nameA, nameB);
			break;
		case'7':exit(0); break;
		}
	}
}
