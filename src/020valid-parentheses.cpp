#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		//�򻯰�
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
		vector<char> s_stack;  //����ջ
		int len = s.size();
		int i, j=-1;  //jָ��ջ��Ԫ��
		//һ�δ����ַ���s�е�ÿ������
		for (i = 0; i < len; i++)
		{
			//������������ţ�������ջ
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				s_stack.push_back(s[i]);
				j++;
			}
			//������������ţ����ջ��Ԫ�ء����ջ����Ԫ����һ����ͬ���͵������ţ���ô������ջ�е�����������������ƥ�������false
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
		//��������ַ�������ϣ�ջ����Ȼ��Ԫ�أ�˵�����ʽ��Ч����false
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