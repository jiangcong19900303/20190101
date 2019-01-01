#include"sort.h"
int main()
{
	string str;
	bool isASCE;//升、降序标志
	printf("请输入字符串：\n");
	getline(cin, str);

	vector<string>resultRev;//存放分割后的字符串

	vector<int>sort_result;//存放排序后的结果

	split_string(str.c_str(), resultRev, ' ');//分割字符串
	
	if (resultRev[0] == "ASCE")
	{
		isASCE = true;
		resultRev.erase(resultRev.begin());//去除标志位
	}
	else
	{
		isASCE = false;
		resultRev.erase(resultRev.begin());//去掉标志位
	}
		
	sort_result=insert_sort(resultRev, isASCE);//开始排序
	
	//输出排序后的数字字符串
	cout<<Splice_string(sort_result);
	
	return 0;
}