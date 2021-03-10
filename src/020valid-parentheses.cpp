#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		//简化版
		stack<char> st;
		for(auto c:s)
		{
			if(c == '(' || c == '[' || c == '{')
				st.push(c);
			else if(c == ')')
			{
				if(!st.empty()&&st.top()=='(')
					st.pop();
				else
					return false;
			}
			else if(c == '}')
			{
				if(!st.empty()&&st.top()=='{')
					st.pop();
				else
					return false;
			}
			else if(c == ']')
			{
				if(!st.empty()&&st.top()=='[')
					st.pop();
				else
					return false;
			}
		}
		return st.empty();
	}
};
class Solution1 {
public:
	bool isValid(string s) {
		vector<char> s_stack;  //建立栈
		int len = s.size();
		int i, j=-1;  //j指向栈顶元素
		//一次处理字符串s中的每个括号
		for (i = 0; i < len; i++)
		{
			//如果遇到开括号，将其入栈
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				s_stack.push_back(s[i]);
				j++;
			}
			//如果遇到闭括号，检查栈顶元素。如果栈顶的元素是一个相同类型的左括号，那么将它从栈中弹出并继续处理，否则，匹配出错返回false
			else if(s[i] == ')')
			{
				if (j >= 0 && s_stack[j] == '(')
				{
					s_stack.pop_back();
					j--;
				}
				else
					return false;
			}
			else if (s[i] == ']')
			{
				if (j >= 0 && s_stack[j] == '[')
				{
					s_stack.pop_back();
					j--;
				}
				else
					return false;
			}
			else if (s[i] == '}')
			{
				if (j >= 0 && s_stack[j] == '{')
				{
					s_stack.pop_back();
					j--;
				}
				else
					return false;
			}
		}
		//如果所有字符处理完毕，栈中仍然有元素，说明表达式无效返回false
		if (j < 0)
			return true;
		else
			return false;

	}
};
int main()
{
	string s = "{[]}}";
	Solution solute;
	cout << solute.isValid(s) << endl;
	return 0;
}