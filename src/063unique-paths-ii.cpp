#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		//基本思想：动态规划，利用已求的信息计算未求的信息，如果第n行m列没有路障第n行m列的路径等于第n-1行m列+第n行m-1列路径之和，如果有路障第n行m列的路径等于0。
		int i, j, n, m;
		n = obstacleGrid.size();
		m = obstacleGrid[0].size();
		//本来打算利用obstacleGrid作为DP数组，可以不需要额外的空间，但是计算中间dp[i][j]时候可能超过int
		//尽管后面可能有路障使得最后返回值在int范围，但中间计算时可能会超过int范围
		vector<vector<long long>> dp(n, vector<long long>(m, 1));
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				//如果第n行m列有路障第n行m列的路径等于0
				if (obstacleGrid[i][j] == 1)
					dp[i][j] = 0;
				//如果第n行m列没有路障第n行m列的路径等于第n-1行m列+第n行m-1列路径之和
				else
				{
					//考虑上边界路径
					if (i == 0 && j != 0)
						dp[i][j] = dp[i][j - 1];
					//考虑左边界路径
					else if (j == 0 && i != 0)
						dp[i][j] = dp[i - 1][j];
					//其他路径下
					else if (i != 0 && j != 0)
						dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

				}
			}
		}
		return dp[n - 1][m - 1];
	}
};
int main()
{
	Solution solute;
	vector<vector<int>> obstacleGrid = {
		{0,0,0},
		{0,1,0},
		{0,0,0}
	};
	cout << solute.uniquePathsWithObstacles(obstacleGrid) << endl;
	return 0;
}