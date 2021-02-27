#include<vector>
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        //基本思想：动态规划，问题转化为判断连续上升或者下降的波段个数
        //利用摆动序列，波峰和波谷的差值最多为1的特点
        if(nums.size()==0)  return 0;
        int up=1,down=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
                up=down+1;
            else if(nums[i]<nums[i-1])
                down=up+1;
        }
        return max(up,down);
    }
};
int main()
{
    Solution solute;
    vector<int> nums{1,17,5,10,13,15,10,5,16,8};
    cout<<solute.wiggleMaxLength(nums)<<endl;
    return 0;
}
