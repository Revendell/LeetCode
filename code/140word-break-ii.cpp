#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
using namespace std;
class Solution {
public:
	vector<string> res;
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		//基本思想：动态规划+递归回溯，这一题的关键是先判断s是否能拆分，不能拆分直接返回空
		unordered_set<string> dict(wordDict.begin(), wordDict.end());  //字典中单词保存到set方便查找
		unordered_set<int> Wordlen;  //字典中所有单词长度，每次只比较这些长度下字符串
		for (auto& v : wordDict)
			Wordlen.insert(int(v.size()));
		//dp[i+1]表示s[0:i]是否能被拆分
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = 0; i < s.size(); i++)
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
		if (dp[s.size()] == false)
			return res;
		string cur;
		//递归回溯生成拆分之后的字符串cur，保存至res
		Recursion(s, dict, 0, cur, dp);
		return res;
	}
	void Recursion(string& s, unordered_set<string>& dict, int pos, string cur, vector<bool>& dp)
	{
		if (pos == s.size())
		{
			cur.pop_back();
			res.push_back(cur);
			return;
		}
		for (int i = pos; i < s.size(); i++)
		{
			if (dp[pos] == true && dict.find(s.substr(pos, i - pos + 1)) != dict.end())
			{
				string temp = cur;
				cur += s.substr(pos, i - pos + 1);
				cur += " ";
				Recursion(s, dict, i + 1, cur, dp);
				cur = temp;
			}
		}
	}
};
int main()
{
	Solution solute;
	string s = "pineapplepenapple";
	vector<string> wordDict = { "apple", "pen", "applepen", "pine", "pineapple" };
	vector<string> res = solute.wordBreak(s, wordDict);
	for_each(res.begin(), res.end(), [](const string& v) {cout << v << endl; });
	return 0;
}