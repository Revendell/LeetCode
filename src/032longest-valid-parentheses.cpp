#include<iostream>
#include<vector>
using namespace std;
class Solution {
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