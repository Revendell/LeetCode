#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int minDistance(string word1, string word2) {
		//基本思想：动态规划法，dp[i][j]表示word1前i个字符转换成word2前j个字符需要的最少步数
		vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
		int i, j;
		if (word1.size() == 0 || word2.size() == 0)
			return max(word1.size(), word2.size());
		for (i = 1; i <= word1.size(); i++)
			dp[i][0] = i;
		for (j = 1; j <= word2.size(); j++)
			dp[0][j] = j;
		for (i = 1; i <= word1.size(); i++)
		{
			for (j = 1; j <= word2.size(); j++)
			{
				//当前word1[i]与word2[j]字符相等，则dp[i][j]=dp[i-1][j-1]
				if (word1[i-1] == word2[j-1])
					dp[i][j] = dp[i - 1][j - 1];
				//当前word1[i]与word2[j]字符相等，为了使word1转换为word2，三种方法里最少步数
				//一可以删除word1[i]字符，dp[i][j]=dp[i-1][j]+1
				//二可以把word1[i]替换成word2[j]，dp[i][j]=dp[i-1][j-1]+1
				//三可以插入word2[j]字符，dp[i][j]=dp[i][j-1]+1
				else
					dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
			}
		}
		return dp[word1.size()][word2.size()];
	}
};
class Solution1 {
public:
	int res;
	int minDistance(string word1, string word2) {
		//基本思想：递归回溯法，超时
		res = max(word1.size(), word2.size());
		Recursion(word1, word2, 0, 0, -1, -1, 0);
		return res;
	}
	void Recursion(string word1, string word2, int i, int j, int prei, int prej, int cnt)
	{
		if (i == word1.size() || j == word2.size())
		{
			cnt += max(word1.size() - prei - 1, word2.size() - prej - 1);
			if (cnt < res)
				res = cnt;
			return;
		}
		if (word1[i] == word2[j])
		{
			cnt += max(i - prei - 1, j - prej - 1);
			//剪枝
			if (cnt > res)
				return;
			prei = i;
			prej = j;
			Recursion(word1, word2, i + 1, j + 1, prei, prej, cnt);
		}
		else
		{
			Recursion(word1, word2, i, j + 1, prei, prej, cnt);
			Recursion(word1, word2, i + 1, j, prei, prej, cnt);
		}
		return;
	}
};
int main()
{
	Solution solute;
	string word1 = "horse";
	string word2 = "ros";
	cout << solute.minDistance(word1, word2) << endl;
	return 0;
}