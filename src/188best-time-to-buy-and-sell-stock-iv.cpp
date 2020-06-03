#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		//基本思想：贪心+动态规划
		if (prices.size() == 0)
			return 0;
		int res = 0;
		//当允许交易的次数大于交易天数时，相当于是可以无限交易，使用贪心算法
		//否则当k过大，dp分配不了那么多内存空间
		if (k > prices.size()/2)
		{
			for (int i = 1; i < prices.size(); i++)
			{
				if (prices[i] > prices[i - 1])
					res += prices[i] - prices[i - 1];
			}
			return res;
		}
		//dp[i][k][0 or 1]表示第i天，已经交易次数k，手上是否持有股票状态下的最大收益
		vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(k + 1, vector<int>(2, 0)));
		//初始状态设置
		dp[0][0][0] = 0;
		dp[0][0][1] = -prices[0];
		for (int i = 1; i < k + 1; i++)
		{
			dp[0][i][0] = -999999;
			dp[0][i][1] = -999999;
		}
		//遍历第1天之后的每天股票情况，计算每一天的2*(k+1)种状态下的最大收益
		for (int i = 1; i < prices.size(); i++)
		{
			for (int j = 0; j < k + 1; j++)
			{
				//第i天，已经交易次数j，手中没有股票下的最大收益等于max(1、无操作：前一天此状态下的收益；2、卖出股票：前一天的持有股票下的最大收益+今天股票价格，因为卖出股票交易数j+1)
				if (j != 0)
					dp[i][j][0] = max(dp[i - 1][j - 1][1] + prices[i], dp[i - 1][j][0]);
				//第i天，已经交易次数j，手中持有股票状态下的最大收益等于max(1、无操作：前一天此状态下的收益；2、买入股票：前一天的没有股票下的最大收益 - 今天股票价格，因为买入股票还没有卖出交易数不变)
				dp[i][j][1] = max(dp[i - 1][j][0] - prices[i], dp[i - 1][j][1]);
			}
		}
		//最后最大收益一定是手中不持有股票，所以返回最后一天不持有股票的k+1种状态下的最大收益
		for (int i = 0; i < k + 1; i++)
			res = max(res, dp[prices.size() - 1][i][0]);
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> prices = { 3,2,6,5,0,3 };
	int k = 2;
	cout << solute.maxProfit(k, prices) << endl;
	return 0;
}