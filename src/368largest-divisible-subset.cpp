#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //基本思想：递归，超时，这种题目一旦递归超时得用动态规划
        vector<int> cur;
        sort(nums.begin(),nums.end());
        Recursion(nums,cur,0);
        vector<int> ans;
        int len=0;
        for(int i=0;i<res.size();i++)
        {
            if(res[i].size()>len)
            {
                ans=res[i];
                len=res[i].size();
            }
        }
        return ans;
    }
    void Recursion(vector<int>& nums,vector<int> cur,int pos)
    {
        res.push_back(cur);
        for(int i=pos;i<nums.size();i++)
        {
            if(cur.empty()||nums[i]%cur.back()==0)
            {
                cur.push_back(nums[i]);
                Recursion(nums,cur,i+1);
                cur.pop_back();
            }
        }
    }
};
class Solution1 {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //基本思想：动态规划
        //dp[i]: 以nums[i]结尾的序列最大长度，初始状态都为1，至少长度为1
        //pre[i]: 在最大序列中 nums[i]的上一个元素在nums出现的下标
        //len记录dp[i]中最大的长度，endi记录最大长度下的最后一个nums的下标，通过pre[endi]不断追踪得到res
        //使用二重循环，对于每一个nums[i]，看可以接在之前的哪个序列dp[j]上，使得dp[i]最长
        //nums[i]%nums[j] == 0是可以接的条件，dp[i]<=dp[j]是使得dp[i]变长的条件
        vector<int> dp(nums.size(),1);
        vector<int> pre(nums.size(),-1);
        vector<int> res;
        int len=0,endi;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0&&dp[i]<=dp[j])
                {
                    dp[i]=dp[j]+1;
                    pre[i]=j;
                }
            }
            if(dp[i]>len)
            {
                len=dp[i];
                endi=i;
            }
        }
        res.push_back(nums[endi]);
        while(pre[endi]!=-1)
        {
            res.push_back(nums[pre[endi]]);
            endi=pre[endi];
        }
        return res;
    }
};
int main()
{
    Solution1 solute;
    vector<int> nums={1,2,3,4,5,6,7,8,9};
    vector<int> res=solute.largestDivisibleSubset(nums);
    for_each(res.begin(),res.end(),[](int v){cout<<v<<" ";});
    cout<<endl;
    return 0;
}
