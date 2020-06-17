#include<algorithm>
#include<iostream>
#include<vector>
#include <iterator>
#include<set>
using namespace std;
class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		//����˼�룺��������+��ϣ���ù�ϣ����ά�����k��С�Ļ�������
		//�����һ�������Ԫ�������λ�õ���������Ԫ�ؾ���ֵС�ڵ���t������true��������뵽�������ڣ�ͬʱ��������ȥ����ɵ�Ԫ��
		set<long> container;  //��ֹ�����������int��Χ
		for (int i = 0; i < nums.size(); i++)
		{
			auto iter = container.lower_bound(nums[i]);
			if (iter != container.end() && *iter - nums[i] <= t)
				return true;
			if (iter != container.begin() && nums[i] - *(--iter) <= t)
				return true;
			container.insert(nums[i]);
			if (container.size() > k)
				container.erase(nums[i - k]);
		}
		return false;
	}
};
class Solution1 {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		//����˼�룺�������� + multiset���������ڴ�СΪk������nums����Ԫ��
		//����������ڴ�СС�ڵ���k�����뵱ǰ��Ԫ�أ�ͬʱ�Ƚϲ����Ԫ������������Ԫ�صľ���ֵ���Ƿ�С�ڵ���t����true
		//����������ڴ�С����k��multisetȥ����߽�Ԫ�أ�ͬʱ����������߽����ơ�
		if (nums.size() == 0)
			return false;
		multiset<int> container;
		int left = 0, right = 1;
		long long value1, value2;
		container.insert(nums[left]);
		while (right < nums.size())
		{
			if (right - left <= k)
			{
				auto iter = container.insert(nums[right]);
				if (iter != container.begin())
				{
					value2 = *iter;
					auto iter1 = iter;
					value1 = *(--iter1);
					if (value2 - value1 <= t)
						return true;
				}
				if (iter != --container.end())
				{
					value1 = *iter;
					value2 = *(++iter);
					if (value2 - value1 <= t)
						return true;
				}
				right++;
			}
			else
			{
				container.erase(container.find(nums[left]));
				left++;
			}
		}
		return false;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 3,6,0,4 };
	int k = 2, t = 2;
	cout << solute.containsNearbyAlmostDuplicate(nums, k, t) << endl;
	return 0;
}