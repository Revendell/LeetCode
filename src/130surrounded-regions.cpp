#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int flag = 0;  //标记连通的O是否被X包围，0是包围，1是没有包围(当连通的O存在边界上时flag=1)
	vector<vector<int>> pos;  //记录连通的O的位置，如果flag=0将这些位置的O置位X
	void solve(vector<vector<char>>& board) {
		//简化版：深度优先搜索
		vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				if (board[i][j] == 'O' && !visited[i][j])
				{
					Recursion(board, i, j, visited);
					if (flag == 0)
					{
						for(auto v:pos)
							board[v[0]][v[1]] = 'X';
					}
					flag = 0;
					pos.clear();
				}
			}
		}
	}
	void Recursion(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited)
	{
		if(i<0||i>=board.size()||j<0||j>=board[i].size())
			return;
		if(board[i][j] != 'O' || visited[i][j])
			return;
		pos.push_back({ i,j });
		visited[i][j] = true;
		if (i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1)
			flag = 1;
		Recursion(board, i - 1, j, visited);
		Recursion(board, i + 1, j, visited);
		Recursion(board, i, j - 1, visited);
		Recursion(board, i, j + 1, visited);
	}
};
class Solution1 {
public:
	int flag = 0;  //标记连通的O是否被X包围，0是包围，1是没有包围(当连通的O存在边界上时flag=1)
	vector<vector<int>> pos;  //记录连通的O的位置，如果flag=0将这些位置的O置位X
	void solve(vector<vector<char>>& board) {
		//基本思想：dfs，遍历非边界所有的O，然后dfs判断查找连通的O是否存在位于边界的O，存在的话flag=1
		if (board.size() == 0)
			return;
		//记录O是否被访问过
		vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
		//遍历非边界所有的O
		for (int i = 1; i < board.size() - 1; i++)
		{
			for (int j = 1; j < board[i].size() - 1; j++)
			{
				if (board[i][j] == 'O' && !visited[i][j])
				{
					Recursion(board, i, j, visited);
					//flag=0，pos里记录的连通的O被X包围，置为X
					if (flag == 0)
					{
						for (int k = 0; k < pos.size(); k++)
						{
							board[pos[k][0]][pos[k][1]] = 'X';
						}
					}
					flag = 0;
					pos.clear();
				}
			}
		}
	}
	void Recursion(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited)
	{
		pos.push_back({ i,j });
		visited[i][j] = true;
		//当连通的O存在边界上时，flag=1
		if (i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1)
		{
			flag = 1;
		}
		if (i - 1 >= 0 && board[i - 1][j] == 'O' && !visited[i - 1][j])
			Recursion(board, i - 1, j, visited);
		if (i + 1 < board.size() && board[i + 1][j] == 'O' && !visited[i + 1][j])
			Recursion(board, i + 1, j, visited);
		if (j - 1 >= 0 && board[i][j - 1] == 'O' && !visited[i][j - 1])
			Recursion(board, i, j - 1, visited);
		if (j + 1 < board[i].size() && board[i][j + 1] == 'O' && !visited[i][j + 1])
			Recursion(board, i, j + 1, visited);
	}
};
int main()
{
	Solution solute;
	vector<vector<char>> board = {
		{'O', 'O', 'O' },
		{'O', 'O', 'O' },
		{'O', 'O', 'O' }
	};
	solute.solve(board);
	for (int i = 0; i < board.size(); i++)
	{
		for_each(board[i].begin(), board[i].end(), [](const char c) {cout << c << " "; });
		cout << endl;
	}
	return 0;
}