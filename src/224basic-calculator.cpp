#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
#include<stack>
#include<deque>
#include<string>
using namespace std;
class Solution {
public:
	int calculate(string s) {
		//����˼�룺ջ������������ı��ʽ��ջ������ջ�ټ����˼�롣
		//����(������֮��ı��ʽ��ջ������)����ջ�����ֵ��ջ��ֱ��ջΪ�ռӵ�res��
		//flag1����������������������flag2��������������������
		int res = 0;
		int flag1 = 1;
		stack<string> st;
		int i = 0;
		while (i < s.size())
		{
			if (s[i] == '(')
			{
				st.push(s.substr(i,1));
			}
			else if (s[i] == ')')
			{
				deque<string> queue;
				while (st.top() != "(")
				{
					queue.push_front(st.top());
					st.pop();
				}
				st.pop();
				int cur=0, flag2 = 1;
				for (auto v : queue)
				{
					if (v == "+" || v == "-")
						flag2 = v == "+" ? 1 : 0;
					else
						cur += flag2 == 1 ? stoi(v) : -stoi(v);
				}
				if (!st.empty())
					st.push(to_string(cur));
				else
					res += flag1 == 1 ? cur : -cur;
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				if (!st.empty())
					st.push(s.substr(i, 1));
				else
					flag1 = s[i] == '+' ? 1 : 0;
			}
			else if (isdigit(s[i]))
			{
				int num = 0;
				while (isdigit(s[i]))
				{
					num *= 10;
					num += s[i] - '0';
					i++;
				}
				if (!st.empty())
					st.push(to_string(num));
				else
					res += flag1 == 1 ? num : -num;
				continue;
			}
			i++;
		}
		return res;
	}
};
class Solution1 {
public:
	int calculate(string s) {
		//�Ż��汾������˼�룺ջ������������ļ�����res�ͷ���flag��ջ���ȼ�������ջ��˼�롣
		stack<int> st;
		int flag = 1, res = 0;
		int i = 0;
		while (i < s.size())
		{
			if (isdigit(s[i]))
			{
				int num = 0;
				while (isdigit(s[i]))
				{
					num *= 10;
					num += s[i] - '0';
					i++;
				}
				res += flag == 1 ? num : -num;
				continue;
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				flag = s[i] == '+' ? 1 : 0;
			}
			else if (s[i] == '(')
			{
				st.push(res);
				res = 0;
				st.push(flag);
				flag = 1;
			}
			else if (s[i] == ')')
			{
				int flag1 = st.top();
				st.pop();
				int res1 = st.top();
				st.pop();
				res1 += flag1 == 1 ? res : -res;
				res = res1;
			}
			i++;
		}
		return res;
	}
};
int main()
{
	Solution1 solute;
	string s = "  (53-(15-(8-3+4)))   ";
	cout << solute.calculate(s) << endl;
	return 0;
}