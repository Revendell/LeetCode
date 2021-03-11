#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
	int longestValidParentheses(string s) {
		//�򻯰汾��ջ��ջ��Ԫ��Ϊû��ƥ����������±����û��ƥ����������±���Ϊ�ָ�㣬һ��ʼ-1��ջΪû��ƥ����������±�
		//����(����ջ������)�ͳ�ջ�����ջΪ��˵��ƥ��ʧ�ܣ���û��ƥ����������±���ջ��
		//���ջ��Ϊ��˵��ƥ��ɹ�����ǰ�±�i��ջ���ָ������������Ч���ŵĳ���

		//����������ÿ��(�����ǽ������±����ջ��
		//����������ÿ��)�������ȵ���ջ��Ԫ�ر�ʾƥ���˵�ǰ�����ţ�
		//���ջΪ�գ�˵����ǰ��������Ϊû�б�ƥ��������ţ����ǽ����±����ջ������������֮ǰ�ᵽ�ġ����һ��û�б�ƥ��������ŵ��±꡹
		//���ջ��Ϊ�գ���ǰ�����ŵ��±��ȥջ��Ԫ�ؼ�Ϊ���Ը�������Ϊ��β�����Ч���ŵĳ��ȡ�
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
		//����˼�룺��ͷѭ���ķ�����������һ��ѭ��������˵ĸ��������������ͷѭ��ȡ��󳤶ȡ�����(()��()(()�����
		vector<int> s_stack;
		int res = 0, i, j, counter;
		int s_len = s.length();
		j = -1;
		counter = 0;
		//��ͷ��βһ��ѭ��������ջ��˼�룬����'('����ջ������')'���ջ��Ϊ'('���ջ����¼�ַ�����counter++�����counter������󳤶�res��ջΪ�գ������res
		//���ջ��Ϊ�ո���res�������()(()���������ַ����Ⱦ�Ϊ4��ʵ��Ϊ2�����û����ͷѭ���������(()���������ַ�����Ϊ0��ʵ��Ϊ2
		for (i = 0; i < s_len; i++)
		{
			//����'('����ջ
			if (s[i] == '(')
			{
				s_stack.push_back(s[i]);
				j++;
			}
			//����')'���ջ��Ϊ'('���ջ����¼�ַ�����counter++�����counter������󳤶�res��ջΪ�գ������res
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
		//��β��ͷһ��ѭ��,���û����ͷѭ���������(()���������ַ�����Ϊ0��ʵ��Ϊ2
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