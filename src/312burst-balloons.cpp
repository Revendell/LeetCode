#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<list>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //简化版：动态规划，正向动态规划，dp[i][j]表示[i,j]范围的最大分数，注意第一重循环必须是j，不断扩大j的范围，并且i必须从j-2不断往前到0，先计算出nums[i]*nums[k]*nums[j]
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0));
        for(int j=2;j<nums.size();j++)
        {
            for(int i=j-2;i>=0;i--)
            {
                for(int k=i+1;k<j;k++)
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j]);
            }
        }
        return dp[0][nums.size()-1];
    }
};
class Solution1 {
public:
    int maxCoins(vector<int>& nums) {
        //基本思想：动态规划，这是一道区间动态规划，用的是分治的思想，大区间用小区间更新，很容易想到dfs+记忆化，这里用自底向上dp推出来的。石子合并和Floyd算法都是一类题。
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        //dp[i][j]表示在开区间(i,j)范围内结果的最大值。dp[i][j]表示i~j最大值，i，j不戳破。
        //以两个数作为左右端点，找出最优解中它们中间那个戳破的气球，中间这个气球把整个队列分为了2部分，
        //要想让中间这个气球和2个端点靠在一起，就需要先把分开的2部分的气球戳破。
        //比如k气球在i,j之间时(i,k,j)被戳破，那么要先戳破i,k、k,j之间的气球，
        //所以dp[i][j]=dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j]
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0));
        for(int i=nums.size()-2;i>=0;i--)
        {
            for(int j=i+2;j<nums.size();j++)
            {
                for(int k=i+1;k<j;k++)
                {
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j]);
                }
            }
        }
        return dp[0][nums.size()-1];
    }
};
int main()
{
    vector<int> nums={3,2,1,2,3,2,1};
    Solution solute;
    cout<<solute.maxCoins(nums)<<endl;
    return 0;
}
