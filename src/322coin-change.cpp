
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //基本思想：动态规划，dp[i]表示总金额为i时最少硬币数，从1到amount遍历每一个总金额下的硬币数
        //动态方程dp[i]=min(dp[i],dp[i-coins[j]]+1)
        //这道题本质和70爬楼梯类似，爬楼梯每次能爬1个或2个楼梯，问爬n阶楼梯多少种方法dp[i]=dp[i-1]+dp[i-2]，如果问爬n阶楼梯最少的步数就是dp[i]=min(dp[i-1]+1,dp[i-2]+1)
        //这道题变成了每次爬的阶梯数为coins[0:n-1]，问爬到amount阶需要的最少步数。dp[i]=min(dp[i],dp[i-coins[j]]+1)
        //dp初始化为-1表示硬币拼凑不出当前金额
        vector<int> dp(amount+1,-1);
        dp[0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(i-coins[j]>=0&&dp[i-coins[j]]!=-1)
                    dp[i]=dp[i]==-1?dp[i-coins[j]]+1:min(dp[i],dp[i-coins[j]]+1);
            }
        }
        return dp[amount];
    }
};
int main()
{
    Solution solute;
    vector<int> coins={1,2,5};
    int amount=11;
    cout<<solute.coinChange(coins,amount)<<endl;
    return 0;
}
