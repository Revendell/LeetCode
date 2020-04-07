#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		//基本思想：贪心算法，最大和的连续子序列一定是以正数开始正数结束，那么当前元素为正数并且当前元素加上下一个元素也为正数，保存两元素和存入下一个元素位置这也就是局部最优解，最后返回容器最大值就是全局最优解
		//比如序列为1,2,3,-5,1,2,5，求完局部最优解后是1,3,6,1,2,4,9，全局最优解就是9
		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i] > 0 && nums[i] + nums[i + 1] > 0)
				nums[i + 1] += nums[i];	
		}
		return *max_element(nums.begin(),nums.end());
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 1,2,3,-5,1,2,5 };
	cout << solute.maxSubArray(nums) << endl;
	return 0;
}