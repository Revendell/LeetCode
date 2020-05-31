#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int numDistinct(string s, string t) {
		//����˼�룺��̬�滮�����ʴ��������ǿ��Ǽӷ��������ַ�����Ҫ���Ƕ�ά��̬�滮
		//dp[i][j]��ʾsǰi���ַ��������tǰj���ַ�����������Ҳ������sǰi���ַ���������ҵ�tǰj���ַ������еĸ���
		//��s[i]==t[j]��t[j]����ѡ��ƥ��s[i]����dp[i][j]+=dp[i-1][j-1]����Ȼt[j]Ҳ����ѡ��ƥ��s[i]����dp[i][j]+=dp[i-1][j]
		//��s[i]!=t[j]��t[j]��ƥ��s[i]����dp[i][j]+=dp[i-1][j]
		int i, j;
		vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
		//��tΪ�մ����մ���s�г��ִ���Ϊ1
		for (i = 0; i <= s.size(); i++)
			dp[i][0] = 1;
		for (i = 1; i <= s.size(); i++)
		{
			for (j = 1; j <= t.size(); j++)
			{
				if (s[i - 1] == t[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				else
					dp[i][j]= dp[i - 1][j];
			}
		}
		return dp[s.size()][t.size()];	
	}
};
class Solution1 {
public:
	int res = 0;
	int numDistinct(string s, string t) {
		//����˼�룺�ݹ飬��ʱ
		Recursion(s, t, 0, 0);
		return res;
	}
	void Recursion(string& s, string& t, int i, int j)
	{
		if (j == t.size())
		{
			res++;
			return;
		}
		for (int k = i; k < s.size(); k++)
		{
			if (s[k] == t[j])
			{
				Recursion(s, t, k + 1, j + 1);
			}
		}
	}
};
int main()
{
	Solution solute;
	string S = "babgbag", T = "bag";
	cout << solute.numDistinct(S, T) << endl;
	return 0;
}