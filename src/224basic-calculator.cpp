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
		//基本思想：栈，将括号里面的表达式入栈。先入栈再计算的思想。
		//遇到(，将其之后的表达式入栈；遇到)，出栈计算的值入栈，直至栈为空加到res上
		//flag1用来标记括号外面的正负，flag2用来标记括号里面的正负
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
		//优化版本，基本思想：栈，将括号外面的计算结果res和符号flag入栈。先计算再入栈的思想。
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