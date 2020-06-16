#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		//基本思想：哈希表，时间复杂度O(n)空间复杂度O(n)
		unordered_set<int> dict;
		for (auto num : nums)
		{
			if (dict.find(num) != dict.end())
				return true;
			dict.insert(num);
		}
		return false;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 1,2,3,1 };
	cout << solute.containsDuplicate(nums) << endl;
	return 0;
}