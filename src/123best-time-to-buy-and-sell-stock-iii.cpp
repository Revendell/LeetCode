#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//基本思想：动态规划法
		if (prices.size() == 0)
			return 0;
		//K为股票最多交易次数
		int K = 2;
		//dp[i][k][0 or 1]表示第i+1天，已经交易次数k，手上是否持有股票状态下的最大收益
		//已经交易次数是完整一次买入并卖出股票的次数，当买入股票还没有卖出股票不算一次交易
		vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(K + 1, vector<int>(2, 0)));
		//初始化第1天的六种状态收益值，第1天可以选择买入股票或者无操作
		dp[0][0][0] = 0;    //第1天，已经交易次数0，手上沒有股票，则第1天无操作收益为0
		dp[0][0][1] = -prices[0];    //第1天，已经交易次数0，手上持有股票，则买入了第1天的股票收益为-prices[0]
		dp[0][1][0] = -999999;    //第1天，已经交易次数1，手上沒有股票，不存在状态
		dp[0][1][1] = -999999;    //第1天，已经交易次数1，手上持有股票，不存在状态
		dp[0][2][0] = -999999;    //第1天，已经交易次数2，手上没有股票，不存在状态
		dp[0][2][1] = -999999;    //第1天，已经交易次数2，手上持有股票，不存在状态
		//遍历第1天之后的每天股票情况
		for (int i = 1; i < prices.size(); i++)
		{
			//计算每一天六种状态下的最大收益，k=0、1、2
			for (int k = 0; k <= K; k++)
			{
				//k=0时，dp[i][0][0]状态不可能由其他状态得到，所以有个判断
				if(k != 0)
				    //第i天，已经交易次数k，手中没有股票下的最大收益等于max(1、无操作：前一天此状态下的收益；2、卖出股票：前一天的持有股票下的最大收益+今天股票价格，因为卖出股票交易数k+1)
				    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k - 1][1] + prices[i]);
				//第i天，已经交易次数k，手中持有股票状态下的最大收益等于max(1、无操作：前一天此状态下的收益；2、买入股票：前一天的没有股票下的最大收益 - 今天股票价格，因为买入股票还没有卖出交易数不变)
				dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k][0] - prices[i]);
			}
		}
		//返回最后一天没有股票状态下交易0次、1次、2次中最大的收益值
		return max(dp[prices.size() - 1][2][0], max(dp[prices.size() - 1][1][0], dp[prices.size() - 1][0][0]));
	}
};
int main()
{
	Solution solute;
	vector<int> prices = { 1,2,3,4,2,3,4,5,1,2,3,4 };
	cout << solute.maxProfit(prices) << endl;
	return 0;
}