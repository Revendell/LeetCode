#include<algorithm>
#include<vector>
#include<iostream>
#include<list>
using namespace std;
class Solution {
public:
	int minCut(string s) {
		//基本思想：动态规划，dp[i]表示前i个字符分割的最小次数
		vector<int> dp(s.size()+1,0);
		for (int i = 0; i <= s.size(); i++)
			dp[i]=i-1;
		for(int i=0;i<s.size();i++)
		{
			for(int j=0;j<=i;j++)
			{
				if(check(s,j,i))
					dp[i+1]=min(dp[i+1],dp[j]+1);
			}
		}
		return dp[s.size()];
	}
	bool check(string &s,int left,int right)
	{
		while(left<right)
		{
			if(s[left]!=s[right])
				return false;
			left++;
			right--;
		}
		return true;
	}
};
class Solution1 {
public:
	vector<int> dp;
	int minCut(string s) {
		//基本思想：动态规划+中心扩展，定义dp[i]表示将s[0:i]分割成回文子串的最小分割次数
		//注意dp[i]是截止s[i]，比如对于aba的dp就是010而不是000
		//遍历s中每个字符，以该字符为中心向两边扩展，扩展过程中不断更新dp[right] = min(dp[right], dp[left - 1] + 1);
		if (s.size() == 0)
			return 0;
		//初始化dp
		for (int i = 0; i < s.size(); i++)
			dp.push_back(i);
		//遍历s中每个字符，以该字符为中心向两边扩展，扩展过程中不断更新dp
		for (int i = 0; i < s.size(); i++)
		{
			Recursion(s, i, i);    //回文串奇数情况
			Recursion(s, i, i + 1);    //回文串偶数情况
		}
		return dp[s.size() - 1];
	}
	void Recursion(string& s, int left, int right)
	{
		if (right == s.size() || left == -1)
			return;
		//如果s[left]=s[right]，则s[left:right]之间的字符组成一个回文串，那么dp[right]=min(dp[right],dp[left-1]+1)
		if (s[left] == s[right])
		{
			if (left == 0)
				dp[right] = min(dp[right], 0);
			else
				dp[right] = min(dp[right], dp[left - 1] + 1);
			Recursion(s, left - 1, right + 1);
		}
	}
};
int main()
{
	Solution solute;
	string s = "didbhbd";
	cout << solute.minCut(s) << endl;
	return 0;
}