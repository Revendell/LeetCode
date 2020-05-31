#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int i, j, n, m;
		n = grid.size();
		m = grid[0].size();
		//基本思想：动态规划法，在原数组上grid作为dp数组，这样就不需要额外的存储空间，grid[i][j]存储从[0,0]到当前坐标[i,j]最短的距离，grid[i][j]=grid[i][j]+min(grid[i-1][j],grid[i][j-1])
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (i == 0 && j != 0)
					grid[0][j] += grid[0][j - 1];
				else if (j == 0 && i != 0)
					grid[i][0] += grid[i - 1][0];
				else if (i != 0 && j != 0)
					grid[i][j] = grid[i][j] + min(grid[i - 1][j], grid[i][j - 1]);
			}
		}
		return grid[n - 1][m - 1];
	}
};
int main()
{
	Solution solute;
	vector<vector<int>> grid = {
		{1,3,1} ,
		{1,5,1} ,
		{4,2,1}
	};
	cout << solute.minPathSum(grid) << endl;
	return 0;
}