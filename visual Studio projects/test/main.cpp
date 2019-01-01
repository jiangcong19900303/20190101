#include<iostream>
using namespace std;
typedef struct
{
	int a;
	int c;
}my_struct;

int fun(void)
{
	static int count = 10;// 事实上此赋值语句从来没有执行过 函数中定义的static变量在第一次进入函数的时候初始化，而不执行这条语句  
	return count--;
}
int main(void)
{
	cout << "fun()=" << fun() << endl; //输出10   
	cout << "fun()=" << fun() << endl; //输出9   
	cout << "fun()=" << fun() << endl; //输出8   
	cout << "fun()=" << fun() << endl; //输出7   
	cout << "fun()=" << fun() << endl; //输出6  
	return 0;
}
