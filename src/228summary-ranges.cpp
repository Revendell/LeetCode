#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		//基本思想：双指针，start连续数字的起始，end连续数字的结束
		vector<string> res;
		if (nums.size() == 0)
			return res;
		int start = nums[0], end;
		for (int i = 0; i < nums.size(); i++)
		{
			if(i == nums.size()-1 || nums[i] + 1 != nums[i + 1])
			{
				end = nums[i];
				string cur;
				if (start == end)
					cur = to_string(start);
				else
				{
					cur += to_string(start);
					cur += "->";
					cur += to_string(end);
				}
				res.push_back(cur);
				if (i != nums.size() - 1)
					start = nums[i + 1];
			}
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 0,2,3,4,6,8,9 };
	vector<string> res = solute.summaryRanges(nums);
	for_each(res.begin(), res.end(), [](const auto v) {cout << v << endl; });
	return 0;
}