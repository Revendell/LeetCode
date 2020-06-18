#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		//基本思想：广度优先搜索，扫描matrix矩阵中每一个元素
		//如果是1，则向右向下向右下三个方向广度优先搜索，检查三个方向元素是否都为1，这三个方向元素入队列，继续广搜
		int res = 0;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				if (matrix[i][j] == '1')
				{
					int len = 1;
					res = max(res, len);
					deque<pair<int, int>> queue;
					queue.push_front({ i,j });
					while (!queue.empty())
					{
						int queuelen = queue.size();
						while(queuelen)
						{
							pair<int, int> temp = queue.back();
							queue.pop_back();
							if (check(matrix, temp.first, temp.second))
							{
								queue.push_front({ temp.first + 1,temp.second });
								queue.push_front({ temp.first,temp.second + 1 });
								queue.push_front({ temp.first + 1,temp.second + 1 });
							}
							else
								break;
							queuelen--;
						}
						if (queuelen == 0)
						{
							len++;
							res = max(res, len);
						}
						else
							break;		
					}
				}
			}
		}
		return res * res;
	}
	bool check(vector<vector<char>>& matrix, int i, int j)
	{
		if (j + 1 < matrix[0].size() && matrix[i][j + 1] == '1' && i + 1 < matrix.size() && matrix[i + 1][j] == '1'&& matrix[i + 1][j+1] == '1')
			return true;
		return false;
	}
};
class Solution1 {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		//基本思想：动态规划，dp[i][j]表示如果当前位置加入组成的正方形的边长
		//如果该位置的值是1，则dp(i,j) 的值由其上方、左方和左上方的三个相邻位置的dp值决定。
		//当前位置的元素值等于三个相邻位置的元素中的最小值加1，状态转移方程如下：
		//dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
		if (matrix.size() == 0)
			return 0;
		int res = 0;
		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				if (matrix[i][j] == '1')
				{
					if (i == 0 || j == 0)
						dp[i][j] = 1;
					else
					    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
					res = max(res, dp[i][j]);
				}
			}
		}
		return res * res;
	}
};
int main()
{
	Solution solute;
	vector<vector<char>> matrix = {
		{'0', '0', '0', '1'},
		{'1', '1', '0', '1'},
		{'1', '1', '1', '1'},
		{'0', '1', '1', '1'},
		{'0', '1', '1', '1'}
	};
	cout << solute.maximalSquare(matrix) << endl;
	return 0;
}