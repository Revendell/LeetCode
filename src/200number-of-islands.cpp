#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		//����˼�룺�����������
		int res = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == '1')
				{
					res++;
					dfs(grid, i, j);
				}
			}
		}
		return res;
	}
	void dfs(vector<vector<char>>& grid, int i, int j)
	{
		if(i<0||i>=grid.size()||j<0||j>=grid[0].size())
			return;
		if(grid[i][j]=='0')
			return;
		grid[i][j] = '0';
		dfs(grid, i, j - 1);
		dfs(grid, i, j + 1);
		dfs(grid, i - 1, j);
		dfs(grid, i + 1, j);
	}
};
class Solution1 {
public:
	int numIslands(vector<vector<char>>& grid) {
		//����˼�룺�������������ע��㣺һ����1��תΪ0������������ͬһ���������кü��Σ��ظ����ܶ��
		deque<vector<int>> queue;
		int res = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == '1')
				{
					res++;
					queue.push_front({ i,j });
					grid[i][j] = '0';
					while (!queue.empty())
					{
						vector<int> cur = queue.back();
						queue.pop_back();
						int r = cur.front(), c = cur.back();
						if (r - 1 >= 0 && grid[r - 1][c] == '1')
						{
							queue.push_front({ r - 1,c });
							grid[r - 1][c] = '0';
						}	
						if (r + 1 < grid.size() && grid[r + 1][c] == '1')
						{	
							queue.push_front({ r + 1,c });
							grid[r + 1][c] = '0';
						}
						if (c - 1 >= 0 && grid[r][c - 1] == '1')
						{
							queue.push_front({ r,c - 1 });
							grid[r][c - 1] = '0';
						}
						if (c + 1 < grid[0].size() && grid[r][c + 1] == '1')
						{
							queue.push_front({ r,c + 1 });
							grid[r][c + 1] = '0';
						}	
					}
				}
			}
		}
		return res;
	}
};
int main()
{
	Solution1 solute;
	vector<vector<char>> grid = {
		{'1','1','0','0','0'},
		{'1','1','0','0','0'},
		{'0','0','1','0','0'},
		{'0','0','0','1','1'}
	};
	cout << solute.numIslands(grid) << endl;
	return 0;
}