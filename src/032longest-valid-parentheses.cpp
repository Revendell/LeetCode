#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
	int longestValidParentheses(string s) {
		//简化版本：栈，栈顶元素为没有匹配的右括号下标或者没有匹配的左括号下标作为分割点，一开始-1入栈为没有匹配的右括号下标
		//遇到(就入栈，遇到)就出栈，如果栈为空说明匹配失败，将没有匹配的右括号下标入栈；
		//如果栈不为空说明匹配成功，当前下标i与栈顶分割点相减就是最长有效括号的长度

		//对于遇到的每个(，我们将它的下标放入栈中
		//对于遇到的每个)，我们先弹出栈顶元素表示匹配了当前右括号：
		//如果栈为空，说明当前的右括号为没有被匹配的右括号，我们将其下标放入栈中来更新我们之前提到的「最后一个没有被匹配的右括号的下标」
		//如果栈不为空，当前右括号的下标减去栈顶元素即为「以该右括号为结尾的最长有效括号的长度」
		int res=0;
		stack<int> st;
		st.push(-1);
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='(')
				st.push(i);
			else
			{
				st.pop();
				if(st.empty())
					st.push(i);
				else
					res=max(res,i-st.top());
			}
		}
		return res;
	}
};
class Solution1 {
public:
	int longestValidParentheses(string s) {
		//基本思想：两头循环的方法，避免了一次循环解决不了的各种特殊情况，两头循环取最大长度。对于(()和()(()的情况
		vector<int> s_stack;
		int res = 0, i, j, counter;
		int s_len = s.length();
		j = -1;
		counter = 0;
		//从头到尾一次循环，采用栈的思想，遇到'('则入栈，遇到')'如果栈顶为'('则出栈，记录字符长度counter++，如果counter大于最大长度res且栈为空，则更新res
		//如果栈不为空更新res，则对于()(()的情况最大字符长度就为4，实际为2。如果没有两头循环，则对于(()的情况最大字符长度为0，实际为2
		for (i = 0; i < s_len; i++)
		{
			//遇到'('则入栈
			if (s[i] == '(')
			{
				s_stack.push_back(s[i]);
				j++;
			}
			//遇到')'如果栈顶为'('则出栈，记录字符长度counter++，如果counter大于最大长度res且栈为空，则更新res
			else if (s[i] == ')')
			{
				if (j >= 0 && s_stack[j] == '(')
				{
					s_stack.pop_back();
					j--;
					counter++;
					if (counter > res&& j == -1)
						res = counter;
				}
				else
				{
					counter = 0;
				}
			}
		}
		j = -1;
		counter = 0;
		s_stack.clear();
		//从尾到头一次循环,如果没有两头循环，则对于(()的情况最大字符长度为0，实际为2
		for (i = s_len-1; i >= 0; i--)
		{
			if (s[i] == ')')
			{
				s_stack.push_back(s[i]);
				j++;
			}
			else if (s[i] == '(')
			{
				if (j >= 0 && s_stack[j] == ')')
				{
					s_stack.pop_back();
					j--;
					counter++;
					if (counter > res&& j == -1)
						res = counter;
				}
				else
				{
					counter = 0;
				}
			}
		}
		return res*2;
	}
};
int main()
{
	Solution solute;
	int res;
	string s = "()(())";
	res = solute.longestValidParentheses(s);
	cout << res << endl;
	return 0;
}