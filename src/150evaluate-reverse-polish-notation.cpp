#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		//基本思想：栈
		stack<int> st;
		int a, b, ans;
		for (auto& s : tokens)
		{
			if (s == "+" || s == "-" || s == "*" || s == "/")
			{
				b = st.top();
				st.pop();
				a = st.top();
				st.pop();
				switch (s[0])
				{
				case '+':
					ans = a + b;
					break;
				case '-':
					ans = a - b;
					break;
				case '*':
					ans = a * b;
					break;
				case '/':
					ans = a / b;
					break;
				default:
					break;
				}
				st.push(ans);
			}
			else
			{
				st.push(stoi(s));
			}
		}
		if (!st.empty())
			return st.top();
		else
			return 0;
	}
};
int main()
{
	Solution solute;
	vector<string> tokens = { "2", "1", "+", "3", "*" };
	cout << solute.evalRPN(tokens) << endl;
	return 0;
}