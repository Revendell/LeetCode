#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		//基本思想：HashMap，HashMap建立s[i]字符到t[i]字符的映射
		unordered_map<char, char> HashMap;
		for (int i = 0; i < s.size(); i++)
		{
			if (HashMap.find(s[i]) == HashMap.end())
			{
				for (auto v : HashMap)
				{
					if (v.second == t[i])
						return false;
				}
				HashMap[s[i]] = t[i];
			}
			else
			{
				if (HashMap[s[i]] != t[i])
					return false;
			}
		}
		return true;
	}
};
int main()
{
	Solution solute;
	string s = "egg", t = "add";
	cout << solute.isIsomorphic(s, t) << endl;
	return 0;
}