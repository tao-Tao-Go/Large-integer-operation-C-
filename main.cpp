#include "List.h"
#include"Calculate.h"
#include <iostream>
#include<time.h>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	clock_t start, finish;
	Calculate calculate;
	int Radix=10,n;
	List<int> num;
	while (1)
	{
		system("cls");//����
		cout << "�������������Ӧ��Сд2~10:" << endl;
		cin >> Radix;
		while (Radix < 2 || Radix >10)
		{
			cout << "����������������룺" << endl;
			cin >> Radix;
		}
		calculate.trBinary(Radix);
		cout << "1.��������" << endl;
		cout << "2.�ļ�����" << endl;
		cout << "������1��2" << endl;
		cin >> n;
		while (n != 1 && n != 2)
		{
			cout << "����������������룺" ;
			cin >> n;
		}
		string m,fu;
		if (n == 1)
		{
			cout << "�������һ����������";
			cin >> m;
			while (calculate.check(m) == 0)
			{
				cout << "����������������룺";
				cin >> m;
			}
			List<int> s1(m);
			cout << "�������������";
			cin >> fu;
			while (fu != "+"&&fu != "-"&&fu != "*"&&fu != "/"&&fu != "^")
			{
				cout << "����������������룺";
				cin >> fu;
			}
			cout << "������ڶ�����������";
			cin >> m;
			while (calculate.check(m) == 0)
			{
				cout << "����������������룺";
				cin >> m;
			}
			List<int> s2(m);
			s1.display();
			cout << fu<<" ";
			s2.display();
			cout << "= ";
			start=clock();
			if (fu == "+")  num=calculate.add(s1, s2);
			else if (fu == "-")  num = calculate.sub(s1, s2);
			else if (fu == "*")  num = calculate.multiply(s1, s2);
			else if (fu == "/")  num = calculate.division(s1, s2);
			else if (fu == "^")  num = calculate.exOperation(s1, s2);
			finish = clock();
			double duration = (double)(finish - start)/ CLOCKS_PER_SEC;
			num.display();
			cout << endl;
			cout << "�����������ʱ����:" ;
			printf("%lf s\n", duration);
			cout << "1.��������浽�ļ�" << endl;
			cout << "2.����������浽�ļ�" << endl;
			cout << "������1��2" << endl;
			cin >> n;
			while (n != 1 && n != 2)
			{
				cout << "����������������룺";
				cin >> n;
			}
			if (n == 1)
			{
				ofstream fout;
				fout.open("bigData1.txt", ios::out);
				num.save(fout);
				cout << "����ѱ��浽�ļ�" << endl;
				fout.close();
			}
		}
		else
		{
			cout << "�������������";
			cin >> fu;
			while (fu != "+"&&fu != "-"&&fu != "*"&&fu != "/"&&fu != "^")
			{
				cout << "����������������룺";
				cin >> fu;
			}
			cout << "1.��������浽�ļ�" << endl;
			cout << "2.����������浽�ļ�" << endl;
			cout << "������1��2" << endl;
			cin >> n;
			while (n != 1 && n != 2)
			{
				cout << "����������������룺";
				cin >> n;
			}
			string m2;
			ifstream fin;
			fin.open("bigData0.txt", ios::in);
			ofstream fout;
			fout.open("bigData1.txt", ios::out);
			while (fin >> m >> m2)
			{
				List<int> s1(m);
				List<int> s2(m2);
				s1.display();
				cout << fu << " ";
				s2.display();
				cout << "= ";
				start = clock();
				if (fu == "+")  num = calculate.add(s1, s2);
				else if (fu == "-")  num = calculate.sub(s1, s2);
				else if (fu == "*")  num = calculate.multiply(s1, s2);
				else if (fu == "/")  num = calculate.division(s1, s2);
				else if (fu == "^")  num = calculate.exOperation(s1, s2);
				finish = clock();
				double duration = (double)(finish - start)/ CLOCKS_PER_SEC;
				num.display();
				cout << endl;
				cout << "�����������ʱ����:";
				printf("%lf s\n", duration);
				if (n == 1)
				{
					num.save(fout);
					cout << "����ѱ��浽�ļ�" << endl;
				}
			}
			fin.close();
			fout.close();
		}
		cout << "1.��������" << endl;
		cout << "2.�˳�����" << endl;
		cout << "������1��2" << endl;
		cin >> n;
		while (n != 1 && n != 2)
		{
			cout << "����������������룺" << endl;
			cin >> n;
		}
		if (n == 2) break;
	}
}
