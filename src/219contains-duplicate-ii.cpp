#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		//����˼�룺HashMap��map����nums��Ԫ�ض�Ӧ�±�λ�õ�ӳ��
		//����nums����Ԫ�أ����ڵ�ǰԪ��nums[i]�����������HashMap�����㵱ǰ�±�i��HashMap[nums[i]]�ľ���
		//���С�ڵ���k����true��ͬʱ����HashMap[nums[i]]Ϊ��ǰ�±�i
		unordered_map<int, int> HashMap;
		for (int i = 0; i < nums.size(); i++)
		{
			if (HashMap.find(nums[i]) != HashMap.end())
			{
				if (i - HashMap[nums[i]] <= k)
					return true;
			}
			HashMap[nums[i]] = i;
		}
		return false;
	}
};
class Solution1 {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		//����˼�룺��ϣ��+�������ڣ��ù�ϣ����ά�����k��С�Ļ�������
		//�����һ��Ԫ�ش����ڻ��������ڣ�����true��������뵽�������ڣ�ͬʱ��������ȥ����ɵ�Ԫ��
		unordered_set<int> container;
		for (int i = 0; i < nums.size(); i++)
		{
			if (container.find(nums[i]) != container.end())
				return true;
			container.insert(nums[i]);
			if (container.size() > k)
				container.erase(nums[i - k]);
		}
		return false;
	}
};
int main()
{
	Solution1 solute;
	vector<int> nums = { 1,2,3,1,2,3 };
	int k = 2;
	cout << solute.containsNearbyDuplicate(nums, k) << endl;
	return 0;
}