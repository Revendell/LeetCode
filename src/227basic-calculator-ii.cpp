#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
    int calculate(string s) {
		//简化版：栈，先入栈后计算，因为*/优先级高于+-，只有知道后一个符号是什么前面的符号才能计算结果
        istringstream is(s);
        stack<int> st;
        int res=0,num;
        char c,pre_op='+';
        while(is>>num)
        {
            is>>c;
            if(pre_op=='+')
                st.push(num);
            else if(pre_op=='-')
                st.push(-num);
            else if(pre_op=='*')
                st.top()*=num;
            else if(pre_op=='/')
                st.top()/=num;
            pre_op=c;
        }
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        return res;
    }
};
class Solution1 {
public:
	int calculate(string s) {
		//基本思想：栈，先计算再入栈的思想，nums保存数字的栈，sigh保存符号的栈
		//如果遇到数字，先判断前一个符号，如果是加减，则数字入栈，因为后面可能是乘除不能直接计算；如果是乘除，直接计算结果
		//如果遇到加减，计算前一个符号的结果
		//如果遇到乘除，符号入栈
		stack<int> nums;
		stack<char> sigh;
		int i = 0;
		while (i < s.size() || !sigh.empty())
		{
			if (i == s.size())
			{
				int a = nums.top(); nums.pop();
				int b = nums.top(); nums.pop();
				int temp = sigh.top() == '+' ? b + a : b - a;
				sigh.pop();
				nums.push(temp);
			}
			if (isdigit(s[i]))
			{
				int num = 0;
				while (isdigit(s[i]))
				{
					num *= 10;
					num += s[i] - '0';
					i++;
				}
				if(sigh.empty())
				    nums.push(num);
				else
				{
					if(sigh.top() == '+' || sigh.top() == '-')
						nums.push(num);
					else
					{
						int a = nums.top(); nums.pop();
						int temp = sigh.top() == '*' ? a * num : a / num;
						sigh.pop();
						nums.push(temp);
					}
				}
				continue;
			}
			else if (s[i] == '-'|| s[i] == '+')
			{
				if (sigh.empty())
					sigh.push(s[i]);
				else
				{
					int a = nums.top(); nums.pop();
					int b = nums.top(); nums.pop();
					int temp = sigh.top() == '-' ? b - a : b + a;
					sigh.pop();
					sigh.push(s[i]);
					nums.push(temp);
				}
			}
			else if (s[i] == '*' || s[i] == '/')
			{
				sigh.push(s[i]);
			}
			i++;
		}
		return nums.top();
	}
};
class Solution2 {
public:
	int calculate(string s) {
		//基本思想：栈，优化，先入栈再计算的思想，这个问题的关键是先乘除后加减，只有知道后一个符号是什么前面的符号才能计算结果
		//所以设一个变量pre_op保存前一个符号，先把乘除法的值计算出来，最终将所有的运算简化成只有加法
		s += '#';    //占位，为了最后一个数字也能被计算
		stack<int> nums;
		char pre_op = '+';
		int num = 0, res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if(s[i] == ' ')
				continue;
			else if (isdigit(s[i]))
			{
				num *= 10;
				num += s[i] - '0';
			}
			else
			{
				switch (pre_op)
				{
				case '+':
					nums.push(num);
					break;
				case '-':
					nums.push(-num);
					break;
				case '*':
					nums.top() *= num;
					break;
				case '/':
					nums.top() /= num;
					break;
				}
				pre_op = s[i];
				num = 0;
			}
		}
		while (!nums.empty())
		{
			res += nums.top();
			nums.pop();
		}
		return res;
	}
};
int main()
{
	Solution1 solute;
	string s = " 3+5 / 2 ";
	cout << solute.calculate(s) << endl;
	return 0;
}