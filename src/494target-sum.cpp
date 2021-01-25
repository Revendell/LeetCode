#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<math.h>
using namespace std;
class Solution {
public:
    int res=0;
    int findTargetSumWays(vector<int>& nums, int S) {
        //基本思想：递归，问题转换为子集求和问题即01背包问题，对nums中的元素添加+或-最后结果等于S，相当于在nums中找到元素和为(sum-S)/2
        //这是因为S+(sum-S)/2-(sum-S)/2=S，S+(sum-S)/2+(sum-S)/2=sum
        //注意：
        //1、因为+0和-0都不影响结果，去除nums中所有的0，并且最后结果*2^zero
        //2、如果sum-S是奇数，说明nums中的元素通过+或-不能得到S返回0
        int zero=0;
        for(int i=0;i<nums.size();i++)
        {
            while(i<nums.size()&&nums[i]==0)
            {
                zero+=1;
                nums.erase(nums.begin()+i);
            }
        }
        int sum=accumulate(nums.begin(),nums.end(),0);
        sum-=S;
        if(sum<0||sum&1)  return res;
        Recursion(nums,sum/2,0);
        return res*pow(2,zero);
    }
    void Recursion(vector<int>& nums, int sum,int pos)
    {
        if(sum<=0)
        {
            if(sum==0) res+=1;
            return;
        }
        for(int i=pos;i<nums.size();i++)
        {
            Recursion(nums,sum-nums[i],i+1);
        }
        return;
    }
};
class Solution1 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        //基本思想：动态规划，问题转换为子集求和问题即01背包问题，对nums中的元素添加+或-最后结果等于S，相当于在nums中找到元素和为(sum-S)/2
        //dp[i]表示填充容量为i的方法个数
        //注意：如果sum-S是奇数，说明nums中的元素通过+或-不能得到S返回0
        int sum=accumulate(nums.begin(),nums.end(),0);
        sum-=S;
        if(sum<0||sum&1)  return 0;
        int w=sum/2;  //背包容量
        vector<int> dp(w+1,0);  //dp[i]表示填充容量为i的方法个数
        dp[0]=1;
        for(auto num:nums)
        {
            for(int j=w;j>=num;j--)
            {
                dp[j]+=dp[j-num];
            }
        }
        return dp[w];
    }
};
int main()
{
    Solution1 solute;
    vector<int> nums={1,1,1,1,1};
    int S=3;
    cout<<solute.findTargetSumWays(nums,S)<<endl;
    return 0;
}
