#ifndef	CALCULATE
#define CALCULATE
#include <iostream>
#include"List.h"
using namespace std;
class Calculate
{
public:
	Calculate() { radix = 10; }                            //���캯��
	~Calculate() {}                                        //��������
	List<int>& add(List<int> &s1, List<int> &s2);          //�ӷ�����
	List<int>& sub(List<int> &s1, List<int> &s2);          //��������
	List<int>& multiply(List<int> &s1, List<int> &s2);     //�˷�����
	List<int>& division(List<int> &s1, List<int> &s2);     //��������
	List<int>& exOperation(List<int> &s1, List<int> &s2);  //ָ������
	void preZeroDelete(List<int> &s1);                     //ȥǰ��0         
	bool check(const string str);                          //��������Ƿ�Ϸ�
	bool compare(List<int> &s1,List<int> &s2);             //�ȽϺ�������s1>=s2�򷵻�1,���򷵻�0��
	void trBinary(int n);                                  //����ת��

private:
	int radix;                                             //����ת��ʱ�ı���(����)
};
#endif