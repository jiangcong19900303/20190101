#include"sort.h"
int main()
{
	string str;
	bool isASCE;//���������־
	printf("�������ַ�����\n");
	getline(cin, str);

	vector<string>resultRev;//��ŷָ����ַ���

	vector<int>sort_result;//��������Ľ��

	split_string(str.c_str(), resultRev, ' ');//�ָ��ַ���
	
	if (resultRev[0] == "ASCE")
	{
		isASCE = true;
		resultRev.erase(resultRev.begin());//ȥ����־λ
	}
	else
	{
		isASCE = false;
		resultRev.erase(resultRev.begin());//ȥ����־λ
	}
		
	sort_result=insert_sort(resultRev, isASCE);//��ʼ����
	
	//��������������ַ���
	cout<<Splice_string(sort_result);
	
	return 0;
}