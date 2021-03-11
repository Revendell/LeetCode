#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int search(vector<int>& nums, int target) {
		//�򻯰棺���ֲ��ң���ת�㽫nums�ֳ������֣����ж�mid����벿�ֻ����Ұ벿�֣�֮��mid�ֽ�ʣ�²��ֳַ�������
		//�������벿�ָ���nums[0]<=target&&target<nums[mid]�ж�λ��mid�����
		//������Ұ벿�ָ���nums[mid]<target&&target<=nums[n-1]�ж�λ��mid���ұ�
		int n = nums.size();
		if(n==0)  return -1;
		int low=0, mid, high=n-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(nums[mid]==target)
				return mid;
			else if(nums[0]<=nums[mid])
			{
				if(nums[0]<=target&&target<nums[mid])
					high=mid-1;
				else
					low=mid+1;
			}
			else
			{
				if(nums[mid]<target&&target<=nums[n-1])
					low=mid+1;
				else
					high=mid-1;
			}
		}
		return -1;
	}
};
class Solution1 {
public:
	int search(vector<int>& nums, int target) {
		int res=-1, high, mid, low;
		int len = nums.size();
		low = 0;
		high = len - 1;
		//����˼�룺�����۰���ң���ת�����������Ϊ�����֣�target����λ����벿�֣�Ҳ����λ���Ұ벿�֣������������nums[low]<target��nums[low]>target
		while (low <= high)
		{
			mid = (low + high) / 2;
			//�ҵ�targetλ�ڵ�λ�÷����±�
			if (nums[low] == target)
			{
				res = low;
				return res;
			}
			else if (nums[high] == target)
			{
				res = high;
				return res;
			}
			else if (nums[mid] == target)
			{
				res = mid;
				return res;
			}
			//���targetλ����벿�֣�����nums[mid]��λ�����������λ���Ұ벿�֣�λ����벿��target����ߣ�λ����벿��target���ұ�
			else if (nums[low] < target)
			{
				//midλ���Ұ벿�֣���targetλ����벿�֣�����high=mid-1��midλ����벿������target���ұߣ�����high=mid-1
				if (nums[mid] <= nums[low] || (nums[mid] > nums[low] && nums[mid] >= target))
				{
					high = mid - 1;
				}
				//midλ����벿������target����ߣ�����low=mid+1
				else if (nums[mid] > nums[low] && nums[mid] < target)
				{
					low = mid + 1;
				}
			}
			//���targetλ���Ұ벿�֣�����nums[mid]��λ�����������λ����벿�֣�λ���Ұ벿��target����ߣ�λ���Ұ벿��target���ұ�
			else if(nums[low] > target)
			{
				//midλ����벿�֣���targetλ���Ұ벿�֣�����low=mid+1��midλ���Ұ벿������target����ߣ�����low=mid+1
				if (nums[mid] >= nums[high] || (nums[mid] < nums[high] && nums[mid] < target))
				{
					low = mid + 1;
				}
				//midλ���Ұ벿������target���ұߣ�����high=mid-1
				else if (nums[mid] < nums[high] && nums[mid] >= target)
				{
					high = mid - 1;
				}
			}
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 4,5,6,7,0,1,2 };
	int target = 0, res;
	res = solute.search(nums, target);
	cout << res << endl;
	return 0;
}