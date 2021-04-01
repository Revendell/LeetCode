#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        //基本思想：前缀和+哈希表HashMap，HashMap[i]表示前缀和为i时的最小下标处,pre[i]-pre[j-1]==k,pre[j-1]==pre[i]-k
        //遍历数组nums，计算从第0个元素到当前元素的和sum，用哈希表Map保存出现过的累积和sum的最小下标处;
        //如果sum-k在哈希表中出现过，则代表从当前下标i往前有连续的子数组的和为sum，res=max(res,i-Map[sum-k])
        unordered_map<int,int> Map;
        int sum=0;
        int res=0;
        Map[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(Map.find(sum-k)!=Map.end())
            {
                res=max(res,i-Map[sum-k]);
            }
            if(Map.find(sum)==Map.end())
                Map[sum]=i;
        }
        return res;
    }
};
inr main()
{
    Solution solute;
    vector<int> nums{1, -1, 5, -2, 3};
    int k=3;
    cout<<solute.maxSubArrayLen(nums,k)<<endl;
    return 0;
}