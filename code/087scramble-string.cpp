#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1.size() != s2.size())
			return false;
		//����˼�룺�ݹ鷨���������п��ܵķָ�����ָ��i��1��s1.size-1����s1�ָ��[0,i)[i,s1.size)
		//��Ӧs2ƥ�������[0,i)[i,s1.size)Ҳ������[s2.size-i,s2.size)[0,s2.size()-i)
		//Ȼ�󲻶ϵݹ�ָ���Ӵ�ֱ��s1=s2����true
		return Recursion(s1, s2);
	}
	bool Recursion(string s1, string s2)
	{
		if (s1 == s2)
			return true;
		//��ֹ��ʱ����s1�������ַ���s2�в������ڣ�˵��s1������ô�ָ��s2�޷�ƥ�䣬ֱ�ӷ���false������Ż�Ч��
		string t1 = s1, t2 = s2;
		sort(t1.begin(), t1.end());
		sort(t2.begin(), t2.end());
		if (t1 != t2)
			return false;
		//i��1��s1.size-1�����ܴ��±�0��ʼ�����ٷָ�1���ַ������������޷�����ѭ��
		for (int i = 1; i < s1.size(); i++)
		{
			//��s1�ָ��[0,i)[i,s1.size)��Ӧs2ƥ�������[0,i)[i,s1.size)Ҳ������[s2.size-i,s2.size)[0,s2.size()-i)
			bool flag1 = Recursion(s1.substr(0, i), s2.substr(0, i)) && Recursion(s1.substr(i,s1.size()-i), s2.substr(i,s2.size()-i));
			bool flag2 = Recursion(s1.substr(0, i), s2.substr(s2.size() - i, i)) && Recursion(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i));
			if (flag1 || flag2)
				return true;
		}
		return false;
	}
};
int main()
{
	Solution solute;
	string s1 = "abcd";
	string s2 = "cadb";
	cout << solute.isScramble(s1, s2) << endl;
	return 0;
}