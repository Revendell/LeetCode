
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //����˼�룺����ָ�룬Floyd��Ȧ�㷨��ʱ�临�Ӷ�O(n)�ռ临�Ӷ�O(1)
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
        //����˼�룺���ֲ���
        /*
        arr = [1,3,4,2,2] ��ʱ������ 1 �� 5 ֮��
        mid = (1 + 5) / 2 = 3 arrС�ڵ��ڵ�3��4��(1,2,2,3)��1��3�п϶����ظ���ֵ
        mid = (1 + 3) / 2 = 2 arrС�ڵ��ڵ�2��3��(1,2,2)��1��2�п϶����ظ���ֵ
        mid = (1 + 2) / 2 = 1 arrС�ڵ��ڵ�1��1��(1)��2��2�п϶����ظ���ֵ
        �����ظ������� 2
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
