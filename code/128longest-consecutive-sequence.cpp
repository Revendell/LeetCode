#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		//基本思想：HashMap，时间复杂度O(n+n)，对于这种时间复杂度严格要求的，第一时间想到空间换时间
		int length, res = 0;
		//HashMap，key是nums中的值value是bool型是否访问过
		unordered_map<int, bool> dict;
		for (auto& v : nums)
			dict.insert({ v,false });
		auto i = dict.begin();
		while (i != dict.end())
		{
			if (i->second == true)
			{
				i++;
				continue;
			}
			int v = i->first;
			length = 0;
			while (dict.find(v) != dict.end())
			{
				dict[v] = true;
				v++;
				length++;
				res = max(res, length);
			}
			i++;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = {  };
	cout << solute.longestConsecutive(nums) << endl;
	return 0;
}