#pragma once
using namespace std;
#include <iostream>
#include<vector>
#include<string>

//定义投掷动作的数据结构，type=0表示前后投掷，type=1表示左右投掷，num为正时表示向前或向左投掷
typedef struct
{
	unsigned int type;
	int num;
}ThroughAction;

//定义掷骰子的类
class ThroughDicing
{
public:
	//初始化构造函数，入参是骰子的6面的初始化状态
	ThroughDicing(unsigned int UP, unsigned int DOWN, unsigned int LEFT, unsigned int RIGHT, unsigned int BEFORE, unsigned int AFTER) :up(UP),down(DOWN),left(LEFT),right(RIGHT),before(BEFORE),after(AFTER)
	{
		forward_though.type = 0;
		forward_though.num = 0;
		backward_through.type = 0;
		backward_through.num = 0;

		left_through.type = 1;
		left_through.num = 0;
		right_through.type = 1;
		right_through.num = 0;		
	}
	
	//向前，向后投掷函数，
    void Through_forward_backward(int step_num);
	
   //向左向右投掷函数
	void Through_left_right(int step_num);

	//投掷动作读取,给定一个字符串“前前后后左右前后左右左后后前”，把字符“前”、“后”、“左”、“右”转换成数字，并以ThroughAction类型的数据结构累加保存到对应变量中
	void ReadThroughAction(const string& str, char& delim);
	
	//把以字符串形式输入投掷操作分割存入到向量中
	void split_string(const char *s, vector<string> &strs, char& delim);
	
	//根据读取的投掷指令进行投掷操作
	void Through();

	//打印投掷骰子的结果
	void print_result();

	~ThroughDicing();

private:
	//骰子的6个面
	unsigned int up;
	unsigned int down;
	unsigned int left;
	unsigned int right;
	unsigned int before;
	unsigned int after;
	
	//存放投掷操作的数组,在构造函数中初始化
	ThroughAction forward_though;
	ThroughAction backward_through;
	ThroughAction left_through;
	ThroughAction right_through;

};


