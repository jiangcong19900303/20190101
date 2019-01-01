#include"sort.h"
void split_string(const char *s, vector<string> &resultVer, char delim)
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
			resultVer.push_back(string(head, tail));
			head = tail;
		}

		else
		{
			break;
		}
	}
}
void str_handle(vector<string>&vector_input, bool&Flag, string& str)
{
	int len = vector_input.size();
	if (vector_input[0] == "ASCE")//升序
	{
		Flag = true;
		vector_input.erase(vector_input.begin());//删除第一个标志字符串		
	}
	else//降序
	{
		Flag = false;
		vector_input.erase(vector_input.begin());//删除第一个标志字符串

	}
}
vector<int>insert_sort(vector<string>&vector_input,bool isASCE)
{
	if (vector_input.empty())exit(1);//向量为空，退出
	int len = vector_input.size();
	int* NumArray = new int[len];
	vector<int>result;
	for (int i = 0; i < len; i++)
	{
		NumArray[i] = atoi(const_cast<char*>(vector_input[i].c_str()));//把向量中的数字字符串转化成数字
    }
	
		for (int j = 1; j < len; j++)
		{
			int i=j - 1;
			int key = NumArray[j];
			while (i>=0&&NumArray[i]>key)
			{
					NumArray[i + 1] = NumArray[i];					
					i -= 1;				
			}
			NumArray[i + 1] = key;
			
		}
		if(isASCE)//升序
		for (int i = 0; i < len; i++)
		{
			result.push_back(NumArray[i]);
		}
		else//降序
			for (int i = len-1; i>=0; i--)
			{
				result.push_back(NumArray[i]);
			}		
	
	return result;
}
string Splice_string(vector<int>&vector_input)
{
	string str_sorted;
	for (int i = 0; i < vector_input.size(); i++)
	{
		str_sorted.append(to_string(vector_input[i]));
		if (i < vector_input.size() - 1)str_sorted.append(" ");

	}
	return str_sorted;
}
