#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		//基本思想：二维动态规划法，dp[i][j] 表示 s1[0-i]+s2[0-j] 是否能够组成 s3[0-(i+j)]
		//if(s3[k]==s1[i]) dp[i][j]=dp[i-1][j]
		//if(s3[k] == s2[j]) dp[i][j] = dp[i][j - 1]
		//if((s3[k] == s1[i]) && (s3[k] == s2[j])) dp[i][j] = dp[i - 1][j] || dp[i][j - 1]
		if (s1.size() + s2.size() != s3.size()) 
			return false;
		vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
		int pos1 = 0, pos2 = 0, pos3 = 0;
		dp[0][0] = true;
		while (pos1 < s1.size() && s1[pos1++] == s3[pos3++])
		{
			dp[pos1][0] = true;
		}
		pos3 = 0;
		while (pos2 < s2.size() && s2[pos2++] == s3[pos3++])
		{
			dp[0][pos2] = true;
		}
		for(pos1 = 0; pos1 < s1.size(); pos1++)
		{
			for (pos2 = 0; pos2 < s2.size(); pos2++)
			{
				if (s1[pos1] == s3[pos1 + pos2 + 1])
				{
					dp[pos1 + 1][pos2 + 1] = dp[pos1][pos2 + 1];
				}
				if (s2[pos2] == s3[pos1 + pos2 + 1])
				{
					dp[pos1 + 1][pos2 + 1] = dp[pos1 + 1][pos2];
				}
				if (s1[pos1] == s3[pos1 + pos2 + 1] && s2[pos2] == s3[pos1 + pos2 + 1])
				{
					dp[pos1 + 1][pos2 + 1] = dp[pos1][pos2 + 1] || dp[pos1 + 1][pos2];
				}
			}
		}
		return dp[s1.size()][s2.size()];
	}
};
class Solution1 {
public:
	bool isInterleave(string s1, string s2, string s3) {
		//基本思想：递归法，超时，递归遍历所有s1s2交错匹配s3的可能情况
		if (s1.size() == 0)
			return s2 == s3;
		if (s2.size() == 0)
			return s1 == s3;
		if (s1.size() + s2.size() != s3.size())
			return false;
		return Recursion(s1, s2, s3, 0, 0, 0);
	}
	bool Recursion(string &s1, string &s2, string &s3, int pos1, int pos2, int pos3)
	{
		if (pos1 == s1.size() && pos2 == s2.size() && pos3 == s3.size())
		{
			return true;
		}
		if (pos1 < s1.size() && s1[pos1] == s3[pos3])
		{
			if (Recursion(s1, s2, s3, pos1 + 1, pos2, pos3 + 1))
				return true;
		}
		if (pos2 < s2.size() && s2[pos2] == s3[pos3])
		{
			if (Recursion(s1, s2, s3, pos1, pos2 + 1, pos3 + 1))
				return true;
		}
		return false;
	}
};
int main()
{
	Solution solute;
	string s1 = "ab", s2 = "bc", s3 = "bbac";
	cout << solute.isInterleave(s1, s2, s3) << endl;
	return 0;
}