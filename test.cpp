#include<iostream>
#include"WUGraph.h"
void main()
{
	char x;
	string Start;
	string End;
	Graphlnk Railway;

	Railway.initiate();
	while (1) {
		cout << "================���ε���ϵͳϵͳ=================" << endl
			<< "==           1.���γ�����Ϣ                      ==" << endl
			<< "==           2.����·�߹滮                      ==" << endl
			<< "==           3.�˳�����                          ==" << endl;
		
		cin >> x;
		switch (x)
		{
		case'1':
         cout << "���У�" << "����"<<Railway.vertexCount<<endl;
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
}