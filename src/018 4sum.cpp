#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution1 {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int i, j, k, t;
		vector<vector<int>> res;
		int len = nums.size();
		if (len < 4)  //�������Ԫ��С��4������""
			return res;
		sort(nums.begin(), nums.end());  //��nums����Ԫ������
		//����˫ָ�뷨�������������֮�ͣ��ȶ�nums��������Ȼ��̶�nums[t]��nums[k]����k���������趨����ָ��i=k+1��j=len-1��Ȼ���ж�nums[t]+nums[k]+nums[i]+nums[j]����֮����target��ϵ
		//�������֮��>target, j--ָ������
		//�������֮��<target, i++ָ������
		//�������֮��=target, �����ĸ�����res, i++ j--
		for (t = 0; t < len - 3; t++)
		{
			//��ֹ�����ظ��ĵ�һ������������nums[i]+nums[j]+nums[k]+nums[t]=target��nums[t]����Ԫ�ؿ�����ͬ����
			if (t > 0 && nums[t] == nums[t - 1])
				continue;
			for (k = t + 1; k < len - 2; k++)
			{
				//��ֹ�����ظ��ĵڶ�������������nums[i]+nums[j]+nums[k]+nums[t]=target��nums[k]����Ԫ�ؿ�����ͬ����
				if (k > t + 1 && nums[k] == nums[k - 1])
					continue;
				i = k + 1;
				j = len - 1;
				while (i < j)
				{
					if (nums[i] + nums[j] + nums[k] + nums[t] > target)
						j--;
					else if (nums[i] + nums[j] + nums[k] + nums[t] < target)
						i++;
					else
					{
						res.push_back({ nums[t],nums[k],nums[i],nums[j] });
						//��ֹ�����ظ��ĵ���������������nums[i]+nums[j]+nums[k]+nums[t]=target��nums[i]��nums[j]������nums[i+1]��nums[j-1]����Ԫ�ؿ�����ͬ����
						while (i < j && nums[i] == nums[i + 1])
							i++;
						while (i < j && nums[j] == nums[j - 1])
							j--;
						i++;
						j--;
					}
				}
			}
		}
		return res;
	}
};
//�ⷨ����Ҫ���õ�STL����erase��unique����ȥ�ظ��������һ�㣬������ⷨ������ȥ�ظ�����Ԫ��
class Solution2 {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int i, j, k, t;
		vector<vector<int>> res;
		int len = nums.size();
		if (len < 4)
			return res;
		sort(nums.begin(), nums.end());
		for (t = 0; t < len - 3; t++)
		{
			for (k = t + 1; k < len - 2; k++)
			{
				i = k + 1;
				j = len - 1;
				while (i < j)
				{
					if (nums[i] + nums[j] + nums[k] + nums[t] > target)
						j--;
					else if (nums[i] + nums[j] + nums[k] + nums[t] < target)
						i++;
					else
					{
						res.push_back({ nums[t],nums[k],nums[i],nums[j] });
						i++;
						j--;
					}
				}
			}
		}
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());
		return res;
	}
};
int main()
{
	Solution1 solute;
	vector<vector<int>> res;
	vector<int> nums = { -3,-2,-1,0,0,1,2,3 };
	int target = 0;
	res = solute.fourSum(nums, target);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < 4; j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}