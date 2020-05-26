#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		//����˼�룺��̬�滮��ά��������̬���̣�nums[0:i]�����������ĳ˻�Fmax����С������ĳ˻�Fmin
		//Fmax[i]=max{Fmax[i - 1] * nums[i], nums[i], Fmin[i - 1] * nums[i]};
		//Fmin[i]=min{Fmin[i - 1] * nums[i], nums[i], Fmax[i - 1] * nums[i]};
		vector <int> Fmax(nums), Fmin(nums);
		for (int i = 1; i < nums.size(); ++i) {
			Fmax[i] = max(Fmax[i - 1] * nums[i], max(nums[i], Fmin[i - 1] * nums[i]));
			Fmin[i] = min(Fmin[i - 1] * nums[i], min(nums[i], Fmax[i - 1] * nums[i]));
		}
		return *max_element(Fmax.begin(), Fmax.end());
	}
};
class Solution1 {
public:
	int maxProduct(vector<int>& nums) {
		//��̬�滮�Ż��ռ䣬���ݹ�������˼�룬���ǿ���ֻ������������ά��i-1ʱ�̵�״̬
		int res = nums[0], Fmax = nums[0], Fmin = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			int fmax = Fmax, fmin = Fmin;
			Fmax = max(fmax * nums[i], max(fmin * nums[i], nums[i]));
			Fmin = min(fmin * nums[i], min(fmax * nums[i], nums[i]));
			res = max(res, Fmax);
		}
		return res;
	}
};
class Solution2 {
public:
	int maxProduct(vector<int>& nums) {
		//����˼�룺̰�ģ�negative��¼��ǰ��0Ϊ�߽�����ĸ���λ��
		//���negativeΪż������ǰ��������ֵ�����������ĳ˻�
		//���negativeΪ��������ǰ��������ֵ����ȥ����һ����������ȥ�����һ������֮���������ĳ˻�
		if (nums.size() == 1)
			return nums[0];
		vector<int> negative;
		int res = 0, start = 0, cur, ans;
		for (int i = 0; i <= nums.size(); i++)
		{
			if (i < nums.size() && nums[i] < 0)
				negative.push_back(i);
			else if (i==nums.size() || nums[i] == 0)
			{
				if (negative.size() % 2 == 0)
				{
					cur = 1;
					ans = 0;
					for (int j = start; j < i; j++)
					{
						cur *= nums[j];
						ans = cur;
					}
					res = max(res, ans);
				}
				else
				{
					cur = 1;
					ans = 0;
					for (int j = start; j < negative[negative.size() - 1]; j++)
					{
						cur *= nums[j];
						ans = cur;
					}
					res = max(res, ans);
					cur = 1;
					ans = 0;
					for (int j = negative[0] + 1; j < i; j++)
					{
						cur *= nums[j];
						ans = cur;
					}
					res = max(res, ans);
				}
				start = i + 1;
				negative.clear();
			}
		}
		return res;
	}
};
class Solution3 {
public:
	int maxProduct(vector<int>& nums) {
		//̰���Ż��ռ䣬���ֵ������0Ϊ�߽������������֮�ͻ���ȥ����һ������֮�ͻ���ȥ�����һ������֮��
		//���Դ�ͷ��β�˻���һ�����ֵ��Ȼ���β��ͷ��һ�����ֵ����
		int res = nums[0], cur = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			cur *= nums[i];
			res = max(res, cur);
			if (nums[i] == 0)
				cur = 1;
		}
		cur = 1;
		for (int i = nums.size()-1; i >= 0; i--)
		{
			cur *= nums[i];
			res = max(res, cur);
			if (nums[i] == 0)
				cur = 1;	
		}
		return res;
	}
};
int main()
{
	Solution3 solute;
	vector<int> nums = { 2,3,2,4 };
	cout << solute.maxProduct(nums) << endl;
	return 0;
}