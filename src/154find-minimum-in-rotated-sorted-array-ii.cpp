#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
		//基本思想：二分查找
        int left=0,right=nums.size()-1;
        while(left<right)
        {
            int mid=(left+right)/2;
            if(nums[right]==nums[mid])
                right--;
            else if(nums[right]<nums[mid])
                left=mid+1;
            else
                right=mid;
        }
        return nums[left];
    }
};
int main()
{
	Solution solute;
	vector<int> nums = { 3,3,1,3 };
	cout << solute.findMin(nums) << endl;
	return 0;
}