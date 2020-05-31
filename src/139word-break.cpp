#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		//基本思想：动态规划+set，对于递归超时的题，应该想到动态规划
		unordered_set<string> dict(wordDict.begin(), wordDict.end());  //字典中单词保存到set方便查找
		unordered_set<int> Wordlen;  //字典中所有单词长度，每次只比较这些长度下字符串
		for (auto& v : wordDict)
			Wordlen.insert(int(v.size()));
		//dp[i+1]表示s[0:i]是否能被拆分
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for(int i = 0; i < s.size(); i++)
		{
			//以s[i]字符起始Wordlen为长度截取的s字符串，若存在于dict，则dp[i+(*it)]=dp[i+(*it)]||dp[i]
			for (auto it = Wordlen.begin(); it != Wordlen.end(); it++)
			{
				if (i + (*it) - 1 < s.size() && dict.find(s.substr(i, *it)) != dict.end())
				{
					dp[i + (*it)] = dp[i + (*it)] || dp[i];
				}
			}
		}
		return dp[s.size()];
	}
};
class Solution1 {
public:
	unordered_set<int> Wordlen;  //字典中所有单词长度
	bool wordBreak(string s, vector<string>& wordDict) {
		//基本思想：递归，超时
		unordered_set<string> dict(wordDict.begin(), wordDict.end());
		for (auto& v : wordDict)
			Wordlen.insert(int(v.size()));
		return Recursion(s, dict, 0);

	}
	bool Recursion(string& s, unordered_set<string>& dict, int pos)
	{
		if (pos == s.size())
			return true;
		for (auto it = Wordlen.begin(); it != Wordlen.end(); it++)
		{
			if (pos + (*it) - 1 < s.size() && dict.find(s.substr(pos, *it)) != dict.end())
			{
				if (Recursion(s, dict, pos + (*it)))
					return true;
			}
		}
		return false;
	}
};
int main()
{
	Solution solute;
	string s = "aaaaaaa";
	vector<string> wordDict = { "aaaa", "aaa" };
	cout << solute.wordBreak(s, wordDict) << endl;
	return 0;
}