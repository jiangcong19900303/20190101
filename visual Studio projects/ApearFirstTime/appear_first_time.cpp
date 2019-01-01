#include"appear_first_time.h"
//���㲢�����ַ����е�һ���״γ��ֵ��ַ�
char firstSingle(char *str, bool case_sensitive)
{
	int a[255];
	memset(a, 0, sizeof(a));

	//���Ʊ���һ��ԭʼ�ַ�����
	char* origin_str = new char[strlen(str) + 1];
	strcpy(origin_str, str);

	char *p = str;

	//��hash��ͳ��ÿ���ַ��ĳ��ִ���
	while (*p != '\0')
	{
		if (case_sensitive == false)//��Сд������
		{
			if (*p >= 'a'&&*p <= 'z')//�ж��ַ���Сд�ַ�����ת��Ϊ��д�ַ�
				*p -= 32;//Сдת��д
			a[*p]++;//���ַ�key��ASCIIֵ��Ϊ�����±꣬�ַ�key����ASCIIֵ��ӳ���ǹ�ϣ�������ַ�������Ϊ����ֱ��ʹ�á�
			p++;
		}
		else //��Сд����
		{
			a[*p]++;//���ַ�key��ASCIIֵ��Ϊ�����±꣬�ַ�key����ASCIIֵ��ӳ���ǹ�ϣ�������ַ�������Ϊ����ֱ��ʹ�á�
			p++;
		}

	}

	p = str;
	char* p_tmp = origin_str;
	while (*p != '\0'&&p_tmp != '\0')  //�����������β
	{

		if (a[*p] == 1)//�ҵ���һ��������һ�ε�Ԫ��
		{
			char c = *p_tmp;
			return c;
		}
		p++;
		p_tmp++;
	}
	delete[] origin_str;
	return '\0';
}
//�ַ����ָ��������ַ������շָ����ָȻ����뵽vector������
void split_string(const char *s, vector<string> &strs, char delim)
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

//����ַ���������б�־�ַ���true��false����ȥ��vector_input�е����һ����־λ�ַ���������Flag�ó���Ӧ�ı�ǣ�Ȼ�����������е��ַ�����str
void str_handle(vector<string>&vcetor_input, bool&Flag, string& str)
{
	int len = vcetor_input.size();
	if (len>1 && vcetor_input[len - 1] == "true")
	{
		Flag = true;
		vcetor_input.pop_back();
		str.clear();
		for (int i = 0; i < len - 1; i++)
		{
			str.append(vcetor_input[i]);
		}
	}
	else
	{
		Flag = false;
		str.clear();
		for (int i = 0; i < len; i++)
		{
			str.append(vcetor_input[i]);
		}

	}
}
