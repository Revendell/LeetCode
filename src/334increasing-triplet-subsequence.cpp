#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //基本思想：单调栈，维护长度为3的递增栈，如果当前元素比栈顶大，入栈；否则当前元素替换掉栈中刚好比它大的元素；
        //这样替换的好处是并不影响递增子序列的长度
        //为什么对于当前遍历nums的元素需要用它覆盖掉栈中比它大于或等于的元素中第一个元素？
		//比如序列[2,4,5,3,7]当遍历到3时，栈中数组元素是[2,4,5]，需要用3覆盖掉4，这样做的意义是递增子序列长度为2的所有序列中，最后一个元素最小可以是3替换掉之前最小可以是4的情况
        if(nums.size()<3)  return false;
        vector<int> res{nums[0]};
        for(int i=1;i<nums.size()&&res.size()<3;i++)
        {
            if(nums[i]>res.back())
                res.push_back(nums[i]);
            else if(nums[i]<res.back())
            {
                auto iter=lower_bound(res.begin(),res.end(),nums[i]);
                *iter=nums[i];
            }
        }
        return res.size()==3;
    }
};
int main()
{
    Solution solute;
    vector<int> nums{2,1,5,0,3};
    cout<<solute.increasingTriplet(nums)<<endl;
    return 0;
}
