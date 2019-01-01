#pragma once
using namespace std;
#include <iostream>
#include<vector>
#include<string>

//����Ͷ�����������ݽṹ��type=0��ʾǰ��Ͷ����type=1��ʾ����Ͷ����numΪ��ʱ��ʾ��ǰ������Ͷ��
typedef struct
{
	unsigned int type;
	int num;
}ThroughAction;

//���������ӵ���
class ThroughDicing
{
public:
	//��ʼ�����캯������������ӵ�6��ĳ�ʼ��״̬
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
	
	//��ǰ�����Ͷ��������
    void Through_forward_backward(int step_num);
	
   //��������Ͷ������
	void Through_left_right(int step_num);

	//Ͷ��������ȡ,����һ���ַ�����ǰǰ�������ǰ����������ǰ�������ַ���ǰ�������󡱡����󡱡����ҡ�ת�������֣�����ThroughAction���͵����ݽṹ�ۼӱ��浽��Ӧ������
	void ReadThroughAction(const string& str, char& delim);
	
	//�����ַ�����ʽ����Ͷ�������ָ���뵽������
	void split_string(const char *s, vector<string> &strs, char& delim);
	
	//���ݶ�ȡ��Ͷ��ָ�����Ͷ������
	void Through();

	//��ӡͶ�����ӵĽ��
	void print_result();

	~ThroughDicing();

private:
	//���ӵ�6����
	unsigned int up;
	unsigned int down;
	unsigned int left;
	unsigned int right;
	unsigned int before;
	unsigned int after;
	
	//���Ͷ������������,�ڹ��캯���г�ʼ��
	ThroughAction forward_though;
	ThroughAction backward_through;
	ThroughAction left_through;
	ThroughAction right_through;

};


