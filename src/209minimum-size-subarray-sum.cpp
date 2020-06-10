#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		//����˼�룺�������ڣ�ʱ�临�Ӷ�O(n)��ʹ�û�������[left,right]����������Ԫ��֮��Ϊsum
		//���sum<s�����󴰿��ұ߽��������죬ͬʱ����sum
		//���sum>=s������res����С������߽��������죬ͬʱ����sum
		if (nums.size() == 0)
			return 0;
		int res = INT_MAX, left = 0, right = 0, sum = nums[0];
		while (right < nums.size())
		{
			if (sum < s)
			{
				right++;
				if (right < nums.size())
					sum += nums[right];
			}
			else
			{
				res = min(res, right - left + 1);
				sum -= nums[left];
				left++;
			}
		}
		return (res == INT_MAX) ? 0 : res;
	}
};
class Solution1 {
public:
	int minSubArrayLen(int s, vector<int>& nums)
	{
		//����˼�룺���ֲ��ң�ʱ�临�Ӷ�O(nlogn)�ռ临�Ӷ�O(n)��ֻ���ṩ��һ��˼·
		//�Ƚ�nums�ӵ�һ��Ԫ�ص����һ��Ԫ�������ۼƵ��ӱ�����sums���飬ʹ��sums��������
		//Ȼ�����sums�����ҳ���һ�����ڵ���s+sums[i-1]��λ��bound��Ҳ����˵��i��bound��numsԪ��֮�ʹ��ڵ���s
		if (nums.size() == 0)
			return 0;
		int ans = INT_MAX;
		vector<int> sums(nums.size() + 1, 0);
		for (int i = 1; i <= nums.size(); i++)
			sums[i] = sums[i - 1] + nums[i - 1];
		for (int i = 1; i <= nums.size(); i++) {
			int to_find = s + sums[i - 1];
			//lower_bound���ش��ڻ����to_find�ĵ�һ��Ԫ��λ��
			auto bound = lower_bound(sums.begin(), sums.end(), to_find);
			if (bound != sums.end()) {
				ans = min(ans, static_cast<int>(bound - (sums.begin() + i - 1)));
			}
		}
		return (ans != INT_MAX) ? ans : 0;
	}
};
int main()
{
	Solution solute;
	int s = 7;
	vector<int> nums{ 2, 3, 1, 2, 4, 3 };
	cout << solute.minSubArrayLen(s, nums) << endl;
	return 0;
}