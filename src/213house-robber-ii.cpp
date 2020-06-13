#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int rob(vector<int>& nums) {
		//����˼�룺��̬�滮��һά��̬�滮p[i]��ʾ��ֹ��ǰ����С͵���͵��ֵ��dp[i]=max(dp[i-1],dp[i-2]+nums[i])
		//��һ�䷿�Ӻ����һ�䷿�������ڵģ�����ͬʱ��������Ҫô��һ�䷿�ӱ������һ�䲻����Ҫô���һ�䷿�ӱ�����һ�䲻����
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return nums[0];
		if (nums.size() == 2)
			return max(nums[0], nums[1]);
		int max1, max2, first, second;
		//��һ�䷿�ӱ������һ�䲻��
		first = nums[0];
		second = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size() - 1; i++)
		{
			int temp = second;
			second = max(second, first + nums[i]);
			first = temp;
		}
		max1 = second;
		//���һ�䷿�ӱ�����һ�䲻��
		first = nums[1];
		second = max(nums[1], nums[2]);
		for (int i = 3; i < nums.size(); i++)
		{
			int temp = second;
			second = max(second, first + nums[i]);
			first = temp;
		}
		max2 = second;
		return max(max1, max2);
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 1,2,3,1 };
	cout << solute.rob(nums) << endl;
	return 0;
}