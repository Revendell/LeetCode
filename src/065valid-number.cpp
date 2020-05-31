#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool isNumber(string s) {
		//����˼�룺�������������̡��״�������true��".1"��"-.1"��"1."��" 005"��false��"."��"+e"��"+3. e04116"
		int i, flag = 0;
		//ȥ����ͷ�ո�
		remove_space(s, 0);
		if (s.empty())
			return false;
		//ȥ����ͷ+-��
		remove_sighed(s, 0);
		if (s.empty())
			return false;
		//s������.��1-9��ͷ
		if ((s[0] >= '0' && s[0] <= '9') || s[0]=='.')
		{
			i = 0;
			while (i < s.size() && s[i] >= '0' && s[i] <= '9')
			{
				i++;
				flag = 1;
			}
			//sΪ����
			if (i == s.size())
				return true;
			if (s[i] == ' ')
			{
				remove_space(s, i);
				if (i == s.size())
					return true;
				else
					return false;
			}
			//sΪ������ѧ����
			if (s[i] == 'e')
				return check_e(s, i);
			//sΪ������
			if (s[i] == '.')
			{
				i++;
				//sΪ������1.���
				if (i < s.size() && s[i] == ' ')
				{
					remove_space(s, i);
					if (i == s.size() && flag==1)
						return true;
					else
						return false;
				}
				//sΪ������1.1���
				while (i < s.size() && s[i] >= '0' && s[i] <= '9')
				{
					i++;
					flag = 1;
				}
				if (flag == 0)
					return false;
				remove_space(s, i);
				if (i == s.size())
					return true;
				//sΪ��������ѧ����1.1e2���
				if (s[i] == 'e')
					return check_e(s, i);
				else
					return false;
			}
			return false;
		}
		return false;
	}
	//����ȥ��+-��
	void remove_sighed(string& s, int i)
	{
		if (i < s.size() && (s[i] == '+' || s[i] == '-'))
			s.erase(i, 1);
	}
	//����ȥ����ͷ�ͽ�β�����ո�
	void remove_space(string& s,int i)
	{
		int start = i;
		while (i < s.size() && s[i] == ' ')
			i++;
		s.erase(start, i - start);
	}
	//����ǿ�ѧ����������Ƿ������ѧ������
	bool check_e(string& s, int i)
	{
		if (i == s.size() - 1)
			return false;
		i++;
		remove_sighed(s, i);
		remove_space(s, i);
		if (i == s.size())
			return false;
		if (s[i] < '0' || s[i] > '9')
			return false;
		while (i < s.size() && s[i] >= '0' && s[i] <= '9')
			i++;
		remove_space(s, i);
		if (i == s.size())
			return true;
		else
			return false;
	}
};
int main()
{
	Solution solute;
	string s = "+3. e04116";
	cout << solute.isNumber(s) << endl;
	return 0;
}