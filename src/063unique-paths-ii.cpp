#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		//����˼�룺��̬�滮�������������Ϣ����δ�����Ϣ�������n��m��û��·�ϵ�n��m�е�·�����ڵ�n-1��m��+��n��m-1��·��֮�ͣ������·�ϵ�n��m�е�·������0��
		int i, j, n, m;
		n = obstacleGrid.size();
		m = obstacleGrid[0].size();
		//������������obstacleGrid��ΪDP���飬���Բ���Ҫ����Ŀռ䣬���Ǽ����м�dp[i][j]ʱ����ܳ���int
		//���ܺ��������·��ʹ����󷵻�ֵ��int��Χ�����м����ʱ���ܻᳬ��int��Χ
		vector<vector<long long>> dp(n, vector<long long>(m, 1));
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				//�����n��m����·�ϵ�n��m�е�·������0
				if (obstacleGrid[i][j] == 1)
					dp[i][j] = 0;
				//�����n��m��û��·�ϵ�n��m�е�·�����ڵ�n-1��m��+��n��m-1��·��֮��
				else
				{
					//�����ϱ߽�·��
					if (i == 0 && j != 0)
						dp[i][j] = dp[i][j - 1];
					//������߽�·��
					else if (j == 0 && i != 0)
						dp[i][j] = dp[i - 1][j];
					//����·����
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