#include"appear_first_time.h"
int main()
{	
	string str;	
	bool case_sentivite;//��Сд���б�־
	printf("�������ַ�����\n");
	getline(cin, str);	
	vector<string>resultRev;
	split_string(str.c_str(), resultRev, ' ');
	str_handle(resultRev, case_sentivite, str);	
	cout << firstSingle(const_cast<char*>(str.c_str()),case_sentivite);
	return 0;
}