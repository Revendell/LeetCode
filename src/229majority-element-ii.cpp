#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		//基本思想：摩尔投票法，n/k的众数最多只有k-1个
		//设定两个候选人candidate1和candidate2，票数分别是cnt1和cnt2
		//1、如果投A（当前元素等于A），则A的票数++;
		//2、如果投B（当前元素等于B），B的票数++；
		//3、如果A, B都不投（即当前与A，B都不相等）, 那么检查此时A或B的票数是否减为0，如果为0, 则当前元素成为新的候选人；如果A, B两个人的票数都不为0，那么A, B两个候选人的票数均减一。
		//最后会有这么几种可能：有2个大于n/3，有1个大于n/3，有0个大于n/3
		//遍历结束后选出了两个候选人，但是这两个候选人是否满足>n/3，还需要再遍历一遍数组，找出两个候选人的具体票数，因为题目没有像169题保证一定有。
		vector<int> res;
		int candidate1 = 0, candidate2 = 0;
		int cnt1 = 0, cnt2 = 0;
		for (auto num:nums)
		{
			if (nums == candidate1)
				cnt1++;
			else if (nums == candidate2)
				cnt2++;
			else
			{
				if (cnt1 == 0)
				{
					candidate1 = nums;
					cnt1 = 1;
				}
				else if (cnt2 == 0)
				{
					candidate2 = nums;
					cnt2 = 1;
				}
				else
				{
					cnt1--;
					cnt2--;
				}
			}
		}
		cnt1 = 0;
		cnt2 = 0;
		for (auto num : nums)
		{
			if (num == candidate1)
				cnt1++;
			else if (num == candidate2)
				cnt2++;
		}
		if (cnt1 > nums.size()/3)
			res.push_back(candidate1);
		if (cnt2 > nums.size()/3)
			res.push_back(candidate2);
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 1,1,1,3,3,2,2,2 };
	vector<int> res = solute.majorityElement(nums);
	for_each(res.begin(), res.end(), [](const auto v) {cout << v << endl; });
	return 0;
}