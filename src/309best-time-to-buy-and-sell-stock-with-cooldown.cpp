
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //基本思想：动态规划，dp[i][0 or 1 or 2]表示第i天手上是否持有股票或冷冻期状态下的最大收益
        //dp[i][0]表示第i天手中不持有股票状态下的最大收益
        //dp[i][1]表示第i天手中持有股票状态下的最大收益
        //dp[i][2]表示第i天冷冻期状态下的最大收益
        if(prices.size()<2)  return 0;
        //dp[i][0 or 1 or 2]表示第i天，手上是否持有股票或冷冻期状态下的最大收益
        vector<vector<int>> dp(prices.size(), vector<int>(3, 0));
        //初始化第0天状态值
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        dp[0][2]=0;
        //遍历第1天之后的每天股票情况
        for(int i=1;i<prices.size();i++)
        {
            //第i天手中没有股票下的最大收益等于max(1、前一天没有股票状态下的收益；2、前一天冷冻期状态下的收益)
            dp[i][0] = max(dp[i-1][0], dp[i-1][2]);
            //第i天手中有股票下的最大收益等于max(1、买入股票：前一天的没有股票下的最大收益-今天股票价格；2、无操作：前一天有股票状态下的收益)
            dp[i][1] = max(dp[i-1][0]-prices[i], dp[i-1][1]);
            //第i天冷冻期下的收益等于前一天有股票状态今天卖出股票下的收益，也就是前一天的持有股票下的收益+今天股票价格
            dp[i][2] = dp[i-1][1]+prices[i];
        }
        //最后最大收益一定是手中不持有股票，所以返回最后一天不持有股票状态下和冷冻期状态下中的最大值
        return max(dp[prices.size()-1][0],dp[prices.size()-1][2]);
    }
};
int main()
{
    vector<int> prices={1,2,3,0,2};
    Solution solute;
    cout<<solute.maxProfit(prices)<<endl;
    return 0;
}
