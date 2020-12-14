
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //基本思想：快慢指针，Floyd判圈算法，时间复杂度O(n)空间复杂度O(1)
        int slow=0,fast=0;
        while(true)
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast)
                break;
        }
        slow=0;
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
    }
};
class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        //基本思想：二分查找
        /*
        arr = [1,3,4,2,2] 此时数字在 1 — 5 之间
        mid = (1 + 5) / 2 = 3 arr小于等于的3有4个(1,2,2,3)，1到3中肯定有重复的值
        mid = (1 + 3) / 2 = 2 arr小于等于的2有3个(1,2,2)，1到2中肯定有重复的值
        mid = (1 + 2) / 2 = 1 arr小于等于的1有1个(1)，2到2中肯定有重复的值
        所以重复的数是 2
        */
        int n = nums.size();
        int l = 1, r = n - 1, res;
        while (l <= r) {
            int mid = l +(r - l)/2;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if(nums[i] <= mid)
                    cnt++;
            }
            if (cnt <= mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
                res = mid;
            }
        }
        return res;
    }
};
int main()
{
    Solution solute;
    vector<int> nums={1,3,4,2,2};
    cout<<solute.findDuplicate(nums)<<endl;
    return 0;
}
