
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		if (board.size() == 0)  return;
		vector<int> row = { 0,1,-1 };
		vector<int> col = { 0,1,-1 };
		int n = board.size();
		int m = board[0].size();
		//遍历每个位置的细胞，并更新状态
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int livecells = 0;
				//计算当前位置细胞周围8个位置的活细胞个数
				for (int k1 = 0; k1 < 3; k1++)
				{
					for (int k2 = 0; k2 < 3; k2++)
					{
						if (k1 == 0 && k2 == 0)
							continue;
						//每个细胞&1得到的是当前状态
						if (i + row[k1] >= 0 && i + row[k1] < n && j + col[k2] >= 0 && j + col[k2] < m)
							livecells += board[i + row[k1]][j + col[k2]] & 1;
					}
				}
				//根据活细胞个数更新当前位置细胞状态
				if (board[i][j] == 0)
					board[i][j] = livecells == 3 ? 2 : 0;
				else
					board[i][j] = livecells >= 2 && livecells <= 3 ? 3 : 1;
			}
		}
		//每个细胞右移1位得到的是下一个状态
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				board[i][j] >>= 1;
	}
};
int main()
{
	Solution solute;
	vector<vector<int>> board = {
		{0,1,0},
		{0,0,1},
		{1,1,1},
		{0,0,0}
	};
	solute.gameOfLife(board);
	for (int i = 0; i < board.size(); i++)
	{
		for_each(board[i].begin(), board[i].end(), [](const int v) {cout << v << " "; });
		cout << endl;
	}
	return 0;
}
