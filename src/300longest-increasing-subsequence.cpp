
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0)  return 0;
		vector<int> dp(nums.size(), 0);
		for (int i = 0; i < nums.size(); i++)
		{
			int curmax = 0;
			for (int j = 0; j < i; j++)
			{
				if (nums[i] > nums[j])
					curmax = max(curmax, dp[j]);
			}
			dp[i] = curmax + 1;
		}
		return *max_element(dp.begin(), dp.end());
	}
};
class Solution1 {
public:
	int lengthOfLIS(vector<int>& nums) {
		//����˼�룺��̬�滮+���ֲ��ң�������
		//cell��Ԫ�صĺ��������������г���ΪԪ���±�+1�����������У��������һ��Ԫ����С�����
		//�½�����cell�����ڱ�������������С���ԭ���н��б�������ÿλԪ�ض��ֲ���cell�С�
		//���cell��Ԫ�ض�����С�������嵽���
		//�����������ǵ�cell�б������ڻ���ڵ�Ԫ���е�һ��Ԫ�أ�Ҳ����lower_bound����ֵ
		//Ϊʲô���ڵ�ǰ����nums��Ԫ����Ҫ�������ǵ�cell�б������ڻ���ڵ�Ԫ���е�һ��Ԫ�أ�
		//��������[2,4,5,3,7]��������3ʱ��cell����Ԫ����[2,4,5]����Ҫ��3���ǵ�4�������������������������г���Ϊ2�����������У����һ��Ԫ����С������3�滻��֮ǰ��С������4�����
		if (nums.size() < 2)  return nums.size();
		vector<int> cell;
		cell.push_back(nums[0]);
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] > cell.back())
				cell.push_back(nums[i]);
			else
			{
				vector<int>::iterator iter = lower_bound(cell.begin(), cell.end(), nums[i]);
				if (iter != cell.end())
					*iter = nums[i];
			}
		}
		return cell.size();
	}
};
int main()
{
	Solution1 solute;
	vector<int> nums = { 4,10,4,3,8,9 };
	cout << solute.lengthOfLIS(nums) << endl;
	return 0;
}
