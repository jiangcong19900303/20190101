#include<iostream>
using namespace std;
typedef struct
{
	int a;
	int c;
}my_struct;

int fun(void)
{
	static int count = 10;// ��ʵ�ϴ˸�ֵ������û��ִ�й� �����ж����static�����ڵ�һ�ν��뺯����ʱ���ʼ��������ִ���������  
	return count--;
}
int main(void)
{
	cout << "fun()=" << fun() << endl; //���10   
	cout << "fun()=" << fun() << endl; //���9   
	cout << "fun()=" << fun() << endl; //���8   
	cout << "fun()=" << fun() << endl; //���7   
	cout << "fun()=" << fun() << endl; //���6  
	return 0;
}
