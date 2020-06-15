#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		//����˼�룺����ȡ�� k ��
		sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
	}
};
class Solution1 {
public:
	int findKthLargest(vector<int>& nums, int k) {
		//����˼�룺����ǰk�����Ԫ��С���ѣ�ȡ�Ѷ����Ѷ�Ԫ����С
		priority_queue<int, vector<int>, greater<int>> q;
		for (auto num : nums)
		{
			if(q.size() == k && num < q.top())
				continue;
			q.push(num);
			if (q.size() > k)
				q.pop();
		}
		return q.top();
	}
};
class Solution2 {
public:
	int findKthLargest(vector<int>& nums, int k) {
		//����˼�룺�ֶ�ʵ�ֶ����򣬹���󶥶ѣ���Ϊ�󶥶����õ����Ǵ�С�����˳��
		//����󶥶Ѻ󣬴Ӷ�β�ȵõ����Ԫ�����εõ���k��Ԫ�ؼ���
		HeapSort(nums, k);
		return nums[nums.size() - k];
	}
	//�����󶥶ѣ����ֽڵ�nums[start]���ں��ӽڵ㣬������Χ��[start+1,end]֮��
	void HeapAdjust(vector<int>& nums, int start, int end)
	{
		int temp = nums[start];    //����nums[start]ֵ
		int i = 2 * start + 1;    //start��һ�����ӽڵ�nums[2*start+1]��һ����nums[2*start+2]
		while (i <= end)
		{
			//���ڶѽڵ�nums[start]���е�������С���������ӽڵ�nums[i]nums[i+1]�����������������break
			if (i + 1 <= end && nums[i] < nums[i + 1])
				i = i + 1;
			if (temp > nums[i])
				break;
			nums[start] = nums[i];    //nums[start]�����������ӽڵ�����С�ģ�����
			start = i;   //��������start�ĺ��ӽڵ�i�Ƿ����i�ĺ��ӽڵ㣬��˸���start��i
			i = 2 * start + 1;
		}
		nums[start] = temp;
	}
	void HeapSort(vector<int>& nums,int k)
	{
		//�������һ�������󶥶ѣ�������ڵ�������ڵ㽨�������Ǳ�֤��ǰ�ڵ�iֵ�����������ӽڵ�2*i+1��2*i+1ֵ
		for (int i = nums.size() / 2 - 1; i >= 0; i--)
		{
			HeapAdjust(nums, i, nums.size() - 1);
		}
		//������ڶ������ν����Ѷ��Ͷѵף� �����ѵ׾������������ֵ���ýڵ�Ҳȥ�����У��󶥶ѱ��ƻ����½�����
		int i = nums.size() - 1;
		while(k--)
		{
			swap(nums[0], nums[i]);
			HeapAdjust(nums, 0, i - 1);
			i--;
		}
	}
};
int main()
{
	Solution2 solute;
	vector<int> nums = { 3,2,3,1,2,4,5,5,6 };
	int k = 4;
	cout << solute.findKthLargest(nums,k) << endl;
	return 0;
}