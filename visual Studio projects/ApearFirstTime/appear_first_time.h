#pragma once
#include <iostream>
#include<vector>
#include<string>
using namespace std;
//���㲢�����ַ����е�һ���״γ��ֵ��ַ�
char firstSingle(char *str, bool case_sensitive);
//�ַ����ָ��������ַ������շָ����ָȻ����뵽vector������
void split_string(const char *s, vector<string> &strs, char delim);

//����ַ���������б�־�ַ���true��false����ȥ��vector_input�е����һ����־λ�ַ���������Flag�ó���Ӧ�ı�ǣ�Ȼ�����������е��ַ�����str
void str_handle(vector<string>&vcetor_input, bool&Flag, string& str);
