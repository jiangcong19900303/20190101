#include "ThroughDice.h"
using namespace std;
void ThroughDicing::Through_forward_backward(int step_num)
{
	int a = up;
	int b = down;
	int c = before;
	int d = after;
	//向前投掷
	if (step_num > 0)
	{
		int n = step_num % 4;
		if (n == 0)return;
		else if (n == 1)
		{
			up = c;
			down = d;
			before = b;
			after = a;
			return;
		}
		else if(n==2)
		{
			up = b;
			down = a;
			before = d;
			after = c;
			return;
		}
		else
		{
			up = d;
			down = c;
			before = a;
			after = b;
			return;
		}
		
	}
	//向后投掷
	else if (step_num < 0)
	{
		int n = step_num % 4;
		if (n == 0)return;
		else if (n == -1)
		{
			up = d;
			down = c;
			before = a;
			after = b;
			return;
		}
		else if (n == -2)
		{
			up = b;
			down = a;
			before = d;
			after = c;
			return;
		}
		else
		{
			up = c;
			down = d;
			before = b;
			after = a;
			return;
		}
		
	}
	//没有投掷
	else
		return;
}
void ThroughDicing::Through_left_right(int step_num)
{
	int a = up;
	int b = down;
	int c = left;
	int d = right;
	//向左投掷
	if (step_num > 0)
	{
		int n = step_num % 4;
		if (n == 0)return;
		else if (n == 1)
		{
			up = d;
			down = c;
			left = a;
			right = b;
			return;
		}
		else if (n == 2)
		{
			up = b;
			down = a;
			left = d;
			right = c;
			return;
		}
		else
		{
			up = c;
			down = d;
			left = b;
			right = a;
			return;
		}

	}
	//向右投掷
	else if (step_num < 0)
	{
		int n = step_num % 4;
		if (n == 0)return;
		else if (n == -1)
		{
			up = c;
			down = d;
			left = b;
			right = a;
			return;
		}
		else if (n == -2)
		{
			up = b;
			down = a;
			left = d;
			right = c;
			return;
		}
		else
		{
			up = d;
			down = c;
			left = a;
			right = b;
			return;
		}
	}
	//没有投掷
	else
		return;
}
//将字符串s按照delim代表的字符分割，并且放入vector<string>中。
void ThroughDicing::split_string(const char *s, vector<string> &strs, char& delim)
{
	if (s == nullptr)
	{
		return;
	}
	const char *head, *tail;
	head = tail = s;

	while (*head != '\0')
	{
		while (*head != '\0' && *head == delim)
		{
			head++;
		}

		tail = head;
		while (*tail != '\0' && *tail != delim)
		{
			tail++;

		}

		if (head != tail)
		{
			strs.push_back(string(head, tail));
			head = tail;
		}

		else
		{
			break;
		}
	}
}
void ThroughDicing::ReadThroughAction(const string& str, char& delim)
{	
	//const char* convert to char*
	char* strc = new char[strlen(str.c_str()) + 1];
    strcpy(strc, str.c_str());
	vector<string>resultVec;	

	split_string(strc, resultVec, delim);

	delete[] strc;
	size_t len = resultVec.size();
	for (size_t i = 0; i < len;i++)
	{
		
		string ss = resultVec[i];
		if (ss == "前")forward_though.num += 1;
		else if (ss == "后")forward_though.num -= 1;
		else if (ss == "左")left_through.num += 1;
		else left_through.num -= 1;
		
	}	
	
}
void ThroughDicing::Through()
{
	Through_forward_backward(forward_though.num);
	Through_left_right(left_through.num);
}
void ThroughDicing::print_result()
{
	printf("the up face of the dice is:%d\n", up);
	printf("the down face of the dice is:%d\n", down);
	printf("the left face of the dice is:%d\n", left);
	printf("the right face of the dice is:%d\n", right);
	printf("the before face of the dice is:%d\n", before);
	printf("the after face of the dice is:%d\n", after);

}
ThroughDicing::~ThroughDicing()
{
}