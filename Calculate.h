#ifndef	CALCULATE
#define CALCULATE
#include <iostream>
#include"List.h"
using namespace std;
class Calculate
{
public:
	Calculate() { radix = 10; }                            //构造函数
	~Calculate() {}                                        //析构函数
	List<int>& add(List<int> &s1, List<int> &s2);          //加法运算
	List<int>& sub(List<int> &s1, List<int> &s2);          //减法运算
	List<int>& multiply(List<int> &s1, List<int> &s2);     //乘法运算
	List<int>& division(List<int> &s1, List<int> &s2);     //除法运算
	List<int>& exOperation(List<int> &s1, List<int> &s2);  //指数运算
	void preZeroDelete(List<int> &s1);                     //去前置0         
	bool check(const string str);                          //检查输入是否合法
	bool compare(List<int> &s1,List<int> &s2);             //比较函数（若s1>=s2则返回1,否则返回0）
	void trBinary(int n);                                  //进制转换

private:
	int radix;                                             //进制转换时改变它(基数)
};
#endif