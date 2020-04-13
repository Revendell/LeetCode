#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool isNumber(string s) {
		//基本思想：面向测试用例编程。易错用例：true：".1"、"-.1"、"1."、" 005"；false："."、"+e"、"+3. e04116"
		int i, flag = 0;
		//去除开头空格
		remove_space(s, 0);
		if (s.empty())
			return false;
		//去除开头+-号
		remove_sighed(s, 0);
		if (s.empty())
			return false;
		//s必须以.或1-9开头
		if ((s[0] >= '0' && s[0] <= '9') || s[0]=='.')
		{
			i = 0;
			while (i < s.size() && s[i] >= '0' && s[i] <= '9')
			{
				i++;
				flag = 1;
			}
			//s为整数
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
			//s为整数科学计数
			if (s[i] == 'e')
				return check_e(s, i);
			//s为浮点数
			if (s[i] == '.')
			{
				i++;
				//s为浮点数1.情况
				if (i < s.size() && s[i] == ' ')
				{
					remove_space(s, i);
					if (i == s.size() && flag==1)
						return true;
					else
						return false;
				}
				//s为浮点数1.1情况
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
				//s为浮点数科学计数1.1e2情况
				if (s[i] == 'e')
					return check_e(s, i);
				else
					return false;
			}
			return false;
		}
		return false;
	}
	//用于去除+-号
	void remove_sighed(string& s, int i)
	{
		if (i < s.size() && (s[i] == '+' || s[i] == '-'))
			s.erase(i, 1);
	}
	//用于去除开头和结尾连续空格
	void remove_space(string& s,int i)
	{
		int start = i;
		while (i < s.size() && s[i] == ' ')
			i++;
		s.erase(start, i - start);
	}
	//如果是科学计数，检查是否满足科学计数法
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