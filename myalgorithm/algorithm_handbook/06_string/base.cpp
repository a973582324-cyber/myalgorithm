// 定长字符数组实现的基础字符串类型，以 '\0' 标记有效内容结尾。
// 所有写操作都必须为结尾标记预留一个位置，因此最大有效长度为 MAX-1。
#include<iostream>
using namespace std;
const int MAX = 100;
struct String
{
	char data[MAX];
	String()
	{
		data[0] = '\0';
	}
};
int getlength(String s)
{
	int len = 0;
	for (int i = 0;s.data[i] != '\0';i++)
		len++;
	return len;
}
bool operator== (String a, String b)
{
	if (getlength(a) != getlength(b))
		return false;
	else
	{
		int n = getlength(a);
		for (int i = 0;i < n;i++)
		{
			if (a.data[i] != b.data[i])
				return false;
		}
		return true;
	}
}
void insert(String& s, char c)
{
	int i = getlength(s);
	if (i == MAX - 1)
	{
		cout << "满了" << endl;
	}
	else
	{
		s.data[i] = c;
		s.data[++i] = '\0';
	}
}
bool StrCompare(String s1, String s2)
{
	if (s1 == s2)return true;
	else
		return false;
}
void substring(String& s, String ss, int index, int len)
{
	int l = 0;
	for (int i = len;i > 0;i--)
	{
		s.data[l++] = ss.data[index++];
	}
	s.data[l] = '\0';
}
int Index(String s,String t,int pos)//实现查找主串s第pos个字符之后是否存在字串t，若存在则返回第一个下标
{
	int n, m, i;
	n = getlength(s);//得到主串长度
	m = getlength(t);//得到字串长度
	if (pos > 0)
	{
		i = pos - 1;
		while (i <= n - m + 1)
		{
			String sub;
			substring(sub, s, i, m);//sub取主串的第i个位置之后相等的字串

			if (StrCompare(sub, t))//判断两个字串是否相等
				return i+1;
			else
				i++;
		}
	}
	return 0;
}
int main()
{
	String s;
	String t;
	insert(s, 'a');
	insert(s, 'b');
	insert(s, 'c');
	insert(t, 'a');
	cout<<Index(s, t, 2);
	return 0;
}
