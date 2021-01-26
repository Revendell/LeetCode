#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //基本思想：暴力超时，双重循环遍历所有可能的连续子序列，这道题不能用滑动窗口，因为元素存在负数
        int res=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=0;
            for(int j=i;j<nums.size();j++)
            {
                sum+=nums[j];
                if(sum==k)  res++;
            }
        }
        return res;
    }
};
class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        //基本思想：前缀和+哈希表HashMap，HashMap[i]表示前缀和为i的子序列出现的次数,pre[i]-pre[j-1]==k,pre[j-1]==pre[i]-k
        //遍历数组nums，计算从第0个元素到当前元素的和sum，用哈希表Map保存出现过的累积和sum的次数;
        //如果sum-k在哈希表中出现过，则代表从当前下标i往前有连续的子数组的和为sum.
        int res=0;
        unordered_map<int,int> Map;
        Map[0]=1;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(Map.find(sum-k)!=Map.end())
            {
                res+=Map[sum-k];
            }
            Map[sum]++;
        }
        return res;
    }
};
int main()
{
    Solution1 solute;
    vector<int> nums={1,1,1};
    int k=2;
    cout<<solute.subarraySum(nums,k)<<endl;
    return 0;
}
