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
		//����˼�룺��̬�滮+�ݹ���ݣ���һ��Ĺؼ������ж�s�Ƿ��ܲ�֣����ܲ��ֱ�ӷ��ؿ�
		unordered_set<string> dict(wordDict.begin(), wordDict.end());  //�ֵ��е��ʱ��浽set�������
		unordered_set<int> Wordlen;  //�ֵ������е��ʳ��ȣ�ÿ��ֻ�Ƚ���Щ�������ַ���
		for (auto& v : wordDict)
			Wordlen.insert(int(v.size()));
		//dp[i+1]��ʾs[0:i]�Ƿ��ܱ����
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = 0; i < s.size(); i++)
		{
			//��s[i]�ַ���ʼWordlenΪ���Ƚ�ȡ��s�ַ�������������dict����dp[i+(*it)]=dp[i+(*it)]||dp[i]
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
		//�ݹ�������ɲ��֮����ַ���cur��������res
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