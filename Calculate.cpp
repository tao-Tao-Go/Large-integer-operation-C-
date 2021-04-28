#include <iostream>
#include"Calculate.h"
using namespace std;
bool Calculate::compare(List<int> &s1, List<int> &s2)  //比较函数（若s1>=s2则返回1,否则返回0）
{
	preZeroDelete(s1);
	preZeroDelete(s2);
	if (s1.getlength() > s2.getlength())
		return 1;
	else if (s1.getlength() < s2.getlength())
		return 0;
	else
	{
		node<int>*a = s1.root;
		node<int>*b = s2.root;
		while (a->next)
		{
			if (a->next->data > b->next->data)
				return 1;
			else if (a->next->data < b->next->data)
				return 0;
			else
			{
				a = a->next;
				b = b->next;
			}
		}
		return 1;

	}
}
bool Calculate::check(const string str)        //检查输入是否合法
{
	int a = str.length();
		for (int i = 0; i < a; i++)
		{
			if (str[i]-'0'<0 || str[i]-'0'>=radix)
				return 0;
		}
		return 1;
}
void Calculate::trBinary(int n)                                 //进制转换
{
	radix = n;
}
void Calculate::preZeroDelete(List<int> &s1)               //去前置0
{
	while (s1.root->next&&s1.root->next->data == 0)
	{
		s1.erase(0);
	}
	if (s1.getlength() == 0)
		s1.insert(0);                                       //全零则置零
}
List<int>& Calculate::division(List<int> &s1, List<int> &s2)   //除法函数实现
{
	preZeroDelete(s1);
	preZeroDelete(s2);
	List<int> num("0");
	List<int> m;
	int n = s1.getlength() - s2.getlength();
	while (1)
	{
		if (compare(s1, s2) != 1)
		{
			for (int i = 1; i <= n + 1; i++)
			{
				num.insert(0);
			}
			preZeroDelete(num);
			s1 = num;
			return s1;
		}
		m = s2;
		for (int i = 1; i <= n; i++)
		{
			m.insert(0);
		}
		int k = 0;
		while (compare(s1, m))
		{
			sub(s1, m);
			k++;
		}
		num.insert(k);
		n--;
	}

}
List<int>& Calculate::exOperation(List<int> &s1, List<int> &s2)    //指数函数实现
{
	preZeroDelete(s1);
	preZeroDelete(s2);
	List<int> a;
	a = s1;
	List<int> k;
	k = s2;
	List<int> b("1");
	while (k.getlength() > 1 || k.root->next->data > 1)
	{
		multiply(s1, a);
		sub(k, b);
	}
	return s1;
}
List<int>& Calculate::sub(List<int> &s1, List<int> &s2)            //减法函数实现
{
	preZeroDelete(s1);
	preZeroDelete(s2);
	if (compare(s1, s2))
	{
		node<int>* a = s1.tail;
		node<int>* b = s2.tail;
		for (int i = 1; i <= s2.getlength(); i++)
		{
			if (a->data >= b->data)
				a->data -= b->data;
			else
			{
				a->prev->data -= 1;
				a->data += 1 * radix;
				a->data -= b->data;
			}
			a = a->prev;
			b = b->prev;
		}
		preZeroDelete(s1);
		return s1;
	}
	else
	{
		node<int>* a = s2.tail;
		node<int>* b = s1.tail;
		for (int i = 1; i <= s1.getlength(); i++)
		{
			if (a->data >= b->data)
				a->data -= b->data;
			else
			{
				a->prev->data -= 1;
				a->data += 1 * radix;
				a->data -= b->data;
			}
			a = a->prev;
			b = b->prev;
		}
		s2.sign = '-';
		preZeroDelete(s2);
		return s2;
	}
}
List<int>& Calculate::multiply(List<int> &s1, List<int> &s2)           //乘法运算
{
	preZeroDelete(s1);
	preZeroDelete(s2);
	List<int> c;
	c.insert(0);
	node<int>* B = s2.tail;
	for (int i = 1; i <= s2.getlength(); i++)
	{
		List<int> d;
		node<int>* A = s1.tail;
		int n = 0;
		for (int j = 1; j <= s1.getlength(); j++)
		{
			d.preInsert((A->data*B->data + n) % radix);
			n = (A->data*B->data + n) / radix;
			A = A->prev;
		}
		if (n > 0) d.preInsert(n);
		B = B->prev;
		for (int k = 0; k < i - 1; k++)              //补零
		{
			d.insert(0);
		}
		node<int>* a = c.tail;
		node<int>* b = d.tail;
		for (int i = 1; i <= d.getlength(); i++)
		{
			if (a->prev == c.root)
			{
				c.preInsert(0);
			}
			a->data += b->data;
			if (a->data >= radix)
			{
				a->data = a->data%radix;
				a->prev->data += 1;
			}
			a = a->prev;
			b = b->prev;
		}

	}

	preZeroDelete(c);
	s1 = c;
	return s1;
}
List<int>& Calculate::add(List<int> &s1, List<int> &s2)           //加法函数实现
{
	preZeroDelete(s1);
	preZeroDelete(s2);
	if (s1.getlength() >= s2.getlength())
	{
		node<int>* a = s1.tail;
		node<int>* b = s2.tail;
		for (int i = 1; i <= s2.getlength(); i++)
		{
			a->data += b->data;
			if (a->data >= radix)
			{
				a->data = a->data%radix;
				if (a->prev != s1.root)
					a->prev->data += 1;
				else
					s1.preInsert(1);
			}
			a = a->prev;
			b = b->prev;
		}
		return s1;
	}
	else
	{
		node<int>* a = s2.tail;
		node<int>* b = s1.tail;
		for (int i = 1; i <= s1.getlength(); i++)
		{
			a->data += b->data;
			if (a->data >= radix)
			{
				a->data = a->data%radix;
				if (a->prev != s2.root)
					a->prev->data += 1;
				else
					s2.preInsert(1);
			}
			a = a->prev;
			b = b->prev;
		}
		return s2;
	}
}
