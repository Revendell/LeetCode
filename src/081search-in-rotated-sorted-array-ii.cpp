#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		//�򻯰棺���ֲ��ң���ת�㽫nums�ֳ������֣����ж�mid����벿�ֻ����Ұ벿�֣�֮��mid�ֽ�ʣ�²��ֳַ�������
		//���10111��11101��������� nums[low] == nums[mid]��low++
		//�������벿�ָ���nums[low]<target&&target<nums[mid]�ж�λ��mid�����
		//������Ұ벿�ָ���nums[mid]<target&&target<=nums[high]�ж�λ��mid���ұ�
		int n = nums.size();
		if(n==0)  return -1;
		int low=0, mid, high=n-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(nums[mid]==target)
				return true;
			else if(nums[low]==nums[mid])
				low++;
			else if(nums[low]<nums[mid])
			{
				if(nums[low]<=target&&target<nums[mid])
					high=mid-1;
				else
					low=mid+1;
			}
			else
			{
				if(nums[mid]<target&&target<=nums[high])
					low=mid+1;
				else
					high=mid-1;
			}
		}
		return false;
	}
};
class Solution1 {
public:
	bool search(vector<int>& nums, int target) {
		//����˼�룺�۰����
		int low, high, mid;
		low = 0;
		high = nums.size() - 1;
		while (low<=high)
		{
			//ȥ���ظ����֣���ֹ2,2,2,3,2,2,2,2�����
			while (low < high && nums[low] == nums[low + 1])
				low++;
			while (low < high && nums[high] == nums[high - 1])
				high--;
			mid = (low + high) / 2;
			if (nums[mid] == target || nums[low] == target || nums[high] == target)
				return true;
			//target������벿��
			if (nums[low] < target)
			{
				//target������벿�ֵ��Ұ��
				if (nums[mid] < target && nums[mid] > nums[low])
					low = mid + 1;
				//target������벿�ֵ�����
				else
					high = mid - 1;
			}
			//target�����Ұ벿��
			else
			{
				//target�����Ұ벿�ֵ�����
				if (nums[mid] > target&& nums[mid] < nums[high])
					high = mid - 1;
				//target�����Ұ벿�ֵ��Ұ��
				else
					low = mid + 1;
			}
		}
		return false;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 2,2,2,2,2,2,2,2 };
	int target = 4;
	cout << solute.search(nums, target) << endl;
	return 0;
}