#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
    int calculate(string s) {
		//�򻯰棺ջ������ջ����㣬��Ϊ*/���ȼ�����+-��ֻ��֪����һ��������ʲôǰ��ķ��Ų��ܼ�����
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
		//����˼�룺ջ���ȼ�������ջ��˼�룬nums�������ֵ�ջ��sigh������ŵ�ջ
		//����������֣����ж�ǰһ�����ţ�����ǼӼ�����������ջ����Ϊ��������ǳ˳�����ֱ�Ӽ��㣻����ǳ˳���ֱ�Ӽ�����
		//��������Ӽ�������ǰһ�����ŵĽ��
		//��������˳���������ջ
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
		//����˼�룺ջ���Ż�������ջ�ټ����˼�룬�������Ĺؼ����ȳ˳���Ӽ���ֻ��֪����һ��������ʲôǰ��ķ��Ų��ܼ�����
		//������һ������pre_op����ǰһ�����ţ��Ȱѳ˳�����ֵ������������ս����е�����򻯳�ֻ�мӷ�
		s += '#';    //ռλ��Ϊ�����һ������Ҳ�ܱ�����
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