#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int rob(vector<int>& nums) {
		//����˼�룺��̬�滮��һά��̬�滮dp[i]��ʾ���С͵����ǰ���ݣ��ڵ�ǰ���������͵��ֵ
		//����dp[i]=dp[i]+max(dp[i-2],dp[i-3])��������nums��dp���������Ͳ����������ռ�
		//����dp[i]��ʾ��ֹ��ǰ����С͵���͵��ֵ��dp[i]=max(dp[i-1],dp[i-2]+nums[i])
		if (nums.size() == 0)
			return 0;
		if (nums.size() > 2)
			nums[2] += nums[0];
		for (int i = 3; i < nums.size(); i++)
			nums[i] += max(nums[i - 2], nums[i - 3]);
		return *max_element(nums.begin(), nums.end());
	}
};
class Solution1 {
public:
	int rob(vector<int>& nums) {
		//����˼�룺��̬�滮�Ż���nums�����þ�����Ҫ�ı�����ֵ
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return nums[0];
		int first = nums[0], second = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size(); i++)
		{
			int temp = second;
			second = max(second, first + nums[i]);
			first = temp;
		}
		return second;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 1,2,3,1,1,6,10 };
	cout << solute.rob(nums) << endl;
	return 0;
}