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
		//����˼�룺��̬�滮������ԭ������grid��Ϊdp���飬�����Ͳ���Ҫ����Ĵ洢�ռ䣬grid[i][j]�洢��[0,0]����ǰ����[i,j]��̵ľ��룬grid[i][j]=grid[i][j]+min(grid[i-1][j],grid[i][j-1])
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