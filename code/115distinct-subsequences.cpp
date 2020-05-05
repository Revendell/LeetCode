#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int numDistinct(string s, string t) {
		//基本思想：动态规划法，问次数，就是考虑加法，两个字符串就要考虑二维动态规划
		//dp[i][j]表示s前i的字符可以组成t前j个字符的最多次数，也就是在s前i个字符里面可以找到t前j个字符子序列的个数
		//当s[i]==t[j]，t[j]可以选择匹配s[i]，则dp[i][j]+=dp[i-1][j-1]；当然t[j]也可以选择不匹配s[i]，则dp[i][j]+=dp[i-1][j]
		//当s[i]!=t[j]，t[j]不匹配s[i]，则dp[i][j]+=dp[i-1][j]
		int i, j;
		vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
		//当t为空串，空串在s中出现次数为1
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
		//基本思想：递归，超时
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