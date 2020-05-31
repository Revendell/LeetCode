#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		//����˼�룺Boyer-MooreͶƱ����ʱ�临�Ӷ�O(n)�ռ临�Ӷ�O(1)
		//����һ��ʼ�뵽���ǹ�ϣ������򷨣������޷�����ʱ�临�Ӷ�O(n)�ռ临�Ӷ�O(1)����������һ����һ������㷨
		//ץס��������������Ҫ�ҵ��Ǹ�����nums�г�������
		//�ӵ�һ������ʼcount=1��������ͬ�ľͼ�1��������ͬ�ľͼ�1������0�����»�������ʼ�����������ҵ������������Ǹ�
		int candidate = nums[0];
		int count = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] == candidate)
				count++;
			else
			{
				count--;
				if (count == 0)
				{
					candidate = nums[i];
					count = 1;
				}
			}
		}
		return candidate;
	}
};
class Solution1 {
public:
	int majorityElement(vector<int>& nums) {
		//����˼�룺��ϣ��ʱ�临�Ӷ�O(n)�ռ临�Ӷ�O(n)
		unordered_map<int, int> HashMap;
		int res, cnt = 0;
		for (auto v : nums)
		{
			++HashMap[v];
			if (HashMap[v] > cnt)
			{
				res = v;
				cnt = HashMap[v];
			}
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 2,2,1,1,1,2,2 };
	cout << solute.majorityElement(nums) << endl;
	return 0;
}