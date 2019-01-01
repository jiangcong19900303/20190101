#pragma once
#include <iostream>
#include<vector>
#include<string>
using namespace std;
//计算并返回字符串中第一个首次出现的字符
char firstSingle(char *str, bool case_sensitive);
//字符串分割，把输入的字符串按照分隔符分割，然后存入到vector变量中
void split_string(const char *s, vector<string> &strs, char delim);

//如果字符串的最后有标志字符串true或false，则去掉vector_input中的最后一个标志位字符串，并把Flag置成相应的标记，然后并向量容器中的字符串到str
void str_handle(vector<string>&vcetor_input, bool&Flag, string& str);
