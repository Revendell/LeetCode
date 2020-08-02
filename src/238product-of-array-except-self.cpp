#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		//����˼�룺���ҳ˻��б�L[i]��i����������ֵĳ˻���R[i]��i�Ҳ��������ֵĳ˻�
		//����i����ֵΪL[i-1]*R[i+1]��ʱ�临�Ӷ�O(n)�ռ临�Ӷ�O(n)
		vector<int> res;
		vector<int> L(nums.size(), 1);
		vector<int> R(nums.size(), 1);
		L[0] = nums[0];
		for (int i = 1; i < nums.size(); i++)
			L[i] = nums[i] * L[i - 1];
		R[nums.size() - 1] = nums[nums.size() - 1];
		for (int i = nums.size() - 2; i >= 0; i--)
			R[i] = nums[i] * R[i + 1];
		res.push_back(R[1]);
		for (int i = 1; i < nums.size() - 1; i++)
			res.push_back(L[i - 1] * R[i + 1]);
		res.push_back(L[nums.size() - 2]);
		return res;
	}
};
class Solution1 {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		//����˼�룺���ҳ˻��б�����nums��Ϊ��˻��б�����R��Ϊ�ҳ˻��б�ʱ�临�Ӷ�O(n)�ռ临�Ӷ�O(1)
		vector<int> res(nums.size(), 1);
		res[0] = nums[0];
		for (int i = 1; i < nums.size(); i++)
			res[i] = nums[i] * res[i - 1];
		int R = 1;
		for (int i = nums.size() - 1; i >= 1; i--)
		{
			res[i] = res[i - 1] * R;
			R *= nums[i];
		}
		res[0] = R;
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 1,2,3,4 };
	vector<int> res = solute.productExceptSelf(nums);
	for_each(res.begin(), res.end(), [](const auto v) {cout << v << endl; });
	return 0;
}