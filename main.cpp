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
		system("cls");//清屏
		cout << "请输入进制数对应的小写2~10:" << endl;
		cin >> Radix;
		while (Radix < 2 || Radix >10)
		{
			cout << "输入错误，请重新输入：" << endl;
			cin >> Radix;
		}
		calculate.trBinary(Radix);
		cout << "1.键盘输入" << endl;
		cout << "2.文件输入" << endl;
		cout << "请输入1或2" << endl;
		cin >> n;
		while (n != 1 && n != 2)
		{
			cout << "输入错误，请重新输入：" ;
			cin >> n;
		}
		string m,fu;
		if (n == 1)
		{
			cout << "请输入第一个大整数：";
			cin >> m;
			while (calculate.check(m) == 0)
			{
				cout << "输入错误，请重新输入：";
				cin >> m;
			}
			List<int> s1(m);
			cout << "请输入运算符：";
			cin >> fu;
			while (fu != "+"&&fu != "-"&&fu != "*"&&fu != "/"&&fu != "^")
			{
				cout << "输入错误，请重新输入：";
				cin >> fu;
			}
			cout << "请输入第二个大整数：";
			cin >> m;
			while (calculate.check(m) == 0)
			{
				cout << "输入错误，请重新输入：";
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
			cout << "大整数运算的时间是:" ;
			printf("%lf s\n", duration);
			cout << "1.将结果保存到文件" << endl;
			cout << "2.不将结果保存到文件" << endl;
			cout << "请输入1或2" << endl;
			cin >> n;
			while (n != 1 && n != 2)
			{
				cout << "输入错误，请重新输入：";
				cin >> n;
			}
			if (n == 1)
			{
				ofstream fout;
				fout.open("bigData1.txt", ios::out);
				num.save(fout);
				cout << "结果已保存到文件" << endl;
				fout.close();
			}
		}
		else
		{
			cout << "请输入运算符：";
			cin >> fu;
			while (fu != "+"&&fu != "-"&&fu != "*"&&fu != "/"&&fu != "^")
			{
				cout << "输入错误，请重新输入：";
				cin >> fu;
			}
			cout << "1.将结果保存到文件" << endl;
			cout << "2.不将结果保存到文件" << endl;
			cout << "请输入1或2" << endl;
			cin >> n;
			while (n != 1 && n != 2)
			{
				cout << "输入错误，请重新输入：";
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
				cout << "大整数运算的时间是:";
				printf("%lf s\n", duration);
				if (n == 1)
				{
					num.save(fout);
					cout << "结果已保存到文件" << endl;
				}
			}
			fin.close();
			fout.close();
		}
		cout << "1.继续运算" << endl;
		cout << "2.退出程序" << endl;
		cout << "请输入1或2" << endl;
		cin >> n;
		while (n != 1 && n != 2)
		{
			cout << "输入错误，请重新输入：" << endl;
			cin >> n;
		}
		if (n == 2) break;
	}
}
