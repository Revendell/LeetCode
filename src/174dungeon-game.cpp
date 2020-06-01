#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		//基本思想：逆向动态规划，dp[i][j]表示从第i行第j列位置开始到右下角所需的最小能量值
		//这道题目首先想到的应该就是动态规划，但是正向动态规划发现当前位置所需的最小能量值取决于后面的房间值
		//比如当前剩余能量33，最小能量值-7，而右边房间剩余能量值-6，最小能量值-6，按理说从左边到右边房间不需要更新最小能力值
		//因为-7小于-6所需的最小能量值大，但是如果最后一个房间值是-9，那么最终的最小能量值是-15
		//如果更新最小能力值，那么最终的最小能量值是-7
		//所以我想到的是贪心+动态规划，既保存剩余能力值最大的路径以及所需最小能量值最小的路径，但其实还是不合理
		//这个时候应该想到既然当前所需最小能力值取决于后面的，可以使用逆向动态规划，从终点往起点更新动态方程
		int row, col;
		row = dungeon.size();
		col = dungeon[0].size();
		vector<vector<int>> dp(row, vector<int>(col, 0));
		dp[row - 1][col - 1] = dungeon[row - 1][col - 1] > 0 ? 1 : 1 - dungeon[row - 1][col - 1];
		for (int i = row - 2; i >= 0; i--)
		{
			dp[i][col - 1] = max(dp[i + 1][col - 1] - dungeon[i][col - 1], 1);
		}
		for (int j = dungeon[0].size() - 2; j >= 0; j--)
		{
			dp[row - 1][j] = max(dp[row - 1][j + 1] - dungeon[row - 1][j], 1);
		}
		for (int i = row- 2; i >= 0; i--)
		{
			for (int j = col - 2; j >= 0; j--)
			{
				int down = max(dp[i + 1][j] - dungeon[i][j], 1);
				int right = max(dp[i][j + 1] - dungeon[i][j], 1);
				dp[i][j] = min(down, right);
			}
		}
		return dp[0][0];
	}
};
class Solution1 {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		//基本思想：正向动态规划，只通过了42个测试用例
		vector<vector<vector<int>>> dp(dungeon.size() + 1, vector<vector<int>>(dungeon[0].size() + 1, vector<int>(4, 0)));
		for (int i = 0; i <= dungeon.size(); i++)
		{
			dp[i][0][0] = -999999;
			dp[i][0][1] = 999999;
			dp[i][0][2] = -999999;
			dp[i][0][3] = 999999;
		}
		for (int j = 0; j <= dungeon[0].size(); j++)
		{
			dp[0][j][0] = -999999;
			dp[0][j][1] = 999999;
			dp[0][j][2] = -999999;
			dp[0][j][3] = 999999;
		}
		for (int i = 0; i < dungeon.size(); i++)
		{
			for (int j = 0; j < dungeon[i].size(); j++)
			{
				if (i == 0 && j == 0)
				{
					dp[i + 1][j + 1][0] = dungeon[i][j];
					dp[i + 1][j + 1][1] = min(0,dungeon[i][j]);
					dp[i + 1][j + 1][2] = dungeon[i][j];
					dp[i + 1][j + 1][3] = min(0,dungeon[i][j]);
				}
				else
				{
					int left_rest, up_rest, left_min, up_min;
					left_rest = dp[i + 1][j][0] + dungeon[i][j];
					up_rest = dp[i][j + 1][0] + dungeon[i][j];
					left_min = min(left_rest, dp[i + 1][j][1]);
					up_min = min(up_rest, dp[i][j + 1][1]);
					if (up_min > left_min)
					{
						dp[i + 1][j + 1][0] = up_rest;
						dp[i + 1][j + 1][1] = up_min;
					}
					else
					{
						dp[i + 1][j + 1][0] = left_rest;
						dp[i + 1][j + 1][1] = left_min;
					}
					left_rest = dp[i + 1][j][2] + dungeon[i][j];
					up_rest = dp[i][j + 1][2] + dungeon[i][j];
					left_min = min(left_rest, dp[i + 1][j][3]);
					up_min = min(up_rest, dp[i][j + 1][3]);
					if (up_rest > left_rest)
					{
						dp[i + 1][j + 1][2] = up_rest;
						dp[i + 1][j + 1][3] = up_min;
					}
					else
					{
						dp[i + 1][j + 1][2] = left_rest;
						dp[i + 1][j + 1][3] = left_min;
					}
				}	
			}
		}
		if (dp[dungeon.size()][dungeon[0].size()][1] >= 0 || dp[dungeon.size()][dungeon[0].size()][3] >= 0)
			return 1;
		else
			return 1 - max(dp[dungeon.size()][dungeon[0].size()][1], dp[dungeon.size()][dungeon[0].size()][3]);
	}
};
int main()
{
	Solution solute;
	vector<vector<int>> dungeon = {
		{-2,-3,3 }, { -5,-10,1 }, { 10,30,-5 }, { -7,-8,1 }
	};
	cout << solute.calculateMinimumHP(dungeon) << endl;
	return 0;
}