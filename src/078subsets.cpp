#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		//基本思想：字典排序（二进制排序）子集，以字典序的顺序获得全部组合，第一个序为000，最后一个序为111，对应nums元素，vec[i]=1则将nums[i]加入cur
		vector<vector<int>> res;
		vector<int> cur;
		vector<int> vec(nums.size(), 0);
		int i, carry = 1;
		do
		{
			for (i = 0; i < nums.size(); i++)
			{
				if (vec[i] == 1)
					cur.push_back(nums[i]);
			}
			res.push_back(cur);
			cur.clear();
			for (i = 0; i < nums.size(); i++)
			{
				if (vec[i] + carry == 2)
				{
					vec[i] = 0;
					carry = 1;
				}
				else
				{
					vec[i] = 1;
					break;
				}
			}
		} while (vec != vector<int>(nums.size(), 0));
		return res;
	}
};
class Solution1 {
public:
	vector<vector<int>> res;
	vector<vector<int>> subsets(vector<int>& nums) {
		//基本思想：递归回溯法，子集中元素个数subset_len从0到nums.size，循环遍历递归回溯
		vector<int> cur;
		int cnt = 0, subset_len, pos = 0;
		for (subset_len = 0; subset_len <= nums.size(); subset_len++)
		{
			Recursion(nums, pos, cnt, subset_len, cur);
		}
		return res;
	}
	void Recursion(vector<int>& nums, int pos, int cnt, int subset_len, vector<int> cur)
	{
		if (cnt == subset_len)
		{
			res.push_back(cur);
			return;
		}
		for (int i = pos; i < nums.size(); i++)
		{
			cur.push_back(nums[i]);
			Recursion(nums, i + 1, cnt + 1, subset_len, cur);
			cur.pop_back();
		}
		return;
	}
};
int main()
{
	Solution1 solute;
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> res = solute.subsets(nums);
	for (int i = 0; i < res.size(); i++)
	{
		copy(res[i].begin(), res[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	return 0;
}
	