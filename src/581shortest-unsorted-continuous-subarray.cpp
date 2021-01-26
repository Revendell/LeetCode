#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<climits>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //基本思想：单调栈，维持一个单调栈
        //如果栈顶元素大于当前元素，说明位置需要调整，更新调整位置的结束位置就是当前位置，用upper_bound找到调整位置的起始位置
        //否则继续入栈
        vector<int> st;
        int start=nums.size(),finish=0;
        for(int i=0;i<nums.size();i++)
        {
            if(!st.empty()&&st.back()>nums[i])
            {
                finish=i;
                auto iter=upper_bound(st.begin(),st.end(),nums[i]);
                start=min(start,int(iter-st.begin()));
                st.insert(iter,nums[i]);
            }
            else
                st.push_back(nums[i]);
        }
        return max(finish-start+1,0);
    }
};
class Solution1 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //基本思想：两次遍历，时间复杂度O(n)
        //从左到右循环，记录最大值为maxv，若nums[i]<maxv, 则表明位置i需要调整, 记录需要调整的最大位置right=i;
        //从右到左循环，记录最小值为minv, 若nums[i]>minv, 则表明位置i需要调整，记录需要调整的最小位置left=i.
        int right=0,left=nums.size()-1,maxv=INT_MIN,minv=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<maxv)
                right=i;
            maxv=max(maxv,nums[i]);
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]>minv)
                left=i;
            minv=min(minv,nums[i]);
        }
        return right==left?0:max(right-left+1,0);
    }
};
int main()
{
    Solution1 solute;
    vector<int> nums={2,6,4,8,10,9,15};
    cout<<solute.findUnsortedSubarray(nums)<<endl;
    return 0;
}
