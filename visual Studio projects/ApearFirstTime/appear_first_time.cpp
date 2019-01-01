#include"appear_first_time.h"
//计算并返回字符串中第一个首次出现的字符
char firstSingle(char *str, bool case_sensitive)
{
	int a[255];
	memset(a, 0, sizeof(a));

	//复制保存一份原始字符数据
	char* origin_str = new char[strlen(str) + 1];
	strcpy(origin_str, str);

	char *p = str;

	//用hash表统计每个字符的出现次数
	while (*p != '\0')
	{
		if (case_sensitive == false)//大小写不敏感
		{
			if (*p >= 'a'&&*p <= 'z')//判断字符是小写字符，则转换为大写字符
				*p -= 32;//小写转大写
			a[*p]++;//以字符key的ASCII值作为数组下标，字符key到其ASCII值的映射是哈希函数。字符可以作为整数直接使用。
			p++;
		}
		else //大小写敏感
		{
			a[*p]++;//以字符key的ASCII值作为数组下标，字符key到其ASCII值的映射是哈希函数。字符可以作为整数直接使用。
			p++;
		}

	}

	p = str;
	char* p_tmp = origin_str;
	while (*p != '\0'&&p_tmp != '\0')  //如果不是链表尾
	{

		if (a[*p] == 1)//找到第一个仅出现一次的元素
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
//字符串分割，把输入的字符串按照分隔符分割，然后存入到vector变量中
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

//如果字符串的最后有标志字符串true或false，则去掉vector_input中的最后一个标志位字符串，并把Flag置成相应的标记，然后并向量容器中的字符串到str
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
