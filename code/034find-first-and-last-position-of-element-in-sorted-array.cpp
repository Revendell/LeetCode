#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res;
		int low, mid, high, pos1, pos2;
		low = 0;
		high = nums.size() - 1;
		//����˼�룺�۰���ң�˼·�ܼ򵥣�ϸ����ħ��
		while (low <= high)
		{
			mid = (low + high) / 2;
			//��nums[mid]=target������[low,mid]�����۰�����ҵ���벿�ֵ���target���ٽ��±꣬��[mid,high]�����۰�����ҵ��Ұ벿�ֵ���target���ٽ��±�
			if (nums[mid] == target)
			{
				pos1 = mid;
				pos2 = mid;
				//��[low,pos1]�����۰�����ҵ���벿�ֵ���target���ٽ��±�low
				while (nums[low] != target)
				{
					mid = (low + pos1) / 2;
					if (nums[mid] < target)
					{
						low = mid + 1;
					}
					else if (nums[mid] == target)
					{
						pos1 = mid;
						low++;
					}
				}
				//��[pos2, high]�����۰�����ҵ��Ұ벿�ֵ���target���ٽ��±�high
				while (nums[high] != target)
				{
					mid = (pos2 + high) / 2;
					if (nums[mid] > target)
					{
						high = mid - 1;
					}
					else if (nums[mid] == target)
					{
						pos2 = mid;
						high--;
					}
				}
				res.push_back(low);
				res.push_back(high);
				return res;
			}
			//��nums[mid]<target��low=mid+1
			else if (nums[mid] < target)
				low = mid + 1;
			//��nums[mid]>target��high=mid-1
			else
				high = mid - 1;
		}
		res.push_back(-1);
		res.push_back(-1);
		return res;
	}
};
int main()
{
	Solution solute;
	int target = 8;
	vector<int> nums = { 5,7,7,8,8,10 };
	vector<int> res;
	res = solute.searchRange(nums, target);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	return 0;
}