#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
using namespace std;
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		//基本思想：窗口切片+HashSet，对s进行窗口滑动切片，每次切片大小为10个字符串保存到set
		//如果下次切片在set中已经出现过，说明超过1次，加入res，res也是set防止重复出现的切片串
		//时间复杂度O((N-L)L)空间复杂度O((N-L)L)因为L=10所以最终是O(N)
		unordered_set<string> dict;
		unordered_set<string> res;
		if (s.size() < 10)
			return {};
		for (int i = 0; i <= s.size() - 10; i++)
		{
			string cur = s.substr(i, 10);    //时间复杂度O(L)
			if (dict.find(cur) != dict.end())
				res.insert(cur);
			else
				dict.insert(cur);
		}
		return vector<string>(res.begin(),res.end());
	}
};
class Solution1 {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		//基本思想：位运算，这是上面方法的优化，上面方法不断s.substr(i, 10)太耗时且10个字符对应set浪费空间
		//将A、C、G、T看成00、01、10、11，这样10个字符就是对应20个bit
		//遍历s的下一个字符，那么cur只需要左移2位，且新字符对应bit加入cur最低2位即可
		unordered_map<char, int> HashMap = { {'A',0},{'C',1},{'G',2},{'T',3} };
		unordered_set<bitset<20>> dict;
		unordered_set<string> res;
		bitset<20> cur;
		for (int i = 0; i < s.size(); i++)
		{
			cur <<= 2;
			cur |= HashMap[s[i]];
			if (i >= 9)
			{
				if (dict.find(cur) != dict.end())
					res.insert(s.substr(i - 9, 10));
				else
					dict.insert(cur);
			}
		}
		return vector<string>(res.begin(), res.end());
	}
};
int main()
{
	Solution1 solute;
	string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	vector<string> res = solute.findRepeatedDnaSequences(s);
	for_each(res.begin(), res.end(), [](const auto v) {cout << v << endl; });
	return 0;
}