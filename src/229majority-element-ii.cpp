#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		//����˼�룺Ħ��ͶƱ����n/k���������ֻ��k-1��
		//�趨������ѡ��candidate1��candidate2��Ʊ���ֱ���cnt1��cnt2
		//1�����ͶA����ǰԪ�ص���A������A��Ʊ��++;
		//2�����ͶB����ǰԪ�ص���B����B��Ʊ��++��
		//3�����A, B����Ͷ������ǰ��A��B������ȣ�, ��ô����ʱA��B��Ʊ���Ƿ��Ϊ0�����Ϊ0, ��ǰԪ�س�Ϊ�µĺ�ѡ�ˣ����A, B�����˵�Ʊ������Ϊ0����ôA, B������ѡ�˵�Ʊ������һ��
		//��������ô���ֿ��ܣ���2������n/3����1������n/3����0������n/3
		//����������ѡ����������ѡ�ˣ�������������ѡ���Ƿ�����>n/3������Ҫ�ٱ���һ�����飬�ҳ�������ѡ�˵ľ���Ʊ������Ϊ��Ŀû����169�Ᵽ֤һ���С�
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