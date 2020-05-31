#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int res = 0;
	int uniquePaths(int m, int n) {
		//����˼�룺�ݹ���ݷ�����ʱ
		Recursion(0, 0, m, n);
		return res;
	}
	void Recursion(int row, int col, int m, int n)
	{
		if (row == n - 1 && col == m - 1)
		{
			res++;
			return;
		}
		if (row + 1 < n)
			Recursion(row + 1, col, m, n);
		if (col + 1 < m)
			Recursion(row, col + 1, m, n);
		return;
	}
};
class Solution1 {
public:
	int uniquePaths(int m, int n) {
		int i, j;
		//����˼�룺��̬�滮�������������Ϣ����δ�����Ϣ�����n��m�е�·�������ڵ�n-1��m��+��n��m-1��·��֮��
		vector<vector<int>> dp(n, vector<int>(m, 1));
		for (i = 1; i < n; i++)
		{
			for (j = 1; j < m; j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[n-1][m-1];
	}
};
int main()
{
	Solution1 solute;
	int m = 7, n = 3;
	cout << solute.uniquePaths(m, n) << endl;
	return 0;
}