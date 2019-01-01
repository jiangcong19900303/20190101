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
	if (vector_input[0] == "ASCE")//����
	{
		Flag = true;
		vector_input.erase(vector_input.begin());//ɾ����һ����־�ַ���		
	}
	else//����
	{
		Flag = false;
		vector_input.erase(vector_input.begin());//ɾ����һ����־�ַ���

	}
}
vector<int>insert_sort(vector<string>&vector_input,bool isASCE)
{
	if (vector_input.empty())exit(1);//����Ϊ�գ��˳�
	int len = vector_input.size();
	int* NumArray = new int[len];
	vector<int>result;
	for (int i = 0; i < len; i++)
	{
		NumArray[i] = atoi(const_cast<char*>(vector_input[i].c_str()));//�������е������ַ���ת��������
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
		if(isASCE)//����
		for (int i = 0; i < len; i++)
		{
			result.push_back(NumArray[i]);
		}
		else//����
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
