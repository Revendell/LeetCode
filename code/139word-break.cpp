#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		//����˼�룺��̬�滮+set�����ڵݹ鳬ʱ���⣬Ӧ���뵽��̬�滮
		unordered_set<string> dict(wordDict.begin(), wordDict.end());  //�ֵ��е��ʱ��浽set�������
		unordered_set<int> Wordlen;  //�ֵ������е��ʳ��ȣ�ÿ��ֻ�Ƚ���Щ�������ַ���
		for (auto& v : wordDict)
			Wordlen.insert(int(v.size()));
		//dp[i+1]��ʾs[0:i]�Ƿ��ܱ����
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for(int i = 0; i < s.size(); i++)
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
		return dp[s.size()];
	}
};
class Solution1 {
public:
	unordered_set<int> Wordlen;  //�ֵ������е��ʳ���
	bool wordBreak(string s, vector<string>& wordDict) {
		//����˼�룺�ݹ飬��ʱ
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