#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		//基本思想：深度优先搜索
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
		//基本思想：广度优先搜索
		deque<pair<int,int>> queue;
		int res = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == '1')
				{
					res++;
					queue.push_front({ i,j });
					while (!queue.empty())
					{
						pair<int,int> cur = queue.back();
						queue.pop_back();
						int r = cur.first, c = cur.second;
						if(r<0||r>=grid.size()||c<0||c>=grid[0].size())
							continue;
						if(grid[r][c] == '0')
							continue;
						grid[r][c]='0';
						queue.push_front({ r - 1,c });
						queue.push_front({ r + 1,c });
						queue.push_front({ r,c - 1 });
						queue.push_front({ r,c + 1 });
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