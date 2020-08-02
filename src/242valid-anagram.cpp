#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
	bool isAnagram(string s, string t) {
		//基本思想：排序
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
	}
};
class Solution1 {
public:
	bool isAnagram(string s, string t) {
		//基本思想：哈希表
		unordered_map<char,int> s1, t1;
		for (auto v : s)
			++s1[v];
		for (auto v : t)
			++t1[v];
		return s1 == t1;
	}
};
int main()
{
	Solution1 solute;
	string s = "anagram", t = "nagaram";
	cout << solute.isAnagram(s, t) << endl;
	return 0;
}